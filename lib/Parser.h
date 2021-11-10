//
// Created by rishabh singhal on 09/11/21.
//

#pragma once

#include <utility>
#include <vector>

#include "ASTNode.h"
#include "Status.h"

namespace expressionParser
{

class Parser {
public:
    explicit Parser(std::vector<Token> const& _tokens)
        : tokens(_tokens),
          m_position(/*Initial Position=*/-1) {}

    Status advance();

    Status factor(ASTNode* currentNode);

    Status term(ASTNode* currentNode);

    Status expr(ASTNode* currentNode);

    Status createTree(ASTNode* head);

private:
    const std::vector<Token> tokens;
    uint32_t m_position;
};

}
