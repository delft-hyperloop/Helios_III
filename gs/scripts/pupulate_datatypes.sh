#!/bin/sh

echo 'Populating datatypes...'

# Get the commands from the commands.toml file
datatypes=$(grep -oP '(?<=name = ").*(?=")' ../config/datatypes.toml)

# Add quotes around each datatype name
datatypes=$(echo "$datatypes" | sed -r 's/(.*)/"\1"/')

# Format into TS union
datatypes=$(echo "$datatypes" | sed -r ':a;N;$!ba;s/\n/ | /g')

# Delete the line after the AUTO GENERATED USING npm run generate:datatypes comment
sed -i '/AUTO GENERATED USING npm run generate:datatypes/{n;d}' ./src/lib/types.ts

# Add the new NamedDatatype type definition
sed -i "/AUTO GENERATED USING npm run generate:datatypes/a\export type NamedDatatype = $datatypes" ./src/lib/types.ts

echo $datatypes