/*
 Created by rishabh singhal on 08/11/21.
*/
#pragma once

#include "Constants.h"

#include <string>


namespace expressionParser {

class Token
{
public:
    static const std::string allowedTypes;

    enum class Type
    {
        Digit,
        Invalid,
        EndOfFile,
        Plus = '+',
        Minus = '-',
        Multiply = '*',
        Divide = '/',
        ParenLeft = '(',
        ParenRight = ')',
    };

    explicit Token(Type const& _type)
        : type(_type),
          value(parserConstants::INVALID_CHAR) {}

    explicit Token(Type const& _type, char const& _value)
        : type(_type),
          value(_value) {}

    Token(Token const& token) = default;

    [[nodiscard]] bool isDigit() const;

    [[nodiscard]] bool isParenthesis() const;

    [[nodiscard]] bool isOpt() const;

    [[nodiscard]] char getValue() const;

    [[nodiscard]] Type getType() const;

    void copy(Token const& token);

private:
    Type type;
    char value;
};

} // namespace expressionParser
