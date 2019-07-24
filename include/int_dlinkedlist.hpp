#ifndef INT_DLL_HPP
#define INT_DLL_HPP

#include <iostream>

namespace list
{

struct IntDoublyNode
{
    int data;
    IntDoublyNode *next = nullptr;
    IntDoublyNode *previous = nullptr;
};

struct IntDoublyLL
{
    IntDoublyNode *head = nullptr;
};

bool isEmpty(IntDoublyLL &ll)
{
    return ll.head == nullptr;
}

int front(IntDoublyLL &ll)
{
    if (!isEmpty(ll))
    {
        return ll.head->data;
    }
    else
    {
        std::cout << "Empty list!" << std::endl;
        exit(1);
    }
}

int size(IntDoublyLL &ll)
{
    IntDoublyNode *current = ll.head;
    int counter = 0;
    while (current != nullptr)
    {
        current = current->next;
        counter = counter + 1;
    }
    return counter;
}

void insertFront(IntDoublyLL &ll, int data)
{
    IntDoublyNode *newNode = new IntDoublyNode;
    newNode->data = data;
    newNode->previous = nullptr;

    newNode->next = ll.head;
    ll.head = newNode;
}

void insertBack(IntDoublyLL &ll, int data)
{
    IntDoublyNode *newNode = new IntDoublyNode;
    newNode->data = data;
    newNode->next = nullptr;

    if (ll.head == nullptr)
    {
        newNode->previous = nullptr;
        ll.head = newNode;
    }
    else
    {
        IntDoublyNode *current = ll.head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->previous = current;
    }
}

void insertAt(IntDoublyLL &ll, int index, int data)
{
    // Sanity Check
    if (index >= size(ll) || index < 0)
    {
        std::cout << "Index Error!" << std::endl;
        exit(1);
    }

    IntDoublyNode *newNode = new IntDoublyNode;
    newNode->data = data;

    IntDoublyNode *current = ll.head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    current->next->previous = newNode;
    newNode->next = current->next;

    newNode->previous = current;
    current->next = newNode;
}

void printAll(IntDoublyLL &ll)
{
    IntDoublyNode *current = ll.head;

    while (current != nullptr)
    {
        std::cout << "(" << current->data << ")" << "<=>";
        current = current->next;
    }

    std::cout << "nil" << std::endl;
}

void removeFront(IntDoublyLL &ll)
{
    if (!isEmpty(ll))
    {
        IntDoublyNode *discard = ll.head;

        if (ll.head->next != nullptr)
            ll.head->next->previous = nullptr;

        ll.head = ll.head->next;
        delete discard;
    }
    else
    {
        std::cout << "Empty list!" << std::endl;
        exit(1);
    }
}

void removeBack(IntDoublyLL &ll)
{
    // Sanity check
    if (!isEmpty(ll))
    {
        IntDoublyNode *current = ll.head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        
        if( current->previous != nullptr )
            current->previous->next = nullptr;
        
        delete current->next;
    }
    else
    {
        std::cout << "Empty list!" << std::endl;
        exit(1);
    }
}
void removeAt( IntDoublyLL &ll, int index )
{
    // Sanity Check
    if( index >= size( ll ) || index < 0 )
    {
        std::cout << "Index Error!" << std::endl;
        exit( 1 );
    }

    if( index == 0 ) removeFront( ll ); // DRY ;)
    else
    {
        IntDoublyNode *current = ll.head;
        // Since we are in a double linked list we are fine
        // to land on the element at position index, that we need 
        // to delete.
        for( int i = 0 ; i < index ; ++i )
        {
            current = current->next;
        }
        
        current->previous->next = current->next;
        delete current;
    }
}
}
#endif