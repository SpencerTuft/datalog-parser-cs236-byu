//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_DATALOGPARSER_H
#define DATALOG_PARSER_CS236_BYU_DATALOGPARSER_H

#include <vector>

#include "./Scheme.h"
#include "./Fact.h"
#include "./Rule.h"
#include "./Query.h"

class DatalogParser {
 private:
  std::vector<Scheme> schemes;
  std::vector<Fact> facts;
  std::vector<Rule> rules;
  std::vector<Query> querys;

 public:
  void advance ();
};

#endif //DATALOG_PARSER_CS236_BYU_DATALOGPARSER_H
