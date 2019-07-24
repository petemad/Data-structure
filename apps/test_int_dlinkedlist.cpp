#include <iostream>
#include "int_dlinkedlist.hpp"

int main()
{
    list::IntDoublyLL testList;
    list::printAll( testList );

    list::insertFront( testList , 9 );
    list::printAll( testList );

    list::insertBack( testList , 12 );
    list::printAll( testList );

    list::insertBack( testList , 33 );
    list::insertBack( testList , 44 );
    list::printAll( testList );

    list::removeAt( testList , 2 );
    list::printAll( testList );
    
    list::removeAt( testList , 0 );
    list::printAll( testList );
}