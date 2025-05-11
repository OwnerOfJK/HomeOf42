#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cmath>

#include "Utils.hpp"

class BitcoinExchange {
    private:
        struct Date {
            double year;
            double month;
            double day;
            Date(double y, double m, double d) : year(y), month(m), day(d) {}
            bool operator<(const Date &other) const {
                if (year != other.year)
                    return year < other.year;
                if (month != other.month)
                    return month < other.month;
                return day < other.day;
            }
            bool operator>(const Date &other) const {
                if (year != other.year)
                    return year > other.year;
                if (month != other.month)
                    return month > other.month;
                return day > other.day;
            }
            bool operator==(const Date &other) const {
                return year == other.year && month == other.month && day == other.day;
            }
            bool operator!=(const Date &other) const {
                return !(*this == other);
            }
            friend std::ostream &operator<<(std::ostream &os, const Date &date) {
                os << date.year << "-" << date.month << "-" << date.day;
                return os;
            }
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
        void printMap(std::multimap<Date, double> &m) const;
};

#endif