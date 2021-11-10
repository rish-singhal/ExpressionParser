/*
 Created by rishabh singhal on 08/11/21.
*/

#include "Lexer.h"

#include <utility>

using namespace std;

namespace expressionParser
{

    Lexer::Lexer(string const& _expression)
    : expression(_expression),
      m_position(/*Initial Position=*/-1),
      m_current_char(parserConstants::INVALID_CHAR)
{
  advance();
}

void Lexer::advance()
{
    m_position += 1;
    if (m_position < (int) expression.size())
        m_current_char = expression[m_position];
    else
        m_current_char = parserConstants::INVALID_CHAR;
}

Status Lexer::parseTokens(vector<Token>* tokens)
{
    assert(tokens->empty());

    while (m_current_char != parserConstants::INVALID_CHAR) {
        if (isdigit(m_current_char))
            tokens->emplace_back(Token::Type::Digit, m_current_char);
        else if (Token::allowedTypes.find(m_current_char) != string::npos)
        {
            auto type = static_cast<Token::Type> (m_current_char);
            tokens->emplace_back(type, m_current_char);
        }
        else if (m_current_char != parserConstants::SPACE_CHAR)
            return Status(
                    Status::Type::Error,
                    errorMessages::INVALID_CHARACTER
                    );
        advance();
    }

    tokens->emplace_back(Token::Type::EndOfFile, parserConstants::INVALID_CHAR);
    return Status(Status::Type::Ok);
};

} // namespace expressionParser
