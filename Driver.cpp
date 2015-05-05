#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring> 
#include <stdlib.h>

#include "HashTable.h"

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

	std::ifstream in (inputFileName); // input
	std::ofstream out(outputFileName);
	if (!in.is_open())  {
		std::cout << "ERROR: Could not open input file " << inputFileName << std::endl;
		usageString();
	}

	std::ofstream outf (outputFileName);
	if(!outf.is_open()){
		std::cout << "ERROR: Could not open output file " << outputFileName << std::endl;
		usageString();
	}

	METHOD m;
	switch(stoi(methodChoice)){
		case 1:
			m = LINEAR;
			break;
		case 2:
			m = QUADRATIC;
			break;
		case 3:
			m = DOUBLE;
			break;
		case 4:
			m = PERFECT;
			break;
		default:
			std::cout << "ERROR: Invalid algorithm choice " << methodChoice << std::endl;
			usageString();
	}

	int TOTAL_LINES = 0;
	bool doOnce = false;	
    HashTable hash(m, 10000);// Create the HashTable

	if (in.good()) {
		clock_t begin = clock();
		int numLines;
		std::string operation;
		in >> numLines;
		for (int i = 0; i < numLines; i++) {
			int numOperations;
			in >> operation;
			in >> numOperations;
			// std::cout << operation << std::endl;
			for (int j = 0; j < numOperations; i++, j++) {
				int key, value;
				in >> key >> value;
				if (operation == "INSERT") {
					// std::cout << key << " " << value << std::endl;
					hash.insert(key, value);
				} else if (operation == "DELETE") {
					// std::cout << key << std::endl;
					hash.remove(key, value);
				} else if (operation == "FIND") {
					// std::cout << key << std::endl;
					hash.find(key, value);
				} else {
					std::cout << "Invalid operation" << std::endl;
					return 0;
				}
			}
		}
    	clock_t end = clock();
	    double t_elapsed = double (end - begin) / (CLOCKS_PER_SEC);
	}
	in.close();
	outf.close();
}
