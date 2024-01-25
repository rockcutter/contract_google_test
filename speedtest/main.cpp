#include <chrono>
#include <iostream>

constexpr int FUNC_FORLOOP_COUNT = 10000000;

int func(int param){
	int retval = param;
	for(int i = 0; i < FUNC_FORLOOP_COUNT; i++){
		retval = i;
	}
	return retval;
}

int func_with_attr(int param)
	[[expects: param > 0]]
	[[ensures r: r > 0]]
{
	int retval = param;
	for(int i = 0; i < FUNC_FORLOOP_COUNT; i++){
		retval = i;
	}
	return retval;
}

int main(){

	constexpr int MAX_TIMECHECK_COUNT = 10000;

	for(int i = 0; i < MAX_TIMECHECK_COUNT; i++){
		std::chrono::system_clock::time_point  start, end; 
		double elapsed = 0;
		double attr_elapsed = 0;
		double delta = 0;
		start = std::chrono::system_clock::now(); 

		func(2);

		end = std::chrono::system_clock::now();  
		elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count(); 

		start = std::chrono::system_clock::now(); 

		func_with_attr(2);

		end = std::chrono::system_clock::now();  
		attr_elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count(); 
		
		delta = attr_elapsed - elapsed;

		std::cout 
			<< elapsed << ","
			<< attr_elapsed << ","
			<< delta
			<< std::endl;
	}
}
