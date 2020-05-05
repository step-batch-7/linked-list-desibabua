#! /bin/bash

cd test
rm -rf *.o
gcc -c *.c
gcc -o ./test_results *.o
./test_results
rm -rf ./test_results
rm -rf ./*.o
cd ..