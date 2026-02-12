#include <cstdlib>
#include <cerrno>
#include <limits>
#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "ScalarConverter.hpp"
#include <cmath>
#include <stdint.h>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cerr << "Empty input\n";
        return;
    }
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: nanf\n";
        std::cout << "double: nan\n";
        return;
    }
    if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: inff\n";
        std::cout << "double: inf\n";
        return;
    }
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: -inff\n";
        std::cout << "double: -inf\n";
        return;
    }
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    char* end;
    errno = 0;
    double d = std::strtod(literal.c_str(), &end);

    bool isFloat = false;

    if (*end == 'f' && *(end + 1) == '\0')
        isFloat = true;
    else if (*end != '\0')
    {
        std::cerr << "Invalid literal\n";
        return;
    }
    if (errno == ERANGE && std::isinf(d))
    {
        std::cerr << "Overflow\n";
        return;
    }
    std::cout << "char: ";
    if (d < 0 || d > 127 || std::isnan(d))
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max() ||
        std::isnan(d))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf\n";
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "inff\n";
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inff\n";
    else if (d <= std::numeric_limits<float>::max() 
            && d >= -(std::numeric_limits<float>::max()))
    {
        float f = static_cast<float>(d);
        std::ostringstream oss;
        oss << std::setprecision(7) << f;
        std::string fs = oss.str();
        std::cout << fs;
        if (fs.find('.') == std::string::npos && fs.find('e') == std::string::npos)
            std::cout << ".0";
        std::cout << "f\n";
    }
    else
    {
        std::cout << "impossible\n";
    }
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "inf\n";
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf\n";
    else
    {
        std::ostringstream oss;
        oss << std::setprecision(16) << d;
        std::string ds = oss.str();
        std::cout << ds;
        if (ds.find('.') == std::string::npos && ds.find('e') == std::string::npos)
            std::cout << ".0";
        std::cout << "\n";
    }
}
