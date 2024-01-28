#!/bin/bash

for i in {1..100}
do
   ./contract >> contract_result.txt
   ./manual_contract >> manual_contract_result.txt
done
