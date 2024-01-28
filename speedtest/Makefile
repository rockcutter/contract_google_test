CLANG = /home/iwakiri/llvm-project-add-contract-private/build/bin/clang++

speedtest: main.cpp
	$(CLANG) -o speedtest main.cpp -std=c++20 -O0

IR.ll: main.cpp
	$(CLANG) -S -emit-llvm main.cpp -o IR.ll -O0

contractIR.ll: contract.cpp
	$(CLANG) -S -emit-llvm contract.cpp -o contractIR.ll -O0

manual_contractIR.ll: manual_contract.cpp
	$(CLANG) -S -emit-llvm manual_contract.cpp -o manual_contractIR.ll -O0

contract: contract.cpp
	$(CLANG) -o contract contract.cpp -std=c++20 -O0

assert: assert.cpp
	$(CLANG) -o assert assert.cpp -std=c++20 -O0

manual_assert: manual_assert.cpp
	$(CLANG) -o manual_assert manual_assert.cpp -std=c++20 -O0

manual_contract: manual_contract.cpp
	$(CLANG) -o manual_contract manual_contract.cpp -std=c++20 -O0

double_check_manual_contract: double_check_manual_contract.cpp
	$(CLANG) -o double_check_manual_contract double_check_manual_contract.cpp -std=c++20 -O0

manual_contract_internal: manual_contract_internal.cpp
	$(CLANG) -o manual_contract_internal manual_contract_internal.cpp -std=c++20 -O0
