//
// Created by asem on 01/04/18.
//

#include "map.hpp"
#include "helpers1.hpp"

int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::vector< std::string > words = getFileWords( argv[1] );

        // COMPLETE HERE

        map::WordMap counter = map::create();

        for( int i = 0 ; i < words.size() ; ++i )
        {
            map::value( counter , words[i] )++;
        }

        // DONE HERE
        map::printAll (counter) ;
    }
    return 0;
}
