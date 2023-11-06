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

        if ((str[i] == '-' && i >= 1) || ((str[i] > '9' || str[i] < '0') && str[i] != '-' && str[i] != '.'))
        {
            return false;
        }
    }

    if (numOfDecimal > 1 || str[0] == '.' || str[len - 1] == '.')
        return false;

    return true;
}

//parse the expression
bool SyntaxAnalyzer(vector<char*>& tokens)
{
    if (isOperator(tokens[0]) || isOperator(tokens[tokens.size() - 1]))
        return false;

    for (int i = 0; i < tokens.size() - 1; i++)
    {
        if (isOperator(tokens[i]) && isOperator(tokens[i + 1]) || (isNumber(tokens[i]) && isNumber(tokens[i + 1])))
            return false;
    }

    return true;
}