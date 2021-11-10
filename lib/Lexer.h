/*
 Created by Rishabh Singhal on 08/11/21.
*/

#pragma once

#include "Token.h"
#include "Status.h"

#include <string>
#include <vector>

namespace expressionParser
{

class Lexer
{
public:
    explicit Lexer(std::string const& _expression);

    void advance();

    Status parseTokens(std::vector<Token>* tokens);

private:
    const std::string expression;
    uint32_t m_position;
    char m_current_char;
};

} // namespace expressionParser
