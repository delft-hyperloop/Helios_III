import type { CommandInvocation } from "@delft-hyperloop/serpenta";
import { invoke } from "@tauri-apps/api/tauri";

export class CommandInvoker implements CommandInvocation {
    invokeCommand<T>(commandName: string, args: Record<string, unknown>): Promise<T> {
        return invoke<T>(commandName, args);
    }
}