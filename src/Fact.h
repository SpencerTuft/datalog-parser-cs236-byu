//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_FACT_H
#define DATALOG_PARSER_CS236_BYU_FACT_H

#include <string>
#include <sstream>
#include <vector>
#include "Token.h"

class Fact {
 private:
  std::string name;
  std::vector<std::string> list;

 public:
  Fact() = default;
  Fact(std::string factName) : name(std::move(factName)) {};
  Fact(std::string factName, std::string value) {
    name = factName;
    list.emplace_back(value);
  };
  Fact(std::string factName, std::vector<std::string> values) : name(factName), list(values) {};

  void addValue(std::string value) {
    list.emplace_back(value);
  }

  void setName(std::string factName) {
    name = factName;
  }

  std::string getName() {
    return name;
  }

  std::vector<std::string> getList() {
    return list;
  }

  std::string toString() {
    std::stringstream ss;
    ss << name << "(";
    for (std::size_t i = 0, max = list.size(); i < max; i++) {
      ss << list[i];
      if (i != max - 1) ss << ",";
    }
    ss << ").";
    return ss.str();
  };
};

#endif //DATALOG_PARSER_CS236_BYU_FACT_H
