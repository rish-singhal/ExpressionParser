//
// Created by rishabh singhal on 10/11/21.
//

#include <string>

namespace expressionParser
{

class TestSolver
{
public:
    TestSolver() {}

    void test_all() const;

    void test
         (
         std::string const& inputExpression,
         double const& expectedOutput,
         bool const& isError
         ) const;
};

}


