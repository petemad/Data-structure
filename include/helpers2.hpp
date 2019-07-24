#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>
#include <vector> 
#include <iostream> // for std::cout
#include <fstream> // for std::ifstream (loading files from disk)
#include <algorithm> // for std::atof

namespace helpers
{

char* getDNA( const char *filePath , int lineNumber , int &size )
{
    std::ifstream f( filePath );
    std::string line;

    if( f )
    {
        int i = 0;
        while( std::getline( f , line ))
        {
            if( i == lineNumber )
                break;
            else ++i;
        }
    }
    else std::cout << "Failed to open file:" << filePath << std::endl;

    char *buffer = new char[ line.size() + 1 ];
    buffer[ line.size() ] = '\0';
    std::copy( line.begin() , line.end() , &buffer[0] );
    size = line.size();
    return buffer;
}

double *getECG( const char *filePath, int &size )
{
    std::ifstream f( filePath );
    std::vector< double > ecg;
    std::string line;
    if( f )
        while( std::getline( f , line ))
            ecg.push_back( std::atof( line.c_str() ));
    else std::cout << "Failed to open file:" << filePath << std::endl;

    double *buffer = new double[ ecg.size() ];
    size = ecg.size();
    return buffer;
}


}

#endif // HELPERS_HPP
