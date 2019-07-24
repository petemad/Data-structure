#ifndef queue_HPP
#define queue_HPP
#include "LinkedList.hpp"
#include <iostream>

//Peter

//queue of integers using LinkedList

struct intQueue
{
    //parameters here (using Linked List)
    IntegerNode *rear = nullptr;
    IntegerNode *front = nullptr;
    int size = 0;
    //methods
    void enqueue(int data)
    {
        IntegerNode *newNode = new IntegerNode;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
        if (front == nullptr)
        {
            front = rear;
        }
    }

    int dequeue()
    {

        if (isEmpty() == false)
        {
            IntegerNode *current;
            current = front;
            int removedData = current->data;
            front = front->next;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
        }
    }
    int getFront()
    {
        return front->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {

        return size;
    }
    void clear()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

//Bonus : Queue of integers using Arrays

struct intArrayQueue
{
    int front = 0;
    int rear = 0;
    int arrayQueue[100];
    int size = 0;
    //methods
    void enqueue(int data)
    {
        if (isFull() == false)
        {
            size++;
            arrayQueue[rear] = data;
            rear++;
            if (rear == 100)
            {
                rear = 0;
            }
        }
        else
        {
            std::cout << "queue is full";
        }
    }
    int dequeue()
    {
        if (isEmpty() == false)
        {
            size--;
            int removedData = arrayQueue[front];
            front++;
            if (front == 100)
            {
                front = 0;
            }
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
        }
    }
    int getFront()
    {
        return arrayQueue[front];
    }
    bool isFull()
    {
        return size == 100;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        front = rear;
        size = 0;
    }
};

//queue of characters using LinkedList

struct charQueue
{
    //parameters here (using Linked List)
    CharNode *rear = nullptr;
    CharNode *front = nullptr;
    int size = 0;
    //methods
    void enqueue(char data)
    {
        if (front == nullptr)
        {
            front = rear;
        }
        CharNode *newNode = new CharNode;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
    }

    char dequeue()
    {
        if (isEmpty() == false)
        {
            CharNode *current = front;
            char removedData = front->data;
            front = front->next;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
        }
    }
    char getFront()
    {
        return front->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void clear()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

//Bonus : Queue of characters using Arrays
struct charArrayQueue
{
    int front = 0;
    int rear = 0;
    int size = 0;
    char arrayQueue[100];
    //methods
    void enqueue(char data)
    {
        if (isFull() == false)
        {
            size++;
            arrayQueue[rear] = data;
            rear++;
            if (rear == 100)
            {
                rear = 0;
            }
        }
        else
        {
            std::cout << "queue is full";
        }
    }
    char dequeue()
    {
        if (isEmpty() == false)
        {
            size--;
            char removedData = arrayQueue[front];
            front++;
            if (front == 100)
            {
                front = 0;
            }
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
        }
    }
    char getFront()
    {
        return arrayQueue[front];
    }
    bool isFull()
    {
        return size == 100;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        front = rear;
        size = 0;
    }
};

//queue of doubles using LinkedList

struct doubleQueue
{
    //parameters here (using Linked List)
    DoubleNode *rear = nullptr;
    DoubleNode *front = nullptr;
    int size = 0;
    //methods
    void enqueue(double data)
    {
        DoubleNode *newNode = new DoubleNode;
        if (rear != nullptr)
            rear->next = newNode;
        rear = newNode;
        newNode->data = data;
        newNode->next = nullptr;
        size++;
        if (front == nullptr)
        {
            front = rear;
        }
    }

    double dequeue()
    {

        if (isEmpty() == false)
        {
            DoubleNode *current;
            current = front;
            double removedData = current->data;
            front = front->next;
            size--;
            delete current;
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
        }
    }

    double getFront()
    {
        return front->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        while (front != nullptr)
        {
            dequeue();
        }
    }
};

//Bonus : Queue of doubles using Arrays
struct doubleArrayQueue
{
    int front = 0;
    int rear = 0;
    int size = 0;
    double arrayQueue[100];
    //methods
    void enqueue(double data)
    {
        if (isFull() == false)
        {
            arrayQueue[rear] = data;
            rear++;
            size++;
            if (rear == 100)
            {
                rear = 0;
            }
        }
        else
        {
            std::cout << "queue is full";
        }
    }
    double dequeue()
    {
        if (isEmpty() == false)
        {
            size--;
            char removedData = arrayQueue[front];
            front++;
            if (front == 100)
            {
                front = 0;
            }
            return removedData;
        }
        else
        {
            std::cout << "queue is empty";
        }
    }
    double getFront()
    {
        return arrayQueue[front];
    }
    bool isFull()
    {
        return size == 100;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        front = rear;
        size = 0;
    }
};

#endif // queue_HPP
