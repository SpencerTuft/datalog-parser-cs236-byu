#!/usr/bin/env bash

# Build Image
 docker build -t memory-test:0.1 .

# Run container
 docker run -it -v $PWD:/app memory-test:0.1 bash -c "cd /app/; g++ -Wall -Werror -g -std=c++14 ./src/*.cpp ./src/lexer/*.cpp -o ./datalog-parser-cs236-byu && valgrind --leak-check=full ./datalog-parser-cs236-byu ./test/in/62.txt"
