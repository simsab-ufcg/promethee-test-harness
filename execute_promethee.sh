PROGRAM_PATH=$1
INPUT_PATH=$2
OUTPUT_PATH=$3
EXPECTED_OUTPUT_PATH=$4

# executes the promethee with given inputs and output paths
/$PROGRAM_PATH < $INPUT_PATH > $OUTPUT_PATH

# executes the comparator with given the expected output path
./diff/comparator < $EXPECTED_OUTPUT_PATH < $OUTPUT_PATH
