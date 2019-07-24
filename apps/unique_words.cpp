//
// Created by asem on 01/04/18.
//

#include "set.hpp"
#include "helpers1.hpp"


int main( int argc, char **argv )
{
    if( argc == 2 )
    {
        std::vector< std::string > words = getFileWords( argv[1] );

        // COMPLETE HERE
        set::WordSet set = set::create();
        for( int i = 0; i <= words.size(); i++)
        {
            set::insert( set, words[i] );
        }
        std::cout<<"size of set is: "<<set::size( set )<<std::endl;
        
        // DONE HERE
    }

    return 0;
}
