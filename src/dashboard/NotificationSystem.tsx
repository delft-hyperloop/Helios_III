import {closeSnackbar, useSnackbar} from "notistack";
import {useEffect} from "react";
import {listen} from "@tauri-apps/api/event";

interface Notification {
    level : "info" | "debug" | "warning" | "error",
    title: string,
    message : string,
}

const action = (snackbarId: any) => (
    <button onClick={() => {
        closeSnackbar(snackbarId)
    }}>
        Dismiss
    </button>
);

function NotificationSystem() {
    const {enqueueSnackbar} = useSnackbar()
    const delimiter: string = ": "

    useEffect(() => {
        let unsubscribe = listen<Notification>("notification", (event) => {
            let notification = event.payload
            let message = notification.title + delimiter + notification.message

            switch (notification.level) {
                case "info" : {
                    enqueueSnackbar(message, {
                        autoHideDuration: 1000,
                        preventDuplicate: true,
                        variant: "info"
                    })
                    break
                }
                case "debug": {
                    enqueueSnackbar(message, {
                        autoHideDuration: 500,
                        preventDuplicate: true,
                        variant: "default"
                    })
                    break
                }
                case "warning": {
                    enqueueSnackbar(message, {
                        autoHideDuration: 2000,
                        preventDuplicate: true,
                        variant: "warning"
                    })
                    break
                }
                case "error": {
                    enqueueSnackbar(message, {
                        action,
                        persist: true,
                        preventDuplicate: true,
                        variant: "error"
                    })
                    break
                }
            }
        });

        return () => {
            unsubscribe.then(f => f());
        };
    }, []);

    return (<></>)
}

export default NotificationSystem
