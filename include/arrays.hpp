#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>
#include "mathematics.hpp"

namespace arrays
{

void printAll( char *base , int arraySize )
{
    for (int i=0; i<arraySize ; ++i)
    {
        std::cout << base[i]  ;
    }	
}
double maxArray( double *base, int arraySize )
{
    double max = *base ;
    for ( int i = 0;  i < arraySize ; ++i )
    {
        if (max <= base[i+1])
            {
            max = base[i+1] ;
            } 
    }
return max;        
}

double minArray( double *base, int arraySize )
{
    double min = *base;
    for ( int i = 0;  i < arraySize ; ++i )
    {
        if (min >= base[i+1] )
            {
            min = base[i+1] ;
            } 
    }
return min;
}
double meanArray( double *base , int arraySize )
{
    double mean = 0;
    for ( int i = 0;  i < arraySize ; ++i)
    {
        mean += base[i] ;
    }
return mean / arraySize;
}
double varianceArray( double *base, int arraySize )
{
    double variance = 0;
    for ( int i = 0;  i < arraySize ; ++i )
    {
    variance += mathematics::square(base[i] - meanArray( base , arraySize ));
    } 
return variance/arraySize;
}

int countCharacter( char *basePointer , int size , char query )
{
    int counter = 0;
        for (int i = 0; i < size ; ++i )
    {
        if (query == basePointer[i])
            {
                counter += 1;
            }        
    }       
return counter;    
} 

struct DoubleArray 
    {
        double *base;
        int size ;
    };

struct CharacterArray 
    {
        char *base ;
        int size ;
    };


void printAll( CharacterArray array )
{
    arrays::printAll ( array.base , array.size );
}

double maxArray( DoubleArray array )
{
    return arrays::maxArray ( array.base , array.size );
}

double minArray( DoubleArray array )
{
    return arrays::minArray ( array.base , array.size ); 
}

double meanArray( DoubleArray array )
{
    return arrays::meanArray ( array.base , array.size ) ;    
}

double varianceArray( DoubleArray array )
{
    return arrays::varianceArray ( array.base , array.size );
}


}


#endif // ARRAYS_HPP
