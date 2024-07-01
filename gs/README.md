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

## How to run the ground station GUI:

Running the GUI requires some dependencies to be installed and configured. 
To aprehend this issue, we provide a nix shell script that will run an environment with all the dependencies that are needed.
If you opt out of using Nix, you can follow the guide that's further below. 

Clone the repository
```bash
git clone git@github.com:delft-hyperloop/Helios_III.git
```

### Using the declarative Nix package manager.

If you haven't already, download and setup the Nix package manager from [here](https://nixos.org/download/).

1. Enter the root of the gs project and either:
	- run `nix-shell shell.nix` which will run a shell with all of the dependencies installed
	- run `direnv allow` (only the first time you do this) which will setup all the dependencies anytime you run anything from this folder or its children folders
2. Run the GUI
```bash
npm run tauri dev
```



### For people not using Nix

Ensure you have Rust, Tauri and Node.js installed. 
If not, follow the instructions [here](https://tauri.studio/en/docs/getting-started/installation).


1. Install dependencies
```bash
cd Helios_III/gs
npm install
```

2. Run the GUI
```bash
npm run tauri dev
```
