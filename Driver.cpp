#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring> 
#include <time.h>
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
		exit(0);
	}

	std::string inputFileName = argv[1];
	std::string outputFileName = argv[2];
	std::string methodChoice = argv[3];

	std::ifstream in (inputFileName); // input
	std::ofstream out(outputFileName);
	if (!in.is_open())  {
		std::cout << "ERROR: Could not open input file " << inputFileName << std::endl;
		usageString();
		exit(0);
	}

	std::ofstream outf (outputFileName);
	if(!outf.is_open()){
		std::cout << "ERROR: Could not open output file " << outputFileName << std::endl;
		usageString();
		exit(0);
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
			exit(0);
	}

	int TOTAL_LINES=0, insertCtr = 0, deleteCtr =0, findCtr= 0;
	bool doOnce = false;	
    HashTable hash(m, 10007);// Create the HashTable
	double avgInsert, avgDelete, avgFind, temp;
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
					clock_t insertT = clock();
					//std:: cout<< "insertT insert " <<insertT << std::endl;
					hash.insert(key, value);
					clock_t endInsertT = clock();
					insertCtr++;
					//std::cout << "endT insert: " << endInsertT << std::endl;
					temp = double (endInsertT - insertT ) / (CLOCKS_PER_SEC);
					//std::cout << "Insert: " << temp << std::endl;
					avgInsert += temp;		
				} else if (operation == "DELETE") {
					// std::cout << key << std::endl;
					clock_t removeT = clock();
					hash.remove(key, value);
					clock_t endRemoveT = clock();
					temp = double (endRemoveT - removeT) / (CLOCKS_PER_SEC);
					deleteCtr++;
					avgDelete += temp;
				} else if (operation == "FIND") {
					// std::cout << key << std::endl;
					clock_t findT = clock();
					hash.find(key, value);
					clock_t endFind = clock();
					temp = double (endFind - findT) / (CLOCKS_PER_SEC);
					findCtr++;
					avgFind += temp;
				} else {
					std::cout << "Invalid operation" << std::endl;
					return 0;
				}
			}
		}
	}
	clock_t end = clock();
	 double t_elapsed = double (end - begin) / (CLOCKS_PER_SEC);
	in.close();
	outf.close();
	std::cout << "Average insert time " << (avgInsert / insertCtr)  << std::endl;
	std::cout << "Average delete time " << (avgDelete / deleteCtr)  << std::endl;
	std::cout << "Average find time " << (avgFind / findCtr)  << std::endl;
	std::cout << "Total run time " << t_elapsed << std::endl;
}
