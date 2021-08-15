#!/bin/bash

git add * 

if ["$1" != ""]
then
  git commit
  git push origin develop

else  

  if [ "$2" == "" ]
  then
    git commit -m "Finished contest $1"
    git push origin develop
  else
    git commit -m "Finished problem $1/$2"
    git push origin develop
  fi

fi

