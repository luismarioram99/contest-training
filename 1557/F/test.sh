#!/bin/bash

# take two arguments, the first is the name of the contest to run
# the second one is the name of the problem to run

cd $1/$2
make
./base < input.in > output.out
cat output.out

