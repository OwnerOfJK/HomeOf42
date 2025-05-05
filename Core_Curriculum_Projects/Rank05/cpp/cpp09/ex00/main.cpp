#include "include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }
    BitcoinExchange bitcoinExchange;
    bitcoinExchange.readInputFile(argv[1]);
    bitcoinExchange.readDataBase();
    bitcoinExchange.printInputValues();
    return 0;
}