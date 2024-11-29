#include <gtest.h>
#include <iostream>
#include "translator.h"
using namespace std;

int main(int argc, char **argv) {
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();

    //////////////////////INPUT EXPRESSION//////////////////////
    string input;
    cout << "Enter expression: \n";
    cin >> input;

    Arithmetic_Expression expr(input);
    ////////////////////////////////////////////////////////////

    //////////////////////RETURNING INFIX FORM//////////////////
    cout << expr.GetInfix() << endl;
    ////////////////////////////////////////////////////////////
    
    //////////////////////RETURNING POSTFIX FORM////////////////
    vector<string> postfix = expr.GetPostfix();
    for (int i = 0; i < postfix.size(); ++i) {
        std::cout << postfix[i];
    }
    std::cout << std::endl;
    ////////////////////////////////////////////////////////////

    //////////////////////GETTING OPERANDS VALUE////////////////
    vector<string> operands = expr.GetOperands();
    map<string, double> values;
    double val;

    for (const auto& op : operands) {
        if (!isNumber(op)) {
            cout << "Input value of operand " << op << endl;
            cin >> val;
            values[op] = val;
        }
    }
    ////////////////////////////////////////////////////////////
     
    //////////////////////CALCULATING///////////////////////////
    cout<<"Answer: " << expr.Calculate(values) << endl;
    ////////////////////////////////////////////////////////////

    return 0;
}
