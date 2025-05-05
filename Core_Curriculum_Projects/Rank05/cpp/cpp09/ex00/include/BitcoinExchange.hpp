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
        std::multimap<Date, double> inputFile;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        ~BitcoinExchange();

        void readDataBase();
        void readInputFile(std::string filename);
        void addToDataBase(std::string date, double value, bool isInput);
        void printInputValues();

        void printMap(std::multimap<Date, double> &m) const
        {
            std::multimap<Date, double>::const_iterator it;
            std::cout << "Key\tValue" << std::endl;
            for (it = m.begin(); it != m.end(); ++it) {
                std::cout << it->first << "\t" << it->second << std::endl;
            }
        }
};

#endif