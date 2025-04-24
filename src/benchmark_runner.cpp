#include <iostream>
#include "benchmark_util.hpp"

extern void std_sort(std::vector<int>&);

int main() {
	
	const size_t dataSize = 100000;

	auto data = benchmark::generate_random_data<int>(dataSize);

	auto duration = benchmark::time_function(std_sort, data);

	std::cout << "std::sort executed in " << duration <<
							" ms" << std::endl;

	return 0;

}
