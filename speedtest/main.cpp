#include <chrono>
#include <iostream>
#include <cmath>
#include <climits>

//constexpr int FUNC_FORLOOP_COUNT = 10000000;

double mysqrt(double n)
	[[expects: n >= 0]]
	[[ensures r: r >= 0]]
{
	 // 平方根を求める処理
	 return std::sqrt(n);
}
double mysqrt_noattr(double n)
{
	 // 平方根を求める処理
	 return std::sqrt(n);
}
double internalfunc(double n)
{
	return std::sqrt(n);
}
double mysqrt_with_manual_postcond(double n)
{
	if(!(n >= 0)){
		abort();
	}
	// 平方根を求める処理
	auto r = internalfunc(n);
	if(!(r >= 0)){
	 abort();
	}
	return r;
}

void assert_gt_20(int n)
{
    //nが20より大きいことを表明する
    [[assert: n > 20]];
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
		mysqrt_with_manual_postcond(2);
	}

	end = std::chrono::system_clock::now();  
	attr_elapsed = std::chrono::duration_cast<TestDuration>(end-start).count(); 

	start = std::chrono::system_clock::now(); 

	for(int i = 0; i < MAX_TIMECHECK_COUNT; i++){
		mysqrt_noattr(2);
	}

	end = std::chrono::system_clock::now();  
	elapsed = std::chrono::duration_cast<TestDuration>(end-start).count(); 

	start = std::chrono::system_clock::now(); 

	for(int i = 0; i < MAX_TIMECHECK_COUNT; i++){
		mysqrt(2);
	}

	end = std::chrono::system_clock::now();  
	checked = std::chrono::duration_cast<TestDuration>(end-start).count(); 

	std::cout << "attr_elapsed: " << attr_elapsed << std::endl;
	std::cout << "elapsed: " << elapsed << std::endl;
	std::cout << "checked: " << checked << std::endl;

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
