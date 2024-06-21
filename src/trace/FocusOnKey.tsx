import { useEffect } from "react";



export default function useFocusOnCtrlShortcut(key : string, ref : any) {
  useEffect(() => {
    function onKeyPressed(event : KeyboardEvent) {
      if (event.key == key && event.ctrlKey) {
        event.preventDefault();
        ref.current.focus();
      }
    }
    document.addEventListener("keydown", onKeyPressed);
    return () => document.removeEventListener("keydown", onKeyPressed);
  }, [key]);
}
