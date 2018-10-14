//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_SCHEMES_H
#define DATALOG_PARSER_CS236_BYU_SCHEMES_H

#include <vector>

#include "../lexer/Token.h"

class Scheme {
 private:
  Token id;
  std::vector<Token> idList;
};

#endif //DATALOG_PARSER_CS236_BYU_SCHEMES_H
