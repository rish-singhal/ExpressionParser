//
// Created by rishabh singhal on 09/11/21.
//

#pragma once

#include "../lib/Status.h"

#include <string>
#include <utility>

namespace expressionParser
{

class Solver
{
public:
    explicit Solver(std::string  const& _expression)
        : expression(_expression) {}

    Status solve(double* value);

private:
    const std::string expression;
};

}  // namespace expressionParser
