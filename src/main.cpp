#include <iostream>
#include <vector>
#include <string>
#include "./DatalogParser.h"

/**
 * Main process
 * @param argc = argument count
 * @param argv = argument vector
 * @return
 */
int main(int argc, const char *argv[]) {
  std::string fileName = argv[1];

  if (argc < 1) {
    std::cout << "Missing input file argument" << std::endl;
    return 0;
  }
  std::string inputFileName = std::string(fileName);
  DatalogParser dl(inputFileName);
//  std::cout << dl.toString() << std::endl;
  return 0;
}