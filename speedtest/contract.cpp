#include <chrono>
#include <iostream>
#include <cmath>
#include <climits>

double mysqrt(double n)
	[[expects: n >= 0]]
	[[ensures r: r >= 0]]
{
	 // 平方根を求める処理
	 return std::sqrt(n);
}

int main(){
	constexpr int MAX_TIMECHECK_COUNT = INT_MAX;
	std::chrono::system_clock::time_point  start, end; 
	double elapsed = 0;
	double attr_elapsed = 0;
	double delta = 0;
	double checked = 0;
	using TestDuration = std::chrono::milliseconds;

	start = std::chrono::system_clock::now(); 

	for(int i = 0; i < MAX_TIMECHECK_COUNT; i++){
		mysqrt(2);
	}

	end = std::chrono::system_clock::now();  
	attr_elapsed = std::chrono::duration_cast<TestDuration>(end-start).count(); 

	std::cout << "contract: " << attr_elapsed << std::endl;
	return 0;
}

//	for(int i = 0; i < MAX_TIMECHECK_COUNT; i++){
//		std::chrono::system_clock::time_point  start, end; 
//		double elapsed = 0;
//		double attr_elapsed = 0;
//		double delta = 0;
//		start = std::chrono::system_clock::now(); 
//
//		sqrt(2)
//
//		end = std::chrono::system_clock::now();  
//		elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count(); 
//
//		start = std::chrono::system_clock::now(); 
//
//		sqrt(2);
//
//		end = std::chrono::system_clock::now();  
//		attr_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count(); 
//		
//		delta = attr_elapsed - elapsed;
//
//		std::cout 
//			<< elapsed << ","
//			<< attr_elapsed << ","
//			<< delta
//			<< std::endl;
//	}
