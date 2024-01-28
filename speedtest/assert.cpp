#include <iostream>
#include <cstdlib>
#include <climits>
#include <chrono>

constexpr int FUNC_CALL_COUNT = INT_MAX;

void func(int i){
	[[assert: i > 0]];
}

int main(){
	std::chrono::system_clock::time_point  start, end;
	double elapsed = 0;
	using TestDuration = std::chrono::milliseconds;

	start = std::chrono::system_clock::now();

	for(int i = 0; i < FUNC_CALL_COUNT; i++){
		func(2);
	}

	end = std::chrono::system_clock::now();
	elapsed = std::chrono::duration_cast<TestDuration>(end-start).count();
	std::cout << "assert: " << elapsed << std::endl;
}
