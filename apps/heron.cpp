#include "mathematics.hpp" // for mathematics::heron
#include <iostream> // for std::cout
#include <algorithm> // for std::atof

// We need main function here!
int main ()
{
    mathematics::Triangle t{ 0 , 0 , 0 };
    std::cout << "a=" ;
    std::cin >> t.a ;
    std::cout << "b=" ;
    std::cin >> t.b ;
    std::cout << "c=" ;
    std::cin >> t.c ;
    mathematics::heron ( t );
return 0;  
}    
  