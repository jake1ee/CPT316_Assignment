#include "Function.h"

int main()
{
    // declaring a demo array
    char value[100];
    vector<char*> tokens;

    cout << "*\"E\" to terminate the program* \nEnter a String: ";
    cin.getline(value, 100);

    cout << strcmp(value, "E") << endl;

    while (strcmp(value,"E"))
    {
        tokens.clear();

        Tokenization(value, tokens);
        for (auto i = 0; i < tokens.size(); i++)
        {
            cout << tokens[i];

            if (isNumber(tokens[i]))
                cout << " Is a Value" << endl;
            else if (isOperator(tokens[i]))
                cout << " Is an Operator" << endl;
            else if (isParenthesis(tokens[i]))
                cout << " Is a Parenthesis" << endl;
            else
                cout << " Not accepted" << endl;
        }

        cout << (SyntaxAnalyzer(tokens) ? "String Accepted" : "String Rejected") << endl;
        
        system("pause");
        system("cls");

        cout << "*\"E\" to terminate the program* \n Enter a String: ";
        cin.getline(value, 100);

    }
    
    return 0;
}