#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "converter constructor (default)" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
	// std::cout << "converter constructor (copy)" << std::endl;
	*this = c;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "converter destructor" << std::endl;
}


ScalarConverter &ScalarConverter::operator = (const ScalarConverter &c)
{
	std::cout << "converter assignment operator" << std::endl;
	_representation = c._representation;
	return (*this);
}

ScalarConverter::Type ScalarConverter::getType()
{
    char    *end;

    if (_representation.length() == 1 && (_representation[0] >= 0 && _representation[0] <= 127 && isprint(_representation[0])))
        return (CHAR);

    std::strtol(_representation.c_str(), &end, 10);
    if (end[0] == '\0')
        return (INT);
    
    std::strtof(_representation.c_str(), &end);
    if ((end[0] == 'f' && end[1] == '\0') || _representation.compare("-inff") == 0 || _representation.compare("inff") == 0 || _representation.compare("nanf") == 0)
        return (FLOAT);
    
    std::strtod(_representation.c_str(), &end);
    if (end[0] == '\0')
        return (DOUBLE);
    return (NONE);
}

void ScalarConverter::fromChar()
{
    _char     = static_cast<char>(_representation[0]);
    _int      = static_cast<int>(_char);
	_long	  = static_cast<long>(_char);
    _float    = static_cast<float>(_char);
    _double   = static_cast<double>(_char);
}

void ScalarConverter::fromInt()
{
    _long     = static_cast<long>(atol(_representation.c_str()));
    _int      = static_cast<int>(atoi(_representation.c_str()));
    _char     = static_cast<char>(_int);
    _float    = static_cast<float>(_int);
    _double   = static_cast<double>(_int);
}

void ScalarConverter::fromFloat()
{
	char	*end;

    _float    = static_cast<float>(std::strtof(_representation.c_str(), &end));
	_long	  = static_cast<long>(_float);
    _int      = static_cast<int>(_float);
    _char     = static_cast<char>(_float);
    _double   = static_cast<double>(_float);
}

void ScalarConverter::fromDouble()
{
    _double   = static_cast<double>(atof(_representation.c_str()));
	_long	  = static_cast<long>(_double);
    _int      = static_cast<int>(_double);
    _char     = static_cast<char>(_double);
    _float    = static_cast<float>(_double);
}

void ScalarConverter::printChar()
{
    std::cout << "char     : ";
    if (_int < 0 || _int > 127)
        std::cout << "impossible";
    else if (isprint(_char))
        std::cout << "'" << _char << "'";
    else
        std::cout << "non displayable";
    std::cout << std::endl;
}

void ScalarConverter::printInt()
{
    std::cout << "int      : ";
    if (_long < INT_MIN || _long > INT_MAX)
        std::cout << "impossible";
    else
        std::cout << _int;
    std::cout << std::endl;
}

void ScalarConverter::printFloat()
{
    std::cout << "float    : ";
    std::cout << std::fixed << std::setprecision(1);
    if (getType() == NONE)
        std::cout << "nan";
	else
        std::cout << _float;
    std::cout << "f";
    std::cout << std::endl;
}

void ScalarConverter::printDouble()
{
    std::cout << "double   : ";
    std::cout << std::fixed << std::setprecision(1);
    if (getType() == NONE)
        std::cout << "nan";
    else
        std::cout << _double;
    std::cout << std::endl;
}

void ScalarConverter::printAll()
{
    printChar();
    printInt();
    printFloat();
    printDouble();
}

void ScalarConverter::convert(std::string representation)
{
	_representation = representation;
	switch (getType())
    {
    case CHAR:
        fromChar();
        break;
    case INT:
        fromInt();
        break;
    case FLOAT:
        fromFloat();
        break;
    case DOUBLE:
        fromDouble();
        break;
    default:
		std::cout << "incorrect input" << std::endl;
		return;
        break;
    }
	printAll();
}