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

// Function to check if the current token is a ‘(‘ or ‘)’
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
        *ch == '/' || *ch == '=')
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

    for (i = 0; i < len; i++)
    {
        if (str[i] == '.')
        {
            numOfDecimal++;
        }

        if ( (str[0] == '-' && len == 1) || (str[i] == '-' && i >= 1) || ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '.'))
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

    if (it == end) return false; // End of tokens

    // expr -> ‘-’ expr
    if (**it == '-' && !isOperator(*it)) {
        it++; // Consume the ‘-‘
        return expr(it, end);
    }

    // expr -> ‘(’ expr ‘)’
    if (**it == '(') {
        it++; // Consume the ‘(‘
        if (!expr(it, end)) return false;
        if (it == end || **it != ')') return false; // Missing ‘)’
        it++; // Consume the ‘)’
        return true;
    }

    // expr -> id
    if (isNumber(*it)) {
        it++; // Consume the id
        if (it != end && isOperator(*it)) {
            // expr -> expr op exprexpr
            it++; // Consume the operator
            return expr(it, end);
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