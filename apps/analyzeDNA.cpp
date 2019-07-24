#include "helpers2.hpp" // for helpers::loadDNA
#include "dna.hpp" // for dna::analyzeDNA


int main( int argc , char **argv )
{
    if( argc != 2 )
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        int size = 0;
        char *dnaArray1 = helpers::getDNA( argv[1] , 0 , size );


        dna::dnaarray dna { dnaArray1 , size };             
        dna::dnastatistics stats;
        stats = dna::analyzedna ( dna );


        std::cout <<"Adenine (A) content:" << stats.countA << std::endl
                 << "Guanine (G) content:" << stats.countG << std::endl
                 << "Cytocine(C) content:" << stats.countC << std::endl
                 << "Thymine (T) content:" << stats.countT << std::endl << std::endl
                 << "Complementary Sequence:" << std::endl << stats.comp << std::endl;

        // Clean up.
        
        return 0;
    }
}
