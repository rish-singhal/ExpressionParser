//
// Created by rishabh singhal on 10/11/21.
//

#include "../src/Solver.h"

#include "TestSolver.h"

#include <iostream>

using namespace std;

namespace expressionParser {

void TestSolver::test_all() const
{
    test("1 + 1", 2, false);
    test("1 + (2 * 5)", 11, false);
    test("1 * 2 + 5", 7, false);
    test("(1 + 1) * (2 +  5)", 14, false);
    test("1 / (1 + 2) + 3", (double) 3 + (1.0/3), false);
    test("5 - 5 -5", -5, false);
    test("(1) + (2)", 3, false);

    test("(1 + 1", 0, true);
    test("-1", 0, true);
    test("1 + ) * 2", 0, true);
    test("22 + 5x", 0, true);
    test("33", 0, true);
}

void TestSolver::test
        (
        std::string const& inputExpression,
        double const& expectedOutput,
        bool const& isError
        ) const
{
    auto solver = expressionParser::Solver(inputExpression);
    double value = 0.0;
    expressionParser::Status status = solver.solve(&value);

    if (isError)
    {
        if (!status.isError()) {
            cout << "Test Failed on Input: " << inputExpression << "\n"
                 << " :: Expected Output: Error\n\n";
            return;
        }
    }
    else if (value != expectedOutput)
    {
        cout << "Test Failed on Input: " << inputExpression << "\n"
             << " :: Expected Output: " << expectedOutput << "\n"
             << " :: Received Output: " << value << "\n\n";
    }

    cout << "Test Passed on Input: " << inputExpression << "\n";
}

} // namespace expressionSolver

