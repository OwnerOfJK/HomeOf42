#include "include/RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return 0;
    }
    RPN rpn(argv[1]);
    rpn.iterateString();
}