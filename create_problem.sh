#!/bin/bash

#A problem consists on a file named base.cpp, a makefile, a file named input.in, and a file named output.out
#The base.cpp contains the code in template.cpp
#The makefile is a copy of the makefile in this directory

#The script will be called with two parameters, the id of the contest and the letter of the problem.


mkdir $1 

# if second parameter not given, it will be set to all letters from A to I

if [ "$2" == "" ]
then
  for i in {A..I}
  do
    mkdir $1/$i
    cp template.cpp $1/$i/base.cpp
    cp makefile $1/$i/makefile
    cp test.sh $1/$i/test.sh
    echo "" > $1/$i/input.in
    echo "" > $1/$i/output.out    
  done

else
  mkdir $1/$2
  cp template.cpp $1/$2/base.cpp
  cp makefile $1/$2/makefile
  cp test.sh $1/$2/test.sh
  echo "" > $1/$2/input.in
  echo "" > $1/$2/output.out
  code $1/$2/base.cpp $1/$2/input.in  

fi

