#!/bin/bash

#for every directory of level 2 in this folder, cat test_problem.sh to a file named test.sh and give it execution permission

for D in `ls -d */`
do 
  echo "-> $D"
  for F in `ls -d $D*`
  do
    echo "  -> $F"
    cat ./test_problem.sh > $F/test.sh
  done


done