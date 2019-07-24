#include<iostream>

namespace queue
{

struct IntegersQueueArray
{
    int buffer [10];
    int capacity = 10;
    int rear = -1;
    int front = -1;
};

bool isEmpty( IntegersQueueArray &qu )
{
    return qu.front == qu.rear;
}

int front( IntegersQueueArray &qu )
{
    int index = ( qu.front + 1 ) % qu.capacity;
    return qu.buffer[ index ];
}

void enqueue( IntegersQueueArray &qu , int data )
{
    qu.rear = ( qu.rear + 1 ) % qu.capacity;
    qu.buffer[ qu.rear ] = data;
}

int dequeue( IntegersQueueArray &qu )
{
    qu.front = ( qu.front + 1 ) % qu.capacity;
    return qu.buffer[ qu.front ];
}

int size( IntegersQueueArray &qu )
{
    return ( qu.rear - qu.front  + qu.capacity ) % qu.capacity;
}

void printAll( IntegersQueueArray &qu )
{
    if( !isEmpty( qu ))
    {
        for( int i = qu.front ; i != qu.rear ; i = ( i + 1 ) % qu.capacity )
        {
            int index = ( i + 1 ) % qu.capacity;
            std::cout << "(" << qu.buffer[ index ] << ")" << " -> ";
        }
        std::cout << "end" << std::endl;
    }
    std::cout << "front:" << qu.front << ", rear:" << qu.rear <<std::endl;
    std::cout << "size:" << size(qu) << std::endl << std::endl;
}

}
