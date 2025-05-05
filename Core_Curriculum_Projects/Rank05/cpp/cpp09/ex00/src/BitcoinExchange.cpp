#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "Default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        return *this;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "Destructor called" << std::endl;
}

void BitcoinExchange::addToDataBase(std::string date, double value, bool isInput)
{
    std::istringstream date_stream(date);
    std::string year_str, month_str, day_str;
    if (!std::getline(date_stream, year_str, '-') ||
        !std::getline(date_stream, month_str, '-') ||
        !std::getline(date_stream, day_str, '-'))
    {
        std::cerr << "Error: invalid date format => " << date << std::endl;
        return;
    }

    double year, month, day;
    stringToInt(year_str, year);
    stringToInt(month_str, month);
    stringToInt(day_str, day);
    if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
    {
        std::cerr << "Error: invalid date => " << date << std::endl;
        return;
    }

    Date timestamp(year, month, day);
    if (isInput)
        inputFile.insert(std::make_pair(timestamp, value));
    else
        dataBase[timestamp] = value;
}

void BitcoinExchange::readDataBase()
{
    std::ifstream file("assets/data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open data.csv" << std::endl;
        return;
    }

    std::cout << "\nChecking for error in csv database..." << std::endl;
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == 'd')
            continue;

        std::istringstream line_stream(line);
        std::string date, value_str;

        if (!std::getline(line_stream, date, ',') || !std::getline(line_stream, value_str))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        try {
            stringToInt(value_str, value);
            if (value < 0) throw std::invalid_argument("Negative");
        } catch (...) {
            std::cerr << "Error: invalid value => " << value_str << std::endl;
            continue;
        }

        addToDataBase(date, value, 0);
    }

    file.close();
}

void BitcoinExchange::readInputFile(std::string path)
{
    std::ifstream file(path.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open input.txt" << std::endl;
        return;
    }

    std::cout << "\nChecking for error in input file..." << std::endl;
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == 'd')
            continue;

        std::istringstream line_stream(line);
        std::string date, pipe, value_str;
        if (!(line_stream >> date >> pipe >> value_str) || pipe != "|")
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        try {
            stringToInt(value_str, value);
            if (value < 0) throw std::invalid_argument("Negative");
            if (value > 1000) throw std::invalid_argument("Too high");
        } catch (...) {
            std::cerr << "Error: invalid value => " << value_str << std::endl;
            continue;
        }

        addToDataBase(date, value, 1);
    }

    file.close();
}


void BitcoinExchange::printInputValues()
{
    std::cout << "\nPrinting values..." << std::endl;
    std::cout << "Date | Value" << std::endl;

    std::multimap<Date, double>::const_iterator it;
    for (it = inputFile.begin(); it != inputFile.end(); ++it) {
        const Date& inputDate = it->first;
        double inputValue = it->second;
        std::map<Date, double>::const_iterator dbIt = dataBase.find(inputDate);
        if (dbIt == dataBase.end()) {
            continue;
        }
        double dataBaseValue = dbIt->second;
        double result = std::ceil((inputValue * dataBaseValue) * 100.0) / 100.0;
        std::cout << inputDate << " => " << inputValue
                  << " = " << result << std::endl;
    }
    std::cout << "All values computed...\n" << std::endl;
}


