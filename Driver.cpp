#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring> 
#include <stdlib.h>

/*
* Print the usage string
*/
void usageString() {
	std::cout << "Usage: hash-table <input-file-name> <output-file-name> [1-linear | 2-quadtratic | 3-double | 4-perfect]" << std::endl;
}

int main(int argc, const char *argv[]){
	clock_t begin = clock();
    /*argv[1]: <input file name>
    argv[2]: <output file name>
    argv[3]: 1(linear), 2(quadratic), 3(double), 4(perfect)
    */
	std::string inputFileName = argv[1];
	std::string outputFileName = argv[2];
	std::string methodChoice = argv[3];
	
	
	std::string line, input; //yeah ill use strings. 
	std::ifstream in (inputFileName); // input
	std::ofstream outf (outputFileName, ios::app);
	if (!in.is_open())  {
		std::cout << "ERROR: Could not open input file " << inputFileName << std::endl;
		usageString();
	}else if(!outf.is_open()){
		std::cout << "ERROR: Could not open input file " << outputFileName << std::endl;
		usageString();
	}else if(argc != 3){
		std::cout << "ERROR: 3 arguments were not specified" << std::endl;
		usageString();
	}
	std::string input;
	if (prices.good()) {
        while (getline(prices, input)) {
		// TODO	

		}
	}
	prices.close();
    clock_t end = clock();
    double t_elapsed = double (end - begin) / (CLOCKS_PER_SEC);
}
