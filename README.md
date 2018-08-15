## Promethee Test Harness  
A bash script that runs promethee and compares the output with the expected one.

## Usage
The script requires 6 arguments:

 1. Promethee's executable path
 2. Promethee's input directory path
 3. Promethee's meta directory path
 4. Promethee's output directory path
 5. Path to the generated output file
 6. Path to the expected output file

## Example

    sh execute_promethee /path/to/executable /path/to/input/directory/ /path/to/meta/directory/ /path/to/output/directory/ /path/to/output /path/to/expected-output
    The comparison between the generated output and the expected one will then be made.

