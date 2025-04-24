#include <iostream>
#include "benchmark_util.hpp"
#include "for_each.hpp"
#include <type_traits>

extern void std_sort(std::vector<int>&);

int main() {
	
	const size_t dataSize = 10000;
	
	auto data = benchmark::generate_random_data<int>(dataSize);

	auto duration = benchmark::time_function(std_sort, data);

	std::cout << "std::sort executed in " << duration <<
							" ms" << std::endl;


	auto op = [](int& val) { val *= 2; };
	auto bound_op = [&](auto begin, auto end) {
			parallel_for_each(begin, end, op);
	};

	benchmark::benchmark_time(bound_op, data);

	return 0;

}
