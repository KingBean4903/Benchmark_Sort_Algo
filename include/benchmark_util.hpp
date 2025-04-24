#ifndef BENCHMARK_UTIL_HPP
#define BENCHMARK_UTIL_HPP

#include <vector>
#include <random>
#include <functional>
#include <chrono>

namespace benchmark {

	using Clock = std::chrono::high_resolution_clock;

	template<typename T>
	std::vector<T> generate_random_data(size_t size, T min = 0,
										T max = 100000)
	{
			std::vector<T> data(size);
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<T> dist(min, max);
			
			for (auto& val : data)
			{
					val = dist(gen);
			}
			return data;
	}

	template<typename Func, typename... Args>
	double time_function(Func&& func, Args&&... args) { 
		
		auto start = Clock::now();
		func(std::forward<Args>(args)...);
		auto end = Clock::now();
		std::chrono::duration<double, std::milli> elapsed = 
				end - start;
		
		return elapsed.count();
	}
		
	template<typename Func, typename Container>
	void benchmark_time(Func func, Container data)
	{
		auto start = std::chrono::high_resolution_clock::now();
		func(data.begin(), data.end());
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> elapsed = end - start;
		std::cout << " took" << elapsed.count() << " ms\n";
	}
	
	

		
}

#endif
