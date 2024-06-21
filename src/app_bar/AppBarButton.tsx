import Button from "@mui/material/Button";
import { ReactElement } from "react";
import theme from "../theme.ts";


interface AppBarButtonProps {
  children: ReactElement,
  onClick: () => void,
  color: "cmdStart" | "cmdStop" | "cmdAbort" | "cmdExtra"
  width?: number | string
  variant?: "outlined" | "contained" | "text",
  disabled?: boolean,
}

function AppBarButton({
  children,
  onClick,
  color,
  width = "15em",
  variant = "contained",
  disabled = false,
}: Readonly<AppBarButtonProps>) {
  return (
    <Button
      variant={variant}
      size="small"
      disabled={disabled}
      style={{
        maxWidth: width,
        minWidth: width,
        fontSize: "0.5em",
        maxHeight: '57px',
        minHeight: '57px',
      }}
      sx={{
        ":disabled": {
          backgroundColor: theme.palette.background.disabled
        }

      }}
      color={color}
      onClick={onClick}
    >
      {children}
    </Button>
  );
}

export default AppBarButton;
