#include "ScalarConverter.hpp"

std::string	ScalarConverter::_representation	= "";
double 		ScalarConverter::_double   			= 0;
long		ScalarConverter::_long      		= 0;
int			ScalarConverter::_int      			= 0;
char		ScalarConverter::_char     			= 0;
float		ScalarConverter::_float    			= 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: ./converter <representation>" << std::endl;
        return (EXIT_FAILURE);
    }

    ScalarConverter::convert(argv[1]);
}