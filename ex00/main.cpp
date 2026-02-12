#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
    {
        std::cerr << "Give a single argument\n";
        return(1);
    }
    return (0);
}