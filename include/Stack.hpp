#ifndef MEMBER2_HPP
#define MEMBER2_HPP
#include <cstdlib>
#include "LinkedList.hpp"
struct IntegerStack
{

    //Parameters here (using array)
    int arr[100];
    int top = -1;

    //Methods
    void push(int data)
    {
        if (top == 99)
           {
               std::cout << "The stack is full"<< std::endl;
               exit(1);
           }

        top++;
        arr[top] = data;
    }
    int pop()
    {
        if (top != -1)
        {
            int returnData = 0;
            returnData = arr[top];
            top--;
            return returnData;
        }

        else
        {
            std::cout <<"The stack is empty"<<std::endl;
            exit(1);
        }

            
    }
    int front() const
    {
        if (top != -1)
        {
            int returnData = 0;
            returnData = arr[top];
            return returnData;
        }

        else
        {
            std::cout<<"The stack is empty"<<std::endl;
            exit(1);
        }
    }
    bool isEmpty() const
    {
        if (top == -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    int size() const
    {
        return top + 1;
    }
    void clear()
    {
        top = -1;
    }
};

struct CharStack
{

    //parameters here (using array)
    char arr[100];
    int top = -1;

    //Methods
    void push(char data)
    {
        if (top == 99)
           {
               std::cout << "The stack is full"<< std::endl;
               exit(1);
           }

        top++;
        arr[top] = data;
    }
    char pop()
    {
        if (top != -1)
        {
            char returnData = 0;
            returnData = arr[top];
            top--;
            return returnData;
        }

        else
        {
            std::cout << "The stack is empty"<< std::endl;
            exit(1);
        }
    }
    char front() const
    {
        if (top != -1)
        {
            char returnData = 0;
            returnData = arr[top];
            return returnData;
        }

        else
        {
            std::cout << "The stack is full"<< std::endl;
            exit(1);
        }

    }
    bool isEmpty() const
    {
        if (top == -1)
        {
            return true;
        }

        else
        {
            return false;
        }

    }
    int size() const
    {
        return top + 1;
    }
    void clear()
    {
        top = -1;
    }
};

//stack using Linked List
struct IntegerStackLL
{
    IntegerNode *top = nullptr;

    void push(int data)
    {
        IntegerNode *newNode = new IntegerNode;
        newNode->next = top;
        newNode->data = data;
        top = newNode;
    }
    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Invalid Pop: Stack is Empty" << std::endl;
            exit(1);
        }
        int toReturnData = top->data;
        IntegerNode *toDelete = top;
        top = top->next;
        delete toDelete;
        return toReturnData;
    }
    int front() const
    {
        if (isEmpty())
        {
            std::cout<<"The stack is empty"<<std::endl;
            exit(1);
        }
        else
        {
            int toReturnData = top->data;
            return toReturnData;
        }
    }
    bool isEmpty() const
    {
        return (top == nullptr);
    }
    int size() const
    {
        int size = 0;
        IntegerNode *current = top;
        while (current != nullptr)
        {
            current = current->next;
            size++;
        }
        return size;
    }
    void clear()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
};

struct CharStackLL
{
    CharNode *top = nullptr;

    void push(char data)
    {
        CharNode *newNode = new CharNode;
        newNode->next = top;
        newNode->data = data;
        top = newNode;
    }
    char pop()
    {
        if (isEmpty())
        {
            std::cout << "Invalid Pop: Stack is Empty" << std::endl;
            exit(1);
        }
        char toReturnData = top->data;
        CharNode *toDelete = top;
        top = top->next;
        delete toDelete;
        return toReturnData;
    }
    char front() const
    {
        if(isEmpty())
        {
            std::cout<<"The stack is empty"<<std::endl;
            exit(1);
        }
        else
        {
            char toReturnData = top->data;
            return toReturnData;
        }
    }
    bool isEmpty() const
    {
        return (top == nullptr);
    }
    int size() const
    {
        int size = 0;
        CharNode *current = top;
        while (current != nullptr)
        {
            current = current->next;
            size++;
        }
        return size;
    }
    void clear()
    {
        while (top != nullptr)
        {
            pop();
        }
    }
};
#endif // MEMBER2_HPP
