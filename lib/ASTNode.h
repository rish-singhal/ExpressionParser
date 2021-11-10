//
// Created by rishabh singhal on 09/11/21.
//

#pragma once

#include "Token.h"

namespace expressionParser
{

struct ASTNode
{
    Token token;
    ASTNode* leftChild;
    ASTNode* rightChild;

    explicit ASTNode()
        : token(Token(Token::Type::Invalid)),
          leftChild(nullptr),
          rightChild(nullptr) {}

    explicit ASTNode(Token const& _token)
        : token(_token),
          leftChild(nullptr),
          rightChild(nullptr) {}

    explicit ASTNode(ASTNode* _node)
            : token(Token(_node->token)),
              leftChild(_node->leftChild),
              rightChild(_node->rightChild) {}

    [[nodiscard]] bool isDigitNode() const
    {
      return token.isDigit();
    }

    [[nodiscard]] bool isOperatorNode() const
    {
      return token.isOpt();
    }

    void copy(ASTNode* node)
    {
      token.copy(node->token);
      leftChild = node->leftChild;
      rightChild = node->rightChild;
    }
};

} // namespace expressionParser
