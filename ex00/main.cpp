#include "Converter.hpp"

std::string	Converter::_representation	= "";
double 		Converter::_double   		= 0;
long		Converter::_int      		= 0;
char		Converter::_char     		= 0;
float		Converter::_float    		= 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: ./converter <representation>" << std::endl;
        return (EXIT_FAILURE);
    }

    Converter::convert(argv[1]);
}