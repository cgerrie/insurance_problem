/* Charlie Gerrie 2021
 */

#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char *argv[]) {
	// handle arguments
	if(argc<2) {
		std::cout << "Insufficient arguments" << std::endl;
		std::exit(1);
	}
	// parse arguments as numbers
	char *p1, *p2;
	const double threshold = std::strtod(argv[1], &p1),
	             limit = std::strtod(argv[2], &p2);
	if(p1-argv[1]<1 || p2-argv[2]<1) {
		std::cout << "Arguments must be numbers" << std::endl;
		std::exit(2);
	}
				 
	// read up to n<100 lines stdin
	std::string input;
	double inputs[100];
	int input_index = 0;
	// read line
	while(std::cin >> input && input_index<100) {
		// parse number
		inputs[input_index++] = std::stod(input, NULL);
	}
	
	// cumulative variables
	double remaining_limit = limit;
	double sum = 0;
	// generate outputs
	double x,
	       outputs[100];
	int output_index = 0;
	for(;output_index<input_index;output_index++) {
		x = std::max(0.0, inputs[output_index] - threshold);
		x = std::min(x, remaining_limit);
		outputs[output_index] = x;
		// update cumulative variables
		remaining_limit -= x;
		sum += x;
	}
	
	// output
	for(output_index = 0;output_index<input_index;output_index++) {
		std::printf("%.1f\n", outputs[output_index]);
	}
	std::printf("%.1f\n", sum);
}
