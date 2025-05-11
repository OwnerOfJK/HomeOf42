#include "../include/RPN.hpp"

void RPN::iterateString() {
    int strlen = input.length();
    for (int i = 0; i < strlen; ++i) {
        if (std::isdigit(input[i])) {
            stack.push_back(input[i] - '0');
        }
        else if (isOperator(input[i])) {
            if (stack.size() < 2) {
                std::cout << "Error: not enough operands for operator '" << input[i] << "'" << std::endl;
                return;
            }
            subresult(input[i]);
        }
        else if (!std::isspace(input[i])) {
            std::cout << "Error: invalid character '" << input[i] << "'" << std::endl;
            return;
        }
    }
    if (stack.size() == 1) {
        std::cout << "Result: " << stack.back() << std::endl;
    } else {
        std::cout << "Error: invalid RPN expression." << std::endl;
    }
}

bool RPN::isOperator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

void RPN::subresult(char op) {
    try {
        int result = popTwoAndOperate(op);
        stack.push_back(result);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        stack.clear();
    }
}

int RPN::popTwoAndOperate(char op) {
    int b = stack.back(); stack.pop_back();
    int a = stack.back(); stack.pop_back();
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("division by zero");
            return a / b;
        default:
            throw std::runtime_error("unknown operator");
    }
}