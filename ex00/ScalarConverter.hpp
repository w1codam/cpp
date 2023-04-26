#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include <string>
#include <iomanip>

class ScalarConverter {
public:
	static void			convert(std::string representation);
private:
    ScalarConverter(); // occf
    ScalarConverter(const ScalarConverter &c);
    ~ScalarConverter();
    ScalarConverter & operator = (const ScalarConverter &c);

    enum Type { NONE, CHAR, INT, FLOAT, DOUBLE };

    static Type        	getType();

    static void    		fromChar();
    static void    		fromInt();
    static void    		fromFloat();
    static void    		fromDouble();
    static void    		printChar();
    static void    		printInt();
    static void    		printFloat();
    static void    		printDouble();
    static void    		printAll();
private:
    static std::string	_representation;
    static char       	_char;
    static long       	_long;
    static int       	_int;
    static float      	_float;
    static double     	_double;
};

#endif // CONVERTER_H
