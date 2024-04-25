# Ground station

This folder includes the codebase for the front-end GUI and the ground station backend.
The GUI uses [Tauri](https://tauri.app/): a Rust framework for creating native applications.
Tauri is coupled with [SvelteKit](https://kit.svelte.dev/) here: a JavaScript framework for web applications.
Tauri builds its application using the front-end from SvelteKit and creates a native executable.

## Sub-folder structure:

- `station/` - contains Tauri backend and ground station backend
- `src/` - contains the SvelteKit front-end of the GUI. Check out its readme for more documentation.
- `tests/` - contains software tests for the front-end/back-end
- `static/` - contains static files like images, icons, fonts.
