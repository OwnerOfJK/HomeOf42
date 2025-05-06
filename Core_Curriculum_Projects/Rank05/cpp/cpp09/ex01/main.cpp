#include "include/RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        return 0;
    }
    RPN rpn(argv[1]);
    rpn.iterateString();
}