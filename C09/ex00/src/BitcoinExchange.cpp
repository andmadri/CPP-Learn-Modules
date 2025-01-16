#include "../incl/BitcoinExchange.hpp"

bool BitcoinExchange::isValidValue(const std::string& value) {
   
    try {
        float f = std::stof(value);
        if (f < 0 ) {
			std::cerr << "Error: not a positive number." << std::endl;
            return false;
        } else if (f > 1000) {
			std::cerr << "Error: too large a number" << std::endl;
			return false;
		}
        return true;
    } catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
    return false;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
	
	if (date.length() > 10) {
		std::cerr << "Error: Bad date => " << date << std::endl;
		return false;
	}
	try {
		std::string year = date.substr(0, 4);
		std::string month = date.substr(5, 2);
		std::string day = date.substr(8, 2);
		int y = std::stoi(year);
		int m = std::stoi(month);
		int d = std::stoi(day);

		if (m < 1 || m > 12) {
			std::cerr << "Error: Bad date => " << date << std::endl;
			return false;
		}
		else if (d < 1 || d > 31) {
			std::cerr << "Error: Bad date => " << date << std::endl;
			return false;
		}
		else if (y < 2009 || y > 2022) {
			std::cerr << "Error: Bad date => " << date << std::endl;
			return false;
		}
	} catch (const std::exception& e) { 
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::splitString(const std::string& str) {

    size_t separator = str.find('|');

	try {
		if (separator != std::string::npos) {
			m_date = str.substr(0, separator - 1);
			m_value_s = str.substr(separator + 2);
			if (isValidValue(m_value_s) && isValidDate(m_date)) {
                m_value_f = std::stof(m_value_s);
                return true;
			}
		} else {
            std::cerr << "Error: bad input => " << str << std::endl; 
            return false;
        }
	} catch (const std::exception& e) {}
    return false;
}

void BitcoinExchange::readDataBase() {
    
    std::ifstream database("./data.csv");
    if (!database) {
        std::cerr << "Error: opening data.csv" << std::endl;
        exit(1);
    }

    std::string line;
    if (!std::getline(database, line)) {
        std::cerr << "Error: data.csv is empty" << std::endl;
        exit(1);
    }
    while (std::getline(database, line)) {
        size_t separator = line.find(',');
        if (separator != std::string::npos) {
            try {
                std::string date = line.substr(0, separator);
                std::string value_s = line.substr(separator + 1);
                float value_f = std::stof(value_s);
                this->m_dates_prices[date] = value_f;
            } catch (const std::exception& e) {
                    std::cerr << "Error: processing data.csv" << std::endl;
                    exit (1);
            }
        } else {
            std::cerr << "Error: processing data.csv" << std::endl;
            exit (1);
        }
    }
}

void BitcoinExchange::printPrice(float price) {
    std::cout << m_date << " => " << m_value_s << " = " << m_value_f * price << std::endl;
}

void BitcoinExchange::findLowestDate(){

    auto it = m_dates_prices.lower_bound(m_date);

    if (it->first == m_date) {
        printPrice(it->second);
    } else if (it != m_dates_prices.end() && it != m_dates_prices.begin() && it->first != m_date) {
        --it;
        printPrice(it->second);
    }
}

void BitcoinExchange::processInputFile(std::ifstream& InputFile) {

    std::string input_line;
    BitcoinExchange bts;

    bts.readDataBase();
    if (!std::getline(InputFile, input_line)) {
        std::cerr << "Error: input file is empty" << std::endl;
        exit(1);
    }
    while (std::getline(InputFile, input_line)) {
        if (bts.splitString(input_line)) {
            bts.findLowestDate();
        }
    }
}
