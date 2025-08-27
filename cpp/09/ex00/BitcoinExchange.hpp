#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#define MAX 2147483647
#define BAD_INPUT "Mauvais nombre d'argument, Use :  ./btc input.txt"
#define ERR_OPN_FILE "Error: Failed to open file."
#define ERR_HEAD_FILE "Error: First line of file is not 'date | value'."
#define ERR_BAD_INPUT_PIPE "Error: bad input => "
#define ERR_BAD_DATE "Error: bad input => "
#define ERR_NEG_NB "Error: not a positive number."
#define ERR_BIG_NB "Error: too large a number."
#define ERR_DASH_DATE "Error : format dash date"
#define ERR_DATE_YEAR "Error : date is before 2009"

std::map<std::string, double> readData();
std::string dayBack(const std::string& date);
std::string trim(const std::string& str);
double findRate(const std::string& date, const std::map<std::string, double>& data);
void checkInput(const char *file, const std::map<std::string, double>& data);
void printMap(const std::map<std::string, double>& myMap);
bool validDate(const std::string& date);
bool validValue(const std::string& value);

#endif