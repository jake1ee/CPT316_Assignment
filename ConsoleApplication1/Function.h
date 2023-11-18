#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

vector<char*> Tokenization(char input[], vector<char*>& v)
{
    // initializing a character pointer
    char* ptr = strtok(input, " ");

    // looping over and storing successively
    while (ptr != nullptr)
    {
        v.push_back(ptr);
        ptr = strtok(nullptr, " ");
    }

    return v;
}

// Function to check if the current token is a  (  or  ) 
bool isParenthesis(char* ch) {
    return *ch == '(' || *ch == ')';
}

//check if the given character is an operator or not
bool isOperator(char* ch)
{
    int len = strlen(ch);
    if (len > 1)
        return false;

    if (*ch == '+' || *ch == '-' || *ch == '*' ||
        *ch == '/' )
    {
        return true;
    }
    return false;
}

//check if the given substring is a number/decimal number or not
bool isNumber(char* str)
{
    int i, len = strlen(str), numOfDecimal = 0;
    if (len == 0)
    {
        return false;
    }

    // Allow a '-' sign at the beginning
    if (str[0] == '-')
    {
        // If there is only a '-' sign, it's not a valid number
        if (len == 1)
            return false;

        // Start checking from the second character
        i = 1;
    }
    else
    {
        i = 0;
    }

    for (; i < len; i++)
    {
        if (str[i] == '.')
        {
            numOfDecimal++;
        }

        if ((str[i] > '9' || str[i] < '0') && str[i] != '.')
        {
            return false;
        }
    }

    if (numOfDecimal > 1 || str[0] == '.' || str[len - 1] == '.')
        return false;

    return true;
}
// Function to parse an expression based on the grammar rules
bool expr(vector<char*>::iterator& it, vector<char*>::iterator end) {

    if (it == end) {
        cout << "Error: Unexpected end of expression." << endl;
        return false;
    }

    // expr ->  -  expr
    if (**it == '-' && isOperator(*it)) {
        it++; // Consume the  - 
        if ( it != end && (**it != '-' && isOperator(*it))) {
            cout << "Error: Invalid use of negative sign or operator." << endl;
            return false;
        }
        return expr(it, end);
    }

    // expr ->  (  expr  ) 
    if (**it == '(') {
        it++; // Consume the  ( 
        if (!expr(it, end)) return false;
        if (it == end || **it != ')') {
            cout << "Error: Unmatched parentheses." << endl;
            return false; // Missing  ) 
        }
        it++; // Consume the  ) 
        if (it != end && isOperator(*it)) {
            // expr -> expr op expr
            it++; // Consume the operator
            return expr(it, end);
        }
        return true;
    }

    // expr -> id
    if (isNumber(*it)) {

        if (**it == '-' && isOperator(*it))
        {
            it++; // Consume the  - 
            if (**it == '-') return false;
            return expr(it, end);
        }

        it++; // Consume the id

        if (it != end && isOperator(*it)) {
            // expr -> expr op exprexpr
            it++; // Consume the operator
            if (it != end && (**it == ')' || isOperator(*it))) {
                cout << "Error: Invalid expression after operator." << endl;
                return false;
            }
            return expr(it, end);
        }
        else if (it != end && isNumber(*it))
        {
            cout << "Error: Invalid expression after number." << endl;
            return false;
        }
        else {
            return true; // No more tokens or next token is not an operator
        }
    }

    return false; // Token is not an identifier or a valid expression
}

// Function to initiate the syntax analyzer
bool SyntaxAnalyzer(vector<char*>& tokens) {
    auto it = tokens.begin();
    return expr(it, tokens.end()) && it == tokens.end();
}
