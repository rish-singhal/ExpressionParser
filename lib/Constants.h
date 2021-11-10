//
// Created by rishabh singhal on 08/11/21.
//

#pragma once

namespace expressionParser {

namespace parserConstants
{
    static const char INVALID_CHAR = '\0';
    static const char SPACE_CHAR = ' ';
} // namespace parserConstants

namespace errorMessages
{
    static const char* INVALID_CHARACTER = \
       "Input contains at least one invalid character";
    static const char* UNBALANCED_PARENTHESIS = \
       "Input contains unbalanced parenthesis";
    static const char* INVALID_FACTOR  = \
       "Input contains invalid factor, the parser supports "
       "only single digit numbers (0-9)";
    static const char* INVALID_SYNTAX  = \
       "Input contains invalid factor, the parser supports "
       "only single digit numbers (0-9)";
    static const char* EMPTY_TOKENS  = \
       "Input is empty";
}  // namespace errorMessages

} // namespace expressionParser
