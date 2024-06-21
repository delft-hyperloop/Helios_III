## Prerequisites
##### Install npm
Just follow the instructios on the 
[npm website](https://docs.npmjs.com/downloading-and-installing-node-js-and-npm)
for your platform
##### Tauri prerequisites
Just follow the instructions on the 
[tauri website](https://tauri.app/v1/guides/getting-started/prerequisites)
for your platform
##### Download the project
Use a Github Client or from the cli run
```
$ git clone https://github.com/mu-zero-HYPERLOOP/control-panel
```

##### Install npm dependencies
```
$ cd control-panel
$ npm install
```
This will install all npm dependencies and take a while

##### Run the application in developer mode
```
$ npm run tauri dev
```
This takes a while (not more than 3 min), afterwards the control-panel
application, should open in developer mode (less performant than release
but supports hot reloading, devtools etc.)

## Build release version
Just run
```
$ npm run tauri build
```
Afterwards the executable app bundle can be found somewhere 
in ```src-tauri/target/release/bundle/``` depending on your platform




