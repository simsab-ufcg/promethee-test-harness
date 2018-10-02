#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

#define EPS 1e-6

void differentSizeError(int errType) {
	cerr << endl;
	cerr << "Number of " << (errType == 1 ? "lines" : "columns") << " does not match." << endl;
    cerr << "Comparison can't be made." << endl;
    exit(0);
}

void notNanCellError(int line, int column) {
	cerr << endl;
    cerr << "A valid alternative in one of the matrices is invalid in the other one. Comparison can't be made." << endl;
    cerr << "Position with problem is [" << line << ", " << column << "]." << endl; 
    exit(0);
}

void differentResultsError(double value1, double value2, int line, int column) {
	cerr << endl;
	cerr << "Oops! Results are different." << endl;
	cerr << "In position [" << line << ", " << column << "] file1 has (" << value1 << ")";
	cerr << " while file2 has (" << value2 << ")" << endl;
	exit(0);
}

int main(int argc, char* argv[]) {
	ifstream file1(argv[1]);
	ifstream file2(argv[2]);

	int actualLine, actualColumn;
	double value1, value2, difference;
	string line1, line2, token1, token2;

	actualLine = actualColumn = 0;

	while( getline(file1, line1) ) {
		if( !getline(file2, line2) ) differentSizeError(1);

		stringstream reader1(line1);
		stringstream reader2(line2);

		while(reader1 >> token1) {
			if( !(reader2 >> token2) ) differentSizeError(2);

			if(token1 == "nan" and token2 == "nan");
			else {
				if(token1 == "nan" or token2 == "nan") notNanCellError(actualLine, actualColumn);
				else {
					value1 = atof(token1.c_str());
					value2 = atof(token2.c_str());
					
					difference = fabs(value1 - value2);
					if(difference > EPS) differentResultsError(value1, value2, actualLine, actualColumn);
				}
			}

			actualColumn++;
		}

		actualLine++;
	}

	cout << "Tests passed!" << endl;
	return 0;
}