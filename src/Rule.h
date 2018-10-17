//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_RULE_H
#define DATALOG_PARSER_CS236_BYU_RULE_H

#include <vector>
#include <sstream>

#include "Predicate.h"

class Rule {
 private:
  Predicate head;
  std::vector<Predicate> list;

 public:
  Rule() = default;
  Rule(Predicate headPredicate): head(std::move(headPredicate)) {};
  Rule(Predicate headPredicate, Predicate predicate) {
    head = headPredicate;
    list.emplace_back(predicate);
  };
  Rule(Predicate headPredicate, std::vector<Predicate> predicateList)
    : head(headPredicate), list(predicateList) {};

  void setHead(Predicate headPredicate) {
    head = headPredicate;
  }
  void addPredicate(Predicate predicate) {
    list.emplace_back(predicate);
  }
  void setList(std::vector<Predicate> predicateList) {
    list = predicateList;
  }

  Predicate getHead() {
    return head;
  }

  std::vector<Predicate> getList() {
    return list;
  }

  std::string toString() {
    std::stringstream ss;
    ss << head.toString() << " :- ";
    for (std::size_t i = 0, max = list.size(); i < max; i++) {
      ss << list[i].toString();
      if (i != max - 1) ss << ",";
    }
    ss << ".";
    return ss.str();
  }
};

#endif //DATALOG_PARSER_CS236_BYU_RULE_H
