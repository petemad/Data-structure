#include "my_header.hpp"
#include <iostream>
#include <algorithm>

int main( int argc , char **argv)
{
    double x1=0 ,x2=0 ,y1=0 ,y2=0 ;
if (argc == 5 )
{
    x1 = std::atof ( argv[1]);
    x2 = std::atof ( argv[2]);
    y1 = std::atof ( argv[3]);
    y2 = std::atof ( argv[4]);
    
    std::cout << "distance = " << pythagorean (x1 , x2 , y1 , y2) << std::endl;
}
else if (argc == 1)
{
     
    std::cout << "x1=" ;
    std::cin >> x1;
    
    std::cout << "x2=" ;
    std::cin >> x2 ;
    
    std::cout << "y1=" ;
    std::cin >> y1 ;
    
    std::cout << "y2=" ;
    std::cin >> y2 ;
    std::cout << "distance = " << pythagorean (x1 , x2 , y1 , y2) << std::endl;
}    
}  