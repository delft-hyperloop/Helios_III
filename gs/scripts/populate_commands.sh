#!/bin/bash

# This script is used to populate the commands type using the /config/commands.toml file
# The result of this will be put in /gs/src/lib/types.ts in the beginning of the file

echo 'Populating commands...'

# Get the commands from the commands.toml file
commands=$(grep -oP '(?<=name = ").*(?=")' ../config/commands.toml)

# # Convert to snake case
# commands=$(echo "$commands" | sed -r 's/([a-z0-9])([A-Z])/\1_\L\2/g' | tr '[:upper:]' '[:lower:]')

# Add quotes around each command name
commands=$(echo "$commands" | sed -r 's/(.*)/"\1"/')

# Format into TS union
commands=$(echo "$commands" | sed -r ':a;N;$!ba;s/\n/ | /g')

# Delete the line after the AUTO GENERATED USING npm run generate:commands comment
sed -i '/AUTO GENERATED USING npm run generate:commands/{n;d}' ./src/lib/types.ts

# Add the new NamedCommand type definition
sed -i "/AUTO GENERATED USING npm run generate:commands/a\export type NamedCommand = $commands" ./src/lib/types.ts

echo $commands
