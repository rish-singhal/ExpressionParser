//
// Created by rishabh singhal on 09/11/21.
//

#include "../lib/Lexer.h"
#include "../lib/Parser.h"
#include "../lib/AST.h"

#include "Solver.h"

#include <vector>

using namespace std;

namespace expressionParser
{

Status Solver::solve(double* value)
{
  // Lexer part for tokenizing expression
  // e.g. input: (1 +  3) - 4
  //      output: ['(', '1', '+', '3', ')', '-', '4']
  auto lexer = Lexer(expression);
  vector<Token> tokens;

  Status status = lexer.parseTokens(&tokens);
  if (status.isError())
      return status;

  // Parse the token list to Abstract Syntax Tree DS
  auto parser = Parser(tokens);
  auto* headNode = new ASTNode();
  status = parser.createTree(headNode);
  if (status.isError())
      return status;

  // Evaluate the Abstract Syntax Tree DS
  auto abstractSyntaxTree = AbstractSyntaxTree(headNode);
  *value = abstractSyntaxTree.evaluate();

  return Status(Status::Type::Ok);
}

}  // namespace expressionParser
