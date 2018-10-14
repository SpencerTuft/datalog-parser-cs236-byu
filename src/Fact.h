//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_FACT_H
#define DATALOG_PARSER_CS236_BYU_FACT_H

#include <string>
#include <vector>

#include "../lexer/Token.h"

class Fact {
 private:
  Token id;
  std::vector<std::string> stringList;
};

#endif //DATALOG_PARSER_CS236_BYU_FACT_H
