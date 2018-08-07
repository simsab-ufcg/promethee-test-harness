/**
g++ -std=c++14 comparator.cpp -o comparator
./comparator normalizedflow.txt IMD-I_CONVERTED.txt
**/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;
void differentSizeError(){
    cerr << "Tamanhos diferentes" << endl;
    exit(0);
}
int main(int argc, char* argv[]){
    ifstream in0(argv[1]);
    ifstream in1(argv[2]);
    string line0, line1;
    double diff = 0, diffSum = 0;
    while(getline(in0, line0)){
        if(!getline(in1, line1))
            differentSizeError();
        stringstream reader0(line0);
        stringstream reader1(line1);
        string token0, token1;
        while(reader0 >> token0){
            if(!(reader1 >> token1)){
                differentSizeError(); 
            }
            if(token0 == "nan" && token1 == "nan");
            else if(token0 == "nan" || token1 == "nan"){
                cerr << "not nan cell" << endl;
                return 0;
            } else {
                double value0 = atof(token0.c_str());
                double value1 = atof(token1.c_str());
                diff = max(diff, fabs(value0 - value1));
                diffSum += fabs(value0 - value1);
            }
        }
    }
    if(getline(in1, line1)){
        differentSizeError();
    }
    cerr << fixed << setprecision(10);
    cerr << "Maximum difference: " << diff << endl;
    cerr << "Sum of differences: " << diffSum << endl;
    return 0;
}