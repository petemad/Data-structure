#include "mathematics.hpp" // for mathematics::calculation
#include <string>
#include <iostream> // for std::cout and std::cin
#include <algorithm> // for std::atof

int main( int argc , char **argv )
{
    double a = 0, b = 0;
    char operation = 0;
    if( argc == 1 )
    {
        // If argc == 1, then the user hasn't introduce
        // command line arguments.
        // we can give him a chance to input his parameters
        // using std::cin
        std::cin >> a >> operation >> b;
    }
    else if( argc == 4 )
    {
        a = std::atof( argv[1] );
        b = std::atof( argv[3] );
        operation = argv[2][0];
    }
    else
    {
        std::cout << "Incorrect usage!" << std::endl;
        return 1; // Failure Code!
    }

    std::cout << mathematics::calculation( a , b , operation ) << std::endl;
    return 0; // Success Code!
}
