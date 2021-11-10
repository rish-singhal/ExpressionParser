//
// Created by rishabh singhal on 08/11/21.
//

#pragma once

#include <string>
#include <utility>

namespace expressionParser {

class Status {
public:
    enum class Type
    {
        Ok = 0,
        Error /*= 1*/
    };

    explicit Status(Type const& _type): m_type(_type), m_message() {}

    Status(Type const& _type, std::string const& _message)
        : m_type(_type),
          m_message(_message) {}

    [[nodiscard]] bool isError() const;

    void printMessage() const;

private:
    Type m_type;
    std::string m_message;
};

} // namespace expressionParser
