#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <deque>
#include <cctype>
#include <stdexcept>

class RPN {
    private:
        std::string input;
        std::deque<int> stack;

    public:
        RPN(std::string _input) : input(_input) {}
        ~RPN() {}
        void iterateString();

    private:
        bool isOperator(char op);
        void subresult(char op);
        int popTwoAndOperate(char op);
};

#endif