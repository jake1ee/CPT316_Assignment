#include "Function.h"

int main()
{
    // declaring a demo array
    char value[100];
    vector<char*> tokens;

    cout << "Enter a String: ";
    cin.getline(value, 100);

    Tokenization(value, tokens);
    for (auto i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i];

        if (isNumber(tokens[i]))
        {
            cout << " Is a Value" << endl;
        }
        else if (isOperator(tokens[i]))
        {
            cout << " Is a Operator" << endl;
        }
        else
        {
            cout << " Not accepted" << endl;
        }
    }

    cout << SyntaxAnalyzer(tokens);

    return 0;
}