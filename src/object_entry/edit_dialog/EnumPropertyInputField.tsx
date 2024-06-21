import { InputAdornment, MenuItem, TextField } from "@mui/material";
import { useState } from "react";


interface EnumPropertyInputFieldProps {
  variants: string[],
  currentValue: string,
  onUpdate: (value: string) => void,
  name: string,
}


function EnumPropertyInputField({ variants, onUpdate, currentValue, name }: Readonly<EnumPropertyInputFieldProps>) {
  const [value, setValue] = useState<string | undefined>(undefined);
  return (
    <TextField
      sx={{ width: "50ch", boxShadow: 0 }}
      id="outlined-select-value"
      variant="filled"
      select={true}
      defaultValue=""
      label={`Current : ${currentValue}`}
      onChange={(event) => {
        onUpdate(event.target.value);
        setValue(event.target.value);
      }}
      InputProps={{
        startAdornment: <InputAdornment position="start">{value ? `${name} <=`: name}</InputAdornment>,
      }}
    >
      {variants.map((option) => (
        <MenuItem key={option} value={option}>
          {option}
        </MenuItem>
      ))}
    </TextField>
  )
}

export default EnumPropertyInputField;
