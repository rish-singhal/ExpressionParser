# Expression Parser

The Expression Parser is a CLI tool which supports arithmetic expressions
which consists of digits `0-9` and binary operations `+, *, /, -`
with support for `parentheses` and error handling.

## Instructions

To run the Expression Parser CLI tool follow these steps:
```bash
$ cd cmake-build-debug
$ make all
$ ./parser
> 1 + 1
2
```

To run tests give `test` as an input to CLI:
```bash
$ ./parser
> test
```

To exit give `exit` as an input to CLI:
```bash
$ ./parser
> exit
$
```

**Sample Run:**
```bash
> (1 + 2) * 3
Output: 9

> 1 + 2 * 3
Output: 7

> 11
Output: ERROR: Input contains invalid factor,
the parser supports only single digit numbers (0-9)

> 1 + 1 - 3
Output: -1 

> (1 + 2 - 1) / 3 + 2
Output: 2.66667

> (1 + 3
Output: ERROR: Input contains unbalanced parenthesis
```

### Directory Structure

```bash
.
├── CMakeLists.txt
├── README.md
├── lib
│   ├── AST.cpp
│   ├── AST.h
│   ├── ASTNode.h
│   ├── Constants.h
│   ├── Lexer.cpp
│   ├── Lexer.h
│   ├── Parser.cpp
│   ├── Parser.h
│   ├── Status.cpp
│   ├── Status.h
│   ├── Token.cpp
│   └── Token.h
├── src
.   ├── Solver.cpp
    ├── Solver.h
    └── main.cpp
```

## Implementation Details

```bash

.INPUT. --> [LEXER]
              |
          Tokens List
              |
               -> [PARSER] -- AST --> [AST CLASS]
                                          |
                                       .OUTPUT.
```

Errors are handled at each step and a `Status Class` is
implemented with two possible `Types` and corresponding `message`
as class members:
1. `Status::Type::Ok`
2. `Status::Type::Error`

### Abstract Syntax Tree 

`AbstractSyntaxTree` class also implements a print method which prints out the
Abstract Tree  output from the `Parser` as an inorder traversal.

### Grammar for the Parser
```
expr : term ((PLUS|MINUS) term)*
term : factor ((MUL|DIV) factor)*
factor : DIGIT "0-9"
       : LPAREN expr RPAREN
```

## Author

[Rishabh Singhal](https://rish-singhal.github.io)
