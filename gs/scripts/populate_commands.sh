#!/bin/sh

echo 'Populating commands...'

# Get the commands from the commands.toml file
commands=$(grep -oP '(?<=name = ").*(?=")' ../config/commands.toml)

# Add quotes around each command name
commands=$(echo "$commands" | sed -r 's/(.*)/"\1"/')

# Format into TS union
commands_union=$(echo "$commands" | sed -r ':a;N;$!ba;s/\n/ | /g')

# Format into TS array
commands_array=$(echo "$commands" | sed -r ':a;N;$!ba;s/\n/, /g')

# Replace the NamedCommand type definition
sed -i "s/^export type NamedCommand.*/export type NamedCommand = $commands_union;/" ./src/lib/types.ts

# Replace the NamedCommandValues array
sed -i "s/^export const NamedCommandValues.*/export const NamedCommandValues:NamedCommand[] = [$commands_array];/" ./src/lib/types.ts

echo $commands_union
echo $commands_array