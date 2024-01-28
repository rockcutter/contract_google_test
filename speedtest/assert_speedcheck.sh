#!/bin/bash

for i in {1..100}
do
   ./assert >> assert_result.txt
   ./manual_assert >> manual_assert_result.txt
done
