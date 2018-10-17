

//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_QUERY_H
#define DATALOG_PARSER_CS236_BYU_QUERY_H

#include <sstream>
#include "Predicate.h"

class Query {
 private:
  Predicate pred;

 public:
  Query() = default;
  Query(Predicate predicate): pred(std::move(predicate)) {};

  void setPredicate(Predicate predicate) {
    pred = predicate;
  }

  Predicate getPredicate() {
    return pred;
  }

  std::string toString() {
    std::stringstream ss;
    ss << pred.toString() << "?";
    return ss.str();
  }
};

#endif //DATALOG_PARSER_CS236_BYU_QUERY_H
