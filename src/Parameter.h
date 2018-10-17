

//
// Created by Spencer Tuft on 10/6/18.
//

#ifndef DATALOG_PARSER_CS236_BYU_PARAMETER_H
#define DATALOG_PARSER_CS236_BYU_PARAMETER_H

#include "./lexer/Token.h"
#include "./Expression.h"

class Parameter {
 private:
  std::string value;
  std::string type;

 public:
  Parameter() {};
  Parameter(Token &token): value(token.getValue()), type(token.getType()) {};
  Parameter(std::string paramValue, std::string paramType): value(paramValue), type(paramType) {};
  Parameter(Expression expression): value(expression.toString()), type("EXPRESSION") {};

  void setValue(std::string paramValue) {
    value = paramValue;
  }

  void setType(std::string paramType) {
    type = paramType;
  }

  std::string getValue() {
    return value;
  }
  std::string getType() {
    return type;
  }
};

#endif //DATALOG_PARSER_CS236_BYU_PARAMETER_H
