#!/bin/bash

# This script is used to populate the datatypes type using the /config/datatypes.toml file
# The result of this will be put in /gs/src/lib/types.ts in the beginning of the file

echo 'Populating datatypes...'

# Get the commands from the commands.toml file
datatypes=$(grep -oP '(?<=name = ").*(?=")' ../config/datatypes.toml)

# # Convert to snake case
# commands=$(echo "$commands" | sed -r 's/([a-z0-9])([A-Z])/\1_\L\2/g' | tr '[:upper:]' '[:lower:]')

# Add quotes around each datatype name
datatypes=$(echo "$datatypes" | sed -r 's/(.*)/"\1"/')

# Format into TS union
datatypes=$(echo "$datatypes" | sed -r ':a;N;$!ba;s/\n/ | /g')

# Delete the line after the AUTO GENERATED USING npm run generate:datatypes comment
sed -i '/AUTO GENERATED USING npm run generate:datatypes/{n;d}' ./src/lib/types.ts

# Add the new NamedDatatype type definition
sed -i "/AUTO GENERATED USING npm run generate:datatypes/a\export type NamedDatatype = $datatypes" ./src/lib/types.ts

echo $datatypes
