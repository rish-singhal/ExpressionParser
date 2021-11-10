//
// Created by rishabh singhal on 08/11/21.
//
#include "Status.h"

#include <iostream>

using namespace std;

namespace expressionParser
{

bool Status::isError() const
{
    return m_type == Type::Error;
}

void Status::printMessage() const
{
    if (isError())
        cout << "ERROR: " << m_message << "\n";
    else
        cout << "STATUS OK: " << m_message << "\n";
}

} // namespace expressionParser
