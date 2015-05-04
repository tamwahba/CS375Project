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
	if(argc != 4){
		std::cout << "ERROR: 3 arguments were not specified" << std::endl;
		usageString();
	}

	std::string inputFileName = argv[1];
	std::string outputFileName = argv[2];
	std::string methodChoice = argv[3];

	std::string line, input; //yeah ill use strings. 
	std::ifstream in (inputFileName); // input
	if (!in.is_open())  {
		std::cout << "ERROR: Could not open input file " << inputFileName << std::endl;
		usageString();
	}

	std::ofstream outf (outputFileName);
	if(!outf.is_open()){
		std::cout << "ERROR: Could not open output file " << outputFileName << std::endl;
		usageString();
	}

	if (in.good()) {
		clock_t begin = clock();
        while (getline(in, input)) {
		// TODO	

		}
    	clock_t end = clock();
	    double t_elapsed = double (end - begin) / (CLOCKS_PER_SEC);
	}
	in.close();
	outf.close();
}
