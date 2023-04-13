#include <iostream>
#include <stack>
#include <map>

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int precedence(char op) {
    std::map<char, int> precedenceMap = {
        {'+', 1}, {'-', 1},
        {'*', 2}, {'/', 2},
        {'^', 3}
    };
    return precedenceMap[op];
}

std::string infixToPostfix(const std::string& infixExpression) {
    std::string postfixExpression;
    std::stack<char> operatorStack;

    for (char ch : infixExpression) {
        if (isalnum(ch)) {
            postfixExpression += ch;
        } else if (ch == '(') {
            operatorStack.push(ch);
        } else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop(); // Pop the '('
            }
        } else if (isOperator(ch)) {
            while (!operatorStack.empty() && operatorStack.top() != '(' && precedence(operatorStack.top()) >= precedence(ch)) {
                postfixExpression += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.empty()) {
        postfixExpression += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExpression;
}

int main() {
    std::string infix = "a+b*c-(d/e+f)^g";
    std::string postfix = infixToPostfix(infix);

    std::cout << "Infix Expression: " << infix << std::endl;
    std::cout << "Postfix Expression: " << postfix << std::endl;

    return 0;
}
