HOME=$PWD
PROGRAM_PATH=$1
EXECUTABLE=$(basename $PROGRAM_PATH)
INPUT_PATH=$2
OUTPUT_PATH=$3
EXPECTED_OUTPUT_PATH=$4

cd $(dirname $PROGRAM_PATH)
./$EXECUTABLE < $INPUT_PATH > $OUTPUT_PATH


cd $HOME/comparator
echo $PWD

g++ -std=c++14 comparator.cpp -o comparator
./comparator < $EXPECTED_OUTPUT_PATH < $OUTPUT_PATH
