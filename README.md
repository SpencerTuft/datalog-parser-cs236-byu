# datalog-parser-cs236-byu

### Table of Contents
- [Introduction](#introduction)
- [Project Description](#project-description)
- [Requirements](#requirements)
  * [Part 1 Syntax Checker](#part-1-syntax-checker)
  * [Part 2 Datalog Parser](#part-2-datalog-parser)
- [Datalog Grammar](#datalog-grammar)
- [Output Specifications](#output-specifications)
- [Examples](#examples)
  * [Example 1](#example-1)
  * [Example 2](#example-2)
- [FAQ](#faq)
- [Submission](#submission)
- [Pass-off](#pass-off)

### Introduction
A lexical analyzer groups characters in an input stream `S` into tokens. Parsing determines if an input stream of tokens is a member of a language `L` as defined by a grammar `G`. In other words, you need to determine if `S ∈ L(G)`. The test is accomplished by creating an `LL(1)` parser for a simple variant of the *Datalog language*.

### Project Description
Using your lexical analyzer from Project 1, write a parser for the Datalog grammar defined below. You will want to add a few methods to your lexical analyzer to make it easy for you to access the tokens and use the tokens in order to determine if the given input is an instance of a valid Datalog program.

If the parse is successful, `S ∈ L(G)`, return the string: 'Success!' followed by all the schemes, facts, rules, queries, and the domain values (i.e., all the strings that appear in the facts). Include the number of items in each list. Note that the domain is a sorted set (no duplicates) of strings.

If the parse is unsuccessful, S ∉ L(G), output 'Failure!' followed by the offending token, (i.e., its triple including its token-ID name, string value, and line number). Note that the parser stops after encountering the first offending token.

There are two parts to this project:
- Recognizing membership in the language with 10 meaningful tests; and
- Collecting and outputting the data to match the project requirements.

The two parts are due separately and recorded separately. See the next section for details.

### Requirements
#### Part 1 Syntax Checker
You must implement an LL(1) parser to recognize valid and invalid datalog programs according to the Datalog grammar definition. LL(1) is understood as a left to right scan of the input to create a left derivation using only the next token as a look ahead (e.g. a deterministic top-down parser that chooses the rule to expand based on the current token). The parser implementation must also be *recursive* meaning it either uses the runtime stack to keep track of rules in the parse or it manages a stack or rules directly similar to the parse table. Either solution works; although, using the runtime stack is much more direct and simple (i.e., create a method for every rule in the grammar).

Further, *at least 10 test inputs* must be created to test the functionality of the parser. The tests are individual files containing datalog programs (valid or invalid). The tests should cover corner cases and include, *in the comments of the datalog test input*, an explanation of what is being tested with the expected output. Further, all the tests must be automatic; *automatic means the tests run without any user input and reports to the console the status of every test: pass or fail*. The tests must be documented and justified: what does the test accomplish.

- *Command line argument*: no command line arguments
- *Input file*: none
- *Output: Success!* if the input is a member of the language and *Failure!* followed by the offending token, indented, on a new line otherwise. The output is to the console.

Part 1 is scored on your 10 provided tests. Note: part 1 is submitted just like the prior lab; zip up the files and submit the zipped file on learning suite. *The zip-file must include the 10 test cases.*

#### Part 2 Datalog Parser

As the parser traverses the input file reading tokens, collect data from the tokens to store the program input as a collection of instances of classes. If the input is a valid datalog program, then use the class instances to generate output detailing the input data. Classes should be created for at least the following parts of the language: _datalogProgram_, _rule_, _predicate_, _parameter_, and _expressions_. Expressions may be a subclass of Parameter. Expressions require a tree structure to represent arbitrarily nested expressions.

The _datalogProgram_ class should use lists of object instances to collect _schemes_, _facts_, _rules_, or _queries_. The output for this part of the project *must* be generated from the _datalogProgram_ class member variables after the parsing is complete. Implementing toString methods for the different classes is one of several ways to generate the program output.

By way of clarification, the *domain* is any string constant that appears in a _fact_. Only unique values should appear in the domain (no duplicates).

- *Command line*: a single argument indicating the input file
- *Input*: a datalog program (valid or invalid)
- *Output*: see the output specifications and examples

Part 2 is scored on a set of private tests at submission.

### Datalog Grammar
Production start with lower-case letters (nonterminals). Any production that starts with an upper-case letter, such as those at the end of the grammar, represent tokens (terminals). These tokens are input from your scanner and are defined similarly in the Lexical Analyzer. Note that comments do not appear anywhere in the grammar because comments should be ignored. In terms of parsing, this means that you should be able to skip any number of comments showing up at any place in the program. The easiest way to do that is to simply have the lexical analysis ignore comments.

```
grammar Datalog;

/********************************************************
 * Productions
 ********************************************************/
datalogProgram	->	SCHEMES COLON scheme schemeList   FACTS COLON factList   RULES COLON ruleList   QUERIES COLON query queryList


scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN


schemeList	->	scheme schemeList | lambda


idList  	->	COMMA ID idList | lambda


fact    	-> 	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD


factList	->	fact factList | lambda


rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD


ruleList	->	rule ruleList | lambda


headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN


predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN


predicateList	->	COMMA predicate predicateList | lambda


parameter	->	STRING | ID | expression


parameterList	-> 	COMMA parameter parameterList | lambda


expression	-> 	LEFT_PAREN parameter operator parameter RIGHT_PAREN


operator	->	ADD | MULTIPLY


query	        ->      predicate Q_MARK


queryList	->	query queryList | lambda


stringList	->	COMMA STRING stringList | lambda


/********************************************************
 * Token definitions from the lexer project
 * IGNORE: INCLUDED FOR COMPLETENESS FOR ANTLR
 ********************************************************/

COMMA 	:	','
	;

PERIOD	:	'.'
	;

Q_MARK	:	'?'
	;

LEFT_PAREN	: '('
		;

RIGHT_PAREN	: ')'
		;

COLON		: ':'
		;

COLON_DASH	: ':-'
		;

MULTIPLY	: '*'
		;

ADD		: '+'
		;

SCHEMES		: 'Schemes'
		;
FACTS		: 'Facts'
		;
RULES		: 'Rules'
		;
QUERIES		: 'Queries'
		;

ID  :	('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'0'..'9')*
    ;

STRING
    :  '\'' ( ESC_SEQ | ~('\\'|'\'') )* '\''
    ;

COMMENT
    :   '#' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    |   '#|' ( options {greedy=false;} : . )* '|#' {$channel=HIDDEN;}
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
ESC_SEQ
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UNICODE_ESC
    |   OCTAL_ESC
    ;

fragment
OCTAL_ESC
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UNICODE_ESC
    :   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;
```

### Output Specifications
The Part 2 pass-off requires exactly matching the expected output from the reference solution used by the pass-off script. That means output must exactly match in capitalization, punctuation, whitespace, and order. General spacing and ordering rules are

- Indentation is two spaces
- The ':-' is separated by one space on either side
- Schemes, rules, facts, and queries should be listed in program order (i.e., the order in which they appear in the file)
- The domain should be sorted (e.g., standard std::string order)
- The domain includes only strings that appear in facts

Example inputs with the expected outputs for Part 2 pass-off is in the next section.

### Examples
You program for Part 2 must exactly match the output format in the examples. Note that lines are indented using two spaces, not the tab character. Successful pass-off involves comparing your output to expected output from a reference solution. Any mismatch in your output means the pass-off failed. Further, these examples are not comprehensive in testing your parser. They only are sufficient to define the output format.

#### Example 1
*Input*
```
Schemes:
  snap(S,N,A,P)

#comment

  HasSameAddress(X,Y)

Facts: #comment
  snap('12345','C. Brown','12 Apple','555-1234').
  snap('33333','Snoopy','12 Apple','555-1234').

Rules:
  HasSameAddress(X,Y) :- snap(A,X,B,C),snap(D,Y,B,(E+C)).

#comment

Queries:
  HasSameAddress('Snoopy',Who)?
```

*Output*
```
Success!
Schemes(2):
  snap(S,N,A,P)
  HasSameAddress(X,Y)
Facts(2):
  snap('12345','C. Brown','12 Apple','555-1234').
  snap('33333','Snoopy','12 Apple','555-1234').
Rules(1):
  HasSameAddress(X,Y) :- snap(A,X,B,C),snap(D,Y,B,(E+C)).
Queries(1):
  HasSameAddress('Snoopy',Who)?
Domain(6):
  '12 Apple'
  '12345'
  '33333'
  '555-1234'
  'C. Brown'
  'Snoopy'
```

#### Example 2
*Input*
```
Schemes:
    snap(S,N,A,P)
    NameHasID(N,S)

Facts:
    snap('12345','C. Brown','12 Apple','555-1234').
    snap('67890','L. Van Pelt','34 Pear','555-5678').

Rules:
    NameHasID(N,S) :- snap(S,N,A,P)?

Queries:
    NameHasID('Snoopy',Id)?
```

*Output*
```
Failure!
  (Q_MARK,"?",10)
```

### FAQ
*Why is the grammar notation different than class or the book?*

The grammar is in the ANTLR format. ANTLR is a tool that takes a grammar specification like the one on this webpage and automatically turns it into a lexical analyzer and parser for several different output languages. The key changes are this: the '|' character is used to separate different rules for a given non-terminal rather than a new line (much like BNF); non-terminals are lowercase; terminals are upper-case; if something is not separated by the '|' character, then it is part of the same rule (see the first rule for for the datalog program example); and the first rule is the start rule.

*What do I have to change in my Lexical Analyzer?*

The lexical analyzer needs to give the parser tokens. The parser also needs to be able to determine the type of the token too (i.e., STRING, COMMA, PERIOD, etc.). The analyzer may need to change to include the ability to give the parser tokens for analysis.

*Why do we need the Parameter, Predicate, Rule, and Datalog Program classes, and what should be in these classes?*

Each lab projects builds on the previous project. These classes are intended to support the next project. To determine what needs to be in each of these classes, use the grammar as a guide. For example, a parameter is defined as STRING | ID | expression. A such, the parameter class should be able to look like a STRING, ID, or expression, and a method should exist to determine the type of parameter. As another example, A predicate is defined as ID LEFT_PAREN parameter parameterList RIGHT_PAREN. A class to represent a predicate needs to store the ID, and a list of parameters. Other classes are defined similarly: guided by the grammar.

As a further point of clarification, the datalog program has a list for schemes, facts, rules, and queries. It is allowable to build new classes for a scheme or query; however, the predicate class does suffice to represent these objects—they have a common structure and the predicate is more general so it includes what is needed for the schemes and queries.

*What strings need to be included in the domain?*

The domain consists of all strings found in the facts. It does not include strings in the rules or queries.

*How should I represent an expression?*

Use polymorphism! An expression is a parameter. That parameter has an operator with a left parameter and a right parameter. It is possible to define different types of parameters using polymorphism: an ID parameter, a STRING parameter, and an expression parameter that has an operator with a left parameter and a right parameter. Such a structure makes expressions, even arbitrarily nested expressions, trivial.

*How should I print expressions?*

Print expression exactly how they look on the input: left parameter operator right parameter. Remember the left or the right parameter can be either or both expressions. No problem! It is possible to have a to_string method for each type of parameter using polymorphism. That way, printing is easy: just call to_string() on the parameter, and the to_string method knows how to do the rest (i.e., if it is an expression, it first calls left.to_string(), add the operator, and then calls right.to_string().

*What is the easiest way to handle a parse error?*

The most direct way to handle a parse error is with an exception. A parse error is able to throw the offending token. And the caller of the parser is able to catch the same token and provide the required output.

### Submission
Review the project standards for creating a zip archive.

Navigate to Learning Suite, select 'CS 236', and click on 'Assignments' on the course home page. Click on the link to the relevant project and at the bottom of the description click on 'View/Submit'. Use the resulting upload dialog to upload your zip archive.

### Pass-off
Pass-off your project directly to a TA during normal TA hours. TAs help students on a first-come/first-serve basis and are under no obligation to stay later than designated hours so plan accordingly. Please review the syllabus and the project standards for the pass-off requirements.

[Back to Top](#datalog-parser-cs236-byu)
