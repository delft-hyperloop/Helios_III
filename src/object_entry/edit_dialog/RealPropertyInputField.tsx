import { InputAdornment, TextField } from "@mui/material";
import { useState } from "react";


function parseInputToNumber(input: string): number | null {
  let regex = /^-?\d*[.]?\d*$/;
  if (!regex.test(input)) {
    return null;
  }
  return Number(input);
}

function checkInputForErrors(min: number, max: number, input: string): string | null {
  let inputAsNumber = Number(input);
  if (isNaN(inputAsNumber)) {
    return "Input has to be a number!";
  }
  if (inputAsNumber < min) {
    return `Input has to be greater than ${min}!`;
  }
  if (inputAsNumber > max) {
    return `Input has to be less than ${max}!`;
  }
  return null;
}


interface RealPropertyInputFieldProps {
  min: number,
  max: number,
  bitSize: number,
  currentValue?: number,
  onUpdate: (value: number | null | undefined) => void,
  unit?: string,
  name: string,
  width?: string,
}

function RealPropertyInputField({ min, max, onUpdate, currentValue, name, unit, bitSize, width = "75ch" }: Readonly<RealPropertyInputFieldProps>) {
  const [input, setInput] = useState<string>("");
  const [errorMsg, setErrorMsg] = useState<string | null>(null);
  const [hasValue, setHasValue] = useState<boolean>(false);

  let unitAdornment: string;
  if (unit) {
    unitAdornment = `[${unit}]`;
  } else {
    unitAdornment = "";
  }
  let adornment: string;
  if (hasValue) {
    adornment = `${name} ${unitAdornment} <=`;
  } else {
    adornment = `${name} ${unitAdornment}   `;
  }

  return <TextField
    sx={{ width: width, boxShadow: 0, borderRadius: 0 }}
    id={`${name}-set-request-input-field`}
    variant="filled"
    label={errorMsg ?? `d${bitSize}<${min}..${max}>`}
    value={input}
    color={errorMsg ? "error" : "info"}
    placeholder={`<= ${currentValue}`}
    inputProps={{
      style: { boxShadow: "none" }
    }}
    onChange={(event) => {
      const input = event.target.value;
      // NOTE special case for the empty string
      if (input.length === 0) {
        setInput(input);
        onUpdate(undefined);
        setHasValue(false);
        return;
      }
      if (input == "-") {
        setInput(input);
        setHasValue(true);
        setErrorMsg("Not a valid number");
        return;
      }

      const number = parseInputToNumber(input);
      if (number !== null) {
        // NOTE input is a number!
        const error = checkInputForErrors(min, max, input);
        if (error) {
          setErrorMsg(error);
          onUpdate(null); // notify parent about invalid value!
        } else {
          setErrorMsg(null);
          onUpdate(number); // notify parent about new value!
        }
        setHasValue(true);
        setInput(input);
      } else {
        // NOTE input is not a number, don't update the text!
      }
    }}
    InputProps={{
      startAdornment: <InputAdornment position="start">{adornment}</InputAdornment>,
    }}
  >
  </TextField>;
}

export default RealPropertyInputField;
