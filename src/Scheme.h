//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_SCHEMES_H
#define DATALOG_PARSER_CS236_BYU_SCHEMES_H

#include <vector>
#include <string>
#include <sstream>

#include "Token.h"

class Scheme {
 private:
  std::string name;
  std::vector<std::string> list;
 public:
  Scheme() = default;
  Scheme(std::string schemeName): name(std::move(schemeName)) {};
  Scheme(std::string schemeName, std::string id) {
    name = schemeName;
    list.emplace_back(id);
  };
  Scheme(std::string schemeName, std::vector<std::string> idList): name(std::move(schemeName)), list(idList) {};

  void setName(std::string schemeName) {
    name = schemeName;
  }

  void addId(std::string identifier) {
    list.push_back(identifier);
  }

  std::vector<std::string> getIdList() {
    return list;
  };

  std::string getName() {
    return name;
  };

  std::string toString() {
    std::stringstream ss;
    ss << name << "(";
    for (std::size_t i = 0, max = list.size(); i < max; i++) {
      ss << list[i];
      if (i != max - 1) ss << ",";
    }
    ss << ")";
    return ss.str();
  };
};

#endif //DATALOG_PARSER_CS236_BYU_SCHEMES_H
