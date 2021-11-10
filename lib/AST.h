//
// Created by rishabh singhal on 09/11/21.
//

#pragma once

#include "ASTNode.h"

#include <iostream>

namespace expressionParser {

class AbstractSyntaxTree {
public:
    explicit AbstractSyntaxTree(ASTNode* _rootNode)
        : m_rootNode(_rootNode) {}

    double evaluate(ASTNode* currentNode) const;

    [[nodiscard]] double evaluate() const;

    void print() const;

    void printTree(ASTNode* currentNode) const;

private:
    ASTNode* m_rootNode;
};

} // namespace expressionParser
