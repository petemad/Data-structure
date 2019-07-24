#ifndef DNA_HPP
#define DNA_HPP

#include "arrays.hpp"
#include<algorithm>

namespace dna
{
struct dnastatistics
{
    char *comp ;
    int countA ; int countC; int countT ; int countG;
};

struct dnaarray 
{
    char * base;
    int size;
};


    char complementaryBase( char base )
{
    
    if ( base == 'A')
        return 'T';
    else if ( base == 'T')
        return 'A';
    else if ( base == 'C')
        return 'G';
    else 
        return 'C';            
}

char * complementarySequence( char *base, int size )
{
    for ( int i=0; i < (size + 1) / 2; ++i)
    {
        std::swap(base [i], base[size - i - 1]);
    }

    for ( int i=0; i < size; ++i)
    {
        base [i] = complementaryBase (base[i]);
    }


return base;
}

char *analyzeDNA( char *base, int size, int &countA, int &countC, int &countG, int &countT )
{
    countA = arrays::countCharacter( base , size , 'A' );
    countG = arrays::countCharacter( base , size , 'G' );
    countC = arrays::countCharacter( base , size , 'C' );
    countT = arrays::countCharacter( base , size , 'T' );
    complementarySequence( base , size );
}

dnastatistics analyzedna ( dnaarray dna )
{
    dnastatistics DNAarray;
    DNAarray.comp=complementarySequence(dna.base , dna.size );
    DNAarray.countA=arrays::countCharacter( dna.base , dna.size , 'A' );
    DNAarray.countT=arrays::countCharacter( dna.base , dna.size , 'T' );
    DNAarray.countC=arrays::countCharacter( dna.base , dna.size , 'C' );
    DNAarray.countG=arrays::countCharacter( dna.base , dna.size , 'G' );
    return DNAarray;
}

}

#endif // DNA_HPP
