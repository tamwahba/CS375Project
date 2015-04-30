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
	std::cout << "Usage: hash <input-file-name> <output-file-name> [1-linear | 2-quadtratic | 3-double | 4-perfect]" << std::endl;
}

int main(int argc, const char *argv[]){
	clock_t begin = clock();
    /*argv[1]: <input file name>
    argv[2]: <output file name>
    argv[3]: 1(linear), 2(quadratic), 3(double), 4(perfect)
    */
	
	/*
	string line, input; //yeah ill use strings. 
	std::ifstream in (argv[1] ); // input
	std::ofstream outf (argv[2], ios::app );
	if (!outf.is_open() || !in.is_open() || argc != 3)  {std::cout << "error opening input /output files please check again " << argv[1] << " " << argv[2] << std::endl;  }
	string input;
if ( prices.good() ) {
        while ( getline (prices, input) ) {
		// TODO	

	}
}
	prices.close();
    clock_t end = clock();
    double t_elapsed = double (end - begin) / (CLOCKS_PER_SEC);

// outf is outputfile

	*/
}
