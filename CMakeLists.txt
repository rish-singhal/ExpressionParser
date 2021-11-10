cmake_minimum_required(VERSION 3.20)
project(parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(parser src/main.cpp lib/Token.cpp lib/Token.h lib/Lexer.cpp lib/Lexer.h lib/Constants.h lib/Status.cpp lib/Status.h src/Solver.cpp src/Solver.h lib/AST.cpp lib/AST.h lib/ASTNode.h lib/Parser.cpp lib/Parser.h tests/TestSolver.cpp tests/TestSolver.h tests/TestSolver.cpp tests/TestSolver.h)
