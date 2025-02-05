#!/bin/bash

g++ -o temp $1 -lGL -lGLU -lglut
./temp

# If the flag --loop is set, ./execute-code.sh $1
if [ "$2" == "--loop" ]; then
./execute-code.sh $1 --loop
fi

#./execute-code.sh $1
