#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

void differentSizeError() {
    cerr << "Matrices have different dimentions. Comparison can't be made." << endl;
    exit(0);
}

void notNanCellError(int row, int column) {
    cerr << "A valid alternative in one of the matrices is invalid in the other one. Comparison can't be made." << endl;
    cerr << "Position with problem is [" << row << ", " << column << "]." << endl; 
    exit(0);
}

int main(int argc, char* argv[]){
    string line0, line1;
    int actualLine, actualColumn;
    double diff = 0.0, diffSum = 0.0;
    
    ifstream in0(argv[1]);
    ifstream in1(argv[2]);

    actualLine = 1;
    while( getline(in0, line0) ) {
        if( !getline(in1, line1) ) differentSizeError();

        stringstream reader0(line0);
        stringstream reader1(line1);
        string token0, token1;

        actualColumn = 1;
        while(reader0 >> token0) {
            if( !(reader1 >> token1) ) differentSizeError(); 

            if(token0 == "nan" && token1 == "nan");
            else if(token0 == "nan" || token1 == "nan") notNanCellError(actualLine, actualColumn);
            else {
                double value0 = atof(token0.c_str());
                double value1 = atof(token1.c_str());
                diff = max(diff, fabs(value0 - value1));
                diffSum += fabs(value0 - value1);
            }

            actualColumn++;
        }

        actualLine++;
    }

    if(getline(in1, line1)) differentSizeError();

    cerr << fixed << setprecision(10);
    cerr << endl << "Results:" << endl;
    cerr << "Maximum difference is " << diff << endl;
    cerr << "Sum of differences is " << diffSum << endl;

    return 0;
}