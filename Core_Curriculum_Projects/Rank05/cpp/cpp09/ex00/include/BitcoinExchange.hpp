#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>


#include "Utils.hpp"

class BitcoinExchange {
    private:
        struct Date {
            double year;
            double month;
            double day;
        };
        std::map<Date, double> dataBase;
        std::map<Date, double> inputFile;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void readDataBase();
        void readInputFile(std::string filename);
        void addToDataBase(std::string date, double value, bool isInput);
        void printInputValues();


};

#endif