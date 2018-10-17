//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_PREDICATE_H
#define DATALOG_PARSER_CS236_BYU_PREDICATE_H

#include <vector>
#include <sstream>
#include "Token.h"
#include "Parameter.h"

class Predicate {
 private:
  std::string id;
  std::vector<Parameter> list;

 public:
  Predicate() = default;
  Predicate(std::string identifier): id(std::move(identifier)) {};
  Predicate(std::string identifier, Parameter parameter) {
    id = std::move(identifier);
    list.emplace_back(parameter);
  };
  Predicate(std::string identifier, std::vector<Parameter> parameterList)
    : id(std::move(identifier)), list(std::move(parameterList)) {};

  void setId(std::string identifier) {
    id = identifier;
  }

  void setParamList(std::vector<Parameter> parameterList) {
    list = parameterList;
  }

  void addParam(Parameter parameter) {
    list.emplace_back(parameter);
  }

  std::string toString() {
    std::stringstream ss;
    ss << id << "(";
    for (std::size_t i = 0, max = list.size(); i < max; i++) {
      ss << list[i].getValue();
      if (i != max - 1) ss << ",";
    }
    ss << ")";
    return ss.str();
  }
};

#endif //DATALOG_PARSER_CS236_BYU_PREDICATE_H
