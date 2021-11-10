//
// Created by rishabh singhal on 09/11/21.
//

#include "AST.h"
#include "Token.h"

using namespace std;

namespace expressionParser {

double AbstractSyntaxTree::evaluate(ASTNode* currentNode) const
{
    if (currentNode == nullptr)
        return 0.0;
    else if (currentNode->isDigitNode())
    {
        char dig = currentNode->token.getValue();
        assert('0' <= dig && dig <= '9');
        return (double) (dig - '0');
    }

    assert(currentNode->isOperatorNode());

    double leftValue  = evaluate(currentNode->leftChild);
    double rightValue = evaluate(currentNode->rightChild);
    Token::Type opt = currentNode->token.getType();

    if (opt == Token::Type::Plus)
        return leftValue + rightValue;
    else if (opt == Token::Type::Minus)
        return leftValue - rightValue;
    else if (opt == Token::Type::Multiply)
        return leftValue * rightValue;
    else if (opt == Token::Type::Divide)
        return leftValue / rightValue;

    assert(false);
}

double AbstractSyntaxTree::evaluate() const
{
    return evaluate(m_rootNode);
}

void AbstractSyntaxTree::printTree(ASTNode *currentNode) const
{
    if (currentNode == nullptr)
        return;
    else if (currentNode->isDigitNode())
    {
        char dig = currentNode->token.getValue();
        assert('0' <= dig && dig <= '9');
        cout << (int) (dig - '0');
        return;
    }

    assert(currentNode->isOperatorNode());

    cout << "[ ";
    printTree(currentNode->leftChild);
    cout << " " << static_cast<char> (currentNode->token.getType()) << " ";
    printTree(currentNode->rightChild);
    cout << " ]";
}

void AbstractSyntaxTree::print() const
{
    std::cout << "[ ";
    printTree(m_rootNode);
    std::cout << " ]" << std::endl;
}

} // namespace expressionParser
