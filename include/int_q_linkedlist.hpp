#include<iostream>

namespace queue
{
struct IntegerNode
{
    int data;
    IntegerNode *next;
};

struct IntegersQueueLL
{
    IntegerNode *head = nullptr;
};

bool isEmpty( IntegersQueueLL &qu )
{
    return qu.head == nullptr;
}

int front( IntegersQueueLL &qu )
{
    // Same as list::front, copy-paste
    if( !isEmpty( qu ))
    {
        return qu.head->data;
    }
    else
    {
        std::cout << "Empty list!" << std::endl;
        exit( 1 );
    }
}

void enqueue( IntegersQueueLL &qu , int data )
{
    // same as list::insertBack, copy-paste
    IntegerNode *newNode = new IntegerNode;
    newNode->data = data;
    newNode->next = nullptr;

    if (qu.head == nullptr)
    {
        qu.head = newNode;
    }
    else
    {
        IntegerNode *current = qu.head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

}

int dequeue( IntegersQueueLL &qu )
{
    // same as list::front + list::removeFront
    if( !isEmpty( qu ))
    {
        int front = qu.head->data;

        // Now same as list::removeFront
        IntegerNode *oldHead = qu.head;
        qu.head = qu.head->next;
        delete oldHead;
        return front;
    }
    else
    {
        std::cout << "Empty list!" << std::endl;
        exit( 1 );
    }

}

int size( IntegersQueueLL &qu )
{
    // Same as list::size, copy-paste
    IntegerNode *current = qu.head;
    int counter = 0;
    while( current != nullptr )
    {
        current = current->next;
        counter = counter + 1;
    }
    return counter;
    
}

void printAll( IntegersQueueLL &qu )
{
    // Same as list::printAll, copy-paste
    IntegerNode *current = qu.head;
    while (current != nullptr)
    {
        std::cout << "(" << current->data << ")" << "->";
        current = current->next;
    }
    std::cout << "nil" << std::endl;
}
}