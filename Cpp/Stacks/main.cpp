#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int precedence(char &ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    default:
        return -1;
        break;
    }
}

string infixToPostfix(string infix)
{
    Stack<char> aStack;
    string postFixExp = "";
    char top;
    for (char &ch : infix)
    {
        switch (ch)
        {
        case '(':
            aStack.push(ch);
            break;
        case ')':
            aStack.getTop(top);
            while (top != '(')
            {
                postFixExp += top;
                aStack.pop();
                aStack.getTop(top);
            }
            aStack.pop();
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            if (!aStack.isEmpty())
                aStack.getTop(top);
            while (!aStack.isEmpty() && top != '(' && precedence(ch) <= precedence(top))
            {
                postFixExp += top;
                aStack.pop();
                if (!aStack.isEmpty())
                {
                    aStack.getTop(top);
                }
            }
            aStack.push(ch);
            break;
        default:
            postFixExp += ch;
            break;
        }
    }

    while (!aStack.isEmpty())
    {
        char op;
        aStack.pop(op);
        postFixExp += op;
    }

    return postFixExp;
}

int evaluatePostfix(string postfix)
{

    Stack<int> aStack;
    string postFixExp = "";
    int top;
    string operators = "+-/*";
    for (char &ch : postfix)
    {
        if (operators.find(ch) != string::npos)
        {
            aStack.getTop(top);
            int op2 = top;
            aStack.pop();
            aStack.getTop(top);
            int op1 = top;
            aStack.pop();
            int result;
            switch (ch)
            {
            case '*':
                result = op1 * op2;
                break;
            case '+':
                result = op1 + op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '-':
                result = op1 - op2;
                break; 
            default:
                break;
            }
            aStack.push(result);
        }
        else
        {
            int value = ch - '0';
            aStack.push(value);
        }
    }
    aStack.getTop(top);
    return top;
}

int main(int argc, char const *argv[])
{
    string b = infixToPostfix("5-(1+1*2)/1");
    cout << "Postfix Expression: "  << b << endl;
    int result = evaluatePostfix(b);
    cout << result << endl;
    return 0;
}
