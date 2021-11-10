//
// Created by rishabh singhal on 09/11/21.
//

#include "Parser.h"

using namespace std;

namespace expressionParser {

Status Parser::advance()
{
    m_position += 1;
    if (m_position >= (int) tokens.size())
        return Status(Status::Type::Error, "syntax error");
    return Status(Status::Type::Ok);
}

Status Parser::factor(ASTNode* currentNode)
{
    // factor: DIGIT | LPAREN expr RPAREN
    assert(m_position < (int) tokens.size());

    if (tokens[m_position].isDigit())
    {
        auto* tempNode = new ASTNode(Token(tokens[m_position]));
        currentNode->copy(tempNode);
        Status status = advance();
        if (status.isError())
            return status;
        return Status(Status::Type::Ok);
    }
    else if (tokens[m_position].getType() == Token::Type::ParenLeft)
    {
        Status status = advance();
        if (status.isError()) {
            return status;
        }

        status = expr(currentNode);
        if (status.isError()) {
            return status;
        }

        if (tokens[m_position].getType() == Token::Type::ParenRight) {
            status = advance();
            if (status.isError()) {
                return status;
            }
            return Status(Status::Type::Ok);
        }
        else
            return Status(
                    Status::Type::Error,
                    errorMessages::UNBALANCED_PARENTHESIS);
    }

    return Status(Status::Type::Error, errorMessages::INVALID_FACTOR);
}

Status Parser::term(ASTNode* currentNode)
{
    // term : factor ((MUL|DIV) factor)*
    auto* leftNode = new ASTNode();
    Status status = factor(leftNode);
    if (status.isError())
        return status;

    assert(leftNode != nullptr);
    assert(m_position < (int) tokens.size());

    while (tokens[m_position].getType() == Token::Type::Multiply
        || tokens[m_position].getType() == Token::Type::Divide)
    {
        auto* tempNode = new ASTNode(Token(tokens[m_position]));

        tempNode->leftChild = new ASTNode(leftNode);

        Status status = advance();
        if (status.isError())
            return status;

        auto* rightNode = new ASTNode();
        status = factor(rightNode);
        if (status.isError())
            return status;

        tempNode->rightChild = new ASTNode(rightNode);
        leftNode->copy(tempNode);
    }

    currentNode->copy(leftNode);
    return Status(Status::Type::Ok);
}

Status Parser::expr(ASTNode* currentNode)
{
    // expr : term ((PLUS|MINUS) term)* EOF

    assert(m_position < (int) tokens.size());

    if (tokens[m_position].getType() == Token::Type::EndOfFile)
    {
        return Status(Status::Type::Ok);
    }

    auto* leftNode = new ASTNode();;
    Status status = term(leftNode);
    if (status.isError())
    {
        return status;
    }

    assert(leftNode != nullptr);

    while (tokens[m_position].getType() == Token::Type::Plus
           || tokens[m_position].getType() == Token::Type::Minus)
    {
        auto* tempNode = new ASTNode(Token(tokens[m_position]));
        tempNode->leftChild = new ASTNode(leftNode);

        Status status = advance();
        if (status.isError())
            return status;

        auto* rightNode = new ASTNode();
        status = term(rightNode);
        if (status.isError())
            return status;

        tempNode->rightChild = new ASTNode(rightNode);
        leftNode->copy(tempNode);
    }

    currentNode->copy(leftNode);
    return Status(Status::Type::Ok);
}

Status Parser::createTree(ASTNode* head)
{
    if ((int) tokens.size() <= 1)
        return Status(
                Status::Type::Error,
                errorMessages::EMPTY_TOKENS);

    Status status = advance();
    if (status.isError())
        return status;

    status = expr(head);

    if (status.isError())
        return status;

    if (tokens[m_position].getType() != Token::Type::EndOfFile)
        return Status(Status::Type::Error, errorMessages::INVALID_SYNTAX);

    return Status(Status::Type::Ok);
}

} // namespace expressionParser
