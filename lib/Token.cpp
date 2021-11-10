/*
 Created by rishabh singhal on 08/11/21.
*/

#include "Token.h"

using namespace std;

namespace expressionParser {

const string Token::allowedTypes = "+-*/()";

bool Token::isDigit() const
{
    return type == Type::Digit;
};

bool Token::isParenthesis() const
{
    return type == Type::ParenLeft || type == Type::ParenRight;
}

bool Token::isOpt() const
{
    return !isDigit()
           && !isParenthesis()
           && type != Type::Invalid
           && type != Type::EndOfFile;
}

char Token::getValue() const
{
    return value;
}

Token::Type Token::getType() const
{
    return type;
}

void Token::copy(Token const& token)
{
    type = token.type;
    value = token.value;
}

} // namespace expressionParser
