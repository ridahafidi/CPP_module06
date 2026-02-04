#include <cstdlib>   // strtod
#include <cerrno>    // errno
#include <limits>    // numeric_limits
#include <cctype>    // isprint
#include <iostream>
#include "ScalarConverter.hpp"
#include <cmath>

void ScalarConverter::convert(const std::string &literal)
{
    // 1) Empty check
    if (literal.empty())
    {
        std::cerr << "Empty input\n";
        return;
    }

    // 2) Handle special values explicitly (subject requirement)
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

    // 3) Single printable char case (e.g. 'a')
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        char c = literal[0];

        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << ".0f\n";
        std::cout << "double: " << static_cast<double>(c) << ".0\n";
        return;
    }

    // 4) Numeric parsing using strtod
    char* end;
    errno = 0;

    double d = std::strtod(literal.c_str(), &end);

    // 5) Validate parsing
    bool isFloat = false;

    if (*end == 'f' && *(end + 1) == '\0')
        isFloat = true;
    else if (*end != '\0')
    {
        std::cerr << "Invalid literal\n";
        return;
    }

    if (errno == ERANGE)
    {
        std::cerr << "Overflow or underflow\n";
        return;
    }

    // 6) CHAR
    std::cout << "char: ";
    if (d < 0 || d > 127 || std::isnan(d))
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";

    // 7) INT
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() ||
        d > std::numeric_limits<int>::max() ||
        std::isnan(d))
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";

    // 8) FLOAT
    std::cout << "float: ";
    if (std::isnan(d))
        std::cout << "nanf\n";
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "inff\n";
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inff\n";
    else
    {
        float f = static_cast<float>(d);
        std::cout << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f\n";
    }

    // 9) DOUBLE
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan\n";
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "inf\n";
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf\n";
    else
    {
        std::cout << d;
        if (d == static_cast<int>(d))
            std::cout << ".0";
        std::cout << "\n";
    }
}
