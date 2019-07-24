#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

#include <cmath> // for std::sqrt
#include <iostream>
#include <string>
namespace mathematics
{

struct Triangle
{
    double a;
    double b;
    double c;
};



double calculation( double a , double b , char operation )
{
    if ( operation == '+' )
        return a + b;
    else if ( operation == '-' )
        return a - b;
    else if (operation == '*')
        return a * b;
    else if (operation == '/')
	    return a / b;
    else
    std::cout << "invalid operator" << std::endl;	            
}
double heron( double a , double b , double c )
{
   double s = (a+b+c)/2;
   double A = std::sqrt( s*(s-a)*(s-b)*(s-c));
   std::cout << "Triangle area =" << A << std::endl;	  
   return A;
}
double square( double a)
{
   a = a * a;
   return a;
}

double heron( Triangle t )
{
    return heron (t.a , t.b , t.c );
}


}
#endif // MATHEMATICS_HPP
