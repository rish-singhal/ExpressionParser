#include <iostream>
#include <string>

#include "Solver.h"
#include "../tests/TestSolver.h"

using namespace std;

int main()
{
    string expression;
    while (true)
    {
        cout << "> ";
        getline(cin, expression);
        if (expression == "exit")
            break;
        else if (expression == "test")
        {
            auto test_solver = expressionParser::TestSolver();
            test_solver.test_all();
        }
        else
        {
            auto solver = expressionParser::Solver(expression);
            double value = 0.0;
            expressionParser::Status status = solver.solve(&value);
            if (status.isError())
            {
                status.printMessage();
                continue;
            }
            cout << value << "\n";
        }
    }
    return 0;
}
