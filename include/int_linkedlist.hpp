#include <iostream>
#include <cstdlib>

namespace list
{
struct IntegerNode
{
    int data;
    IntegerNode *next;
};

struct IntegersLL
{
    IntegerNode *head = nullptr;
};

int size(IntegersLL &list)
{
    IntegerNode *current = list.head;
    int counter = 0;
    while( current != nullptr )
    {
        current = current->next;
        counter = counter + 1;
    }
    return counter;
}

bool isEmpty(IntegersLL &list)
{
    return list.head == nullptr;
}

void insertFront(IntegersLL &list, int data)
{
    IntegerNode *newNode = new IntegerNode;
    newNode->data = data;
    newNode->next = list.head;
    list.head = newNode;
}

void insertBack(IntegersLL &list, int data)
{
    IntegerNode *newNode = new IntegerNode;
    newNode->data = data;
    newNode->next = nullptr;

    if (list.head == nullptr)
    {
        list.head = newNode;
    }
    else
    {
        IntegerNode *current = list.head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAt( IntegersLL &list , int index, int data )
{
    // Sanity Check
    if( index >= size( list ) || index < 0 )
    {
        std::cout << "Index Error!" << std::endl;
        exit( 1 );
    }

    if( index == 0 )
    {
        insertFront( list , data );
    }
    else
    {
        IntegerNode *current = list.head;
        for ( int i = 0; i < index - 1 ; ++i )
        {
            current = current->next;
        }

        IntegerNode *newNode = new IntegerNode;
        newNode->data = data;
        newNode->next = current->next;

        current->next = newNode;
    }
}


void printAll(IntegersLL &list)
{
    IntegerNode *current = list.head;
    while (current != nullptr)
    {
        std::cout << "(" << current->data << ")" << "->";
        current = current->next;
    }
    std::cout << "nil" << std::endl;
}

void removeFront(IntegersLL &list)
{
    // Sanity Check
    if (isEmpty(list))
    {
        std::cout << "Invalid operation on empty list" << std::endl;
        exit(1); // Not my problem
    }
    else
    {
        IntegerNode *oldHead = list.head;
        list.head = list.head->next;
        delete oldHead; // So it won't go after you in doomsday :)
    }
}

void removeBack(IntegersLL &list)
{
    // Sanity Check
    if (isEmpty(list))
    {
        std::cout << "Invalid operation on empty list" << std::endl;
        exit(1); // Not my problem.
    }
    else if ( list.head->next == nullptr ) // If the list has a single element.
    {
        delete list.head;
        list.head = nullptr;
    }
    else
    {
        IntegerNode *current = list.head;
        while (current->next->next != nullptr) // To stop at the second last element.
        {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

int getAt(IntegersLL &list, int index)
{
    // Sanity Check
    if( index >= size( list ) || index < 0 )
    {
        std::cout << "Index Error!" << std::endl;
        exit( 1 );
    }

    IntegerNode *current = list.head;
    int counter = 0;
    while( current != nullptr && counter != index )
    {
        current = current->next;
        counter = counter + 1;
    }
    return current->data;
}

void deletAt (IntegersLL &list , int index) 
{	int count = 0 ;
	IntegerNode * current = list.head ;
	IntegerNode * pcurrent = list.head ;
	while ( count < index )
	{  count++ ;
	   current = current->next ;
	   pcurrent = current ;
	}
	current = current-> next ;
	pcurrent->next = current ->next ;
	delete current ;
}	
	

void removeAt(IntegersLL &list, int index)
{
    // Sanity Check
    if( index >= size( list ) || index < 0 )
    {
        std::cout << "Index Error!" << std::endl;
        exit( 1 );
    }

    if( index == 0 ) removeFront( list ); // DRY ;)
    else
    {
        IntegerNode *current = list.head;
        IntegerNode *pcurrent = current;
        while( current->next != nullptr )
        {
            pcurrent = current;
            current = current->next;
        }
        pcurrent->next = current->next;
        delete current;
    }
}

int front(IntegersLL &list)
{
    if( !isEmpty( list ))
    {
        return list.head->data;
    }
    else
    {
        std::cout << "Empty list!" << std::endl;
        exit( 1 );
    }
}

int back(IntegersLL &list)
{
    return getAt( list , size( list ) - 1 ); //DRY
}
}
