#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);   
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
public:
    static void convert(const std::string &literal);
};
// "42.0f" "42"  "42f" '*'

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty() == true)
    {
        std::cerr << "The given input is empty";
        return ;
    }
    int i = 0;
    int f_counter = 0;
    int dot_counter = 0;
    int sign = 0;
    int s_counter = 0;
    bool is_char = false;
    bool good = false;
    while (literal[i])
    {
        if (isdigit(literal[i]) == false)
        {
            if (literal[i] == '+')
            {
                s_counter++;
                sign = 1;
            }
            else if (literal[i] == '-')
            {
                s_counter++;
                sign = -1;
            }
            else if (literal[i] == 'f')
                f_counter++;
            else if (literal[i] == '.')
                dot_counter++;
            else
                good = false;
        }
        //handling char incoming
        i++;
    }
}







#endif