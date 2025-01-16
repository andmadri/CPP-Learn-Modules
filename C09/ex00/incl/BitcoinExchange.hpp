#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange {
private:
    BitcoinExchange() = default;

    std::map<std::string, float> m_dates_prices;
    std::string m_date;
    std::string m_value_s;
    float m_value_f;

    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    bool splitString(const std::string& str);
    void readDataBase();
    void findLowestDate();

    void printPrice(float price);

public:
    static void processInputFile(std::ifstream& InputFile);
};

#endif