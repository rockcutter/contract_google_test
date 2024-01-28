#include <cstdlib>
#include <climits>
#include <iostream>
#include <chrono>

constexpr int FUNC_CALL_COUNT = INT_MAX;

void func(int i){
	if(!(i > 0)){
		abort();
	}
}

int main(){
	std::chrono::system_clock::time_point start, end;
	double elapsed = 0;
	using TestDuration = std::chrono::milliseconds;

	start = std::chrono::system_clock::now();

	for(int i = 0; i < FUNC_CALL_COUNT; i++){
		func(2);
	}

	end = std::chrono::system_clock::now();
	elapsed = std::chrono::duration_cast<TestDuration>(end-start).count();

	std::cout << "manual_assert: " << elapsed << std::endl;
}
