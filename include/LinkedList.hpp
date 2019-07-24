#ifndef LinkedList_HPP
#define LinkedList_HPP
#include <cstdlib>
#include <iostream>

//Merna & Youssef

//Linked List of Integers: 
struct IntegerNode
{
    int data;
    IntegerNode *next = nullptr;
};

struct IntegerLL
{
    IntegerNode *front = nullptr;
    //Methods
    IntegerNode *getBackNode() const
    {
        IntegerNode *currentNode = front;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
    int size() const
    {
        IntegerNode *currentNode = front;
        int size = 0;
        while (currentNode != nullptr)
        {
            size++;
            currentNode = currentNode->next;
        }
        return size;
    }
    void insertFront(int const data)
    {
        IntegerNode *newNode = new IntegerNode;
        newNode->data = data;
        newNode->next = front;
        front = newNode;
    }

    void insertBack(int const data)
    {
        IntegerNode *newNode = new IntegerNode;
        newNode->data = data;
        newNode->next = nullptr;
        if (front == nullptr )
        {
            front = newNode;
        }
        else
        {
            IntegerNode *backNode = getBackNode();
            backNode->next = newNode;
        }
    }

    void removeFront()
    {
        if (isEmpty())
        {
            std::cout << "List is empty" << std::endl ;
            exit(1);
        }
        else
        {
            IntegerNode *oldFront = front;
            front = front->next;
            oldFront->next = nullptr;
            delete oldFront;
        }
    }

    void removeBack()
    {
        if (isEmpty())
        {
            std::cout << "List is empty" << std::endl ;
            exit(1);
        }
        else
        {
            IntegerNode *currentNode = front;
            if (currentNode->next == nullptr)
            {
                front = nullptr;
                delete currentNode;
            }
            else
            {
                while (currentNode->next->next != nullptr)
                {
                    currentNode = currentNode->next;
                }
                IntegerNode *oldNode = currentNode->next;
                currentNode->next = nullptr;
                delete oldNode;
            }
        }
    }

    void removeAt(int const index)
    {
        if (index < size() && index >= 0)
        {
            int counterb4Index = 0;
            IntegerNode *currentNode = front;
            if (index == 0)
            {
                removeFront();
            }
            else
            {
                while (counterb4Index != index - 1)
                {
                    currentNode = currentNode->next;
                    counterb4Index++;
                }
                IntegerNode *oldNode = currentNode->next;
                currentNode->next = currentNode->next->next;
                oldNode->next = nullptr;
                delete oldNode;
            }
        }
        else
        {
            std::cout << "invalid index: " << index << std::endl;
        }
    }

    int getFront() const 
    {
        if (!isEmpty())
        {
            return front->data;
        }
        else
        {
            std::cout << "Empty list" << std::endl;
        }    
    }

    int getBack() const
    {
        if (!isEmpty())
        {
            IntegerNode *backNode = getBackNode();
            return backNode->data;
        }
        else
        {    
            std::cout << "Empty List" << std::endl;
        }    
    }

    int getAt(int index) const
    {
        if (!(index < size()) || index < 0)
        {
            std::cout << "invalid index" << std::endl;
        }
        else
        {
            IntegerNode *currentNode = front;
            while (index > 0)
            {
                currentNode = currentNode->next;
                index--;
            }
            return currentNode->data;
        }
    }

    void filter(int const data) 
    {

        while (front->data == data)
        {
            removeFront();
        }
        int index = 0;
        IntegerNode *currentNode = front;
        while (currentNode->next != nullptr)
        {
            if (currentNode->next->data == data)
            {
                removeAt(index + 1);
            }
            else
            {
                currentNode = currentNode->next;
                index++;
            }
        }
    }
    bool isEmpty() const 
    {
        return (front == nullptr);
    }

    void printAll() const 
    {
        IntegerNode *currentNode = front;
        while (currentNode != nullptr)
        {
            std::cout << currentNode->data << std::endl;
            currentNode = currentNode->next;
        }
    }
    void clear() 
    {
        while (front != nullptr)
        {
            removeBack();
        }
    }
};

// Linked List of Characters:
struct CharNode
{
    char data;
    CharNode *next = nullptr;
};

struct CharLL
{
    CharNode *front = nullptr;
    //Methods
    CharNode *getBackNode() const 
    {
        CharNode *currentNode = front;
        while ( currentNode->next != nullptr )
        {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
    int size() const 
    {
        CharNode *currentNode = front;
        int size = 0;
        while ( currentNode != nullptr )
        {
            size++;
            currentNode = currentNode->next;
        }
        return size;
    }
    void insertFront(char const data)
    {
        CharNode *newNode = new CharNode;
        newNode->data = data;
        newNode->next = front;
        front = newNode;
    }

    void insertBack(char const data)
    {
        CharNode *newNode = new CharNode;
        newNode->data = data;
        newNode->next = nullptr;
        if (front == nullptr )
        {
            front = newNode;
        }
        else
        {
            CharNode *backNode = getBackNode();
            backNode->next = newNode;
        }
    }

    void removeFront()
    {
        if (isEmpty())
        {
            std::cout << "List is empty " << std::endl ;
            exit(1);
        }
        else
        {
            CharNode *oldFront = front;
            front = front->next;
            oldFront->next = nullptr;
            delete oldFront;
        }
    }

    void removeBack()
    {
        if (isEmpty())
        {
            std::cout << "List is empty " << std::endl ;
            exit(1);
        }
        else
        {
            CharNode *currentNode = front;
            if ( currentNode->next == nullptr )
            {
                front = nullptr;
                delete currentNode;
            }
            else
            {
                while ( currentNode->next->next != nullptr )
                {
                    currentNode = currentNode->next;
                }
                CharNode *oldNode = currentNode->next;
                currentNode->next = nullptr;
                delete oldNode;
            }
        }
    }

    void removeAt(int const index)
    {
        if ( index < size() && index >= 0 )
        {
            int counterb4Index = 0;
            CharNode *currentNode = front;
            if ( index == 0 )
            {
                removeFront();
            }
            else
            {
                while ( counterb4Index != index - 1 )
                {
                    currentNode = currentNode->next;
                    counterb4Index++;
                }
                CharNode *oldNode = currentNode->next;
                currentNode->next = currentNode->next->next;
                oldNode->next = nullptr;
                delete oldNode;
            }
        }
        else
        {
            std::cout << "invalid index: " << index << std::endl;
        }
    }

    int getFront() const
    {
        if ( !isEmpty() )
        {
            return front->data;
        }
        else
        {
            std::cout << "Empty list" << std::endl;
        }    
    }

    int getBack() const
    {
        if ( !isEmpty() )
        {
            CharNode *backNode = getBackNode();
            return backNode->data;
        }
        else
            std::cout << "Empty List" << std::endl;
    }

    int getAt(int index) const
    {
        if ( !(index < size()) || index < 0 )
        {
            std::cout << "invalid index" << std::endl;
        }
        else
        {
            CharNode *currentNode = front;
            while ( index > 0 )
            {
                currentNode = currentNode->next;
                index--;
            }
            return currentNode->data;
        }
    }

    void filter(char const data)
    {

        while ( front->data == data )
        {
            removeFront();
        }
        int index = 0;
        CharNode *currentNode = front;
        while ( currentNode->next != nullptr )
        {
            if ( currentNode->next->data == data )
            {
                removeAt(index + 1);
            }
            else
            {
                currentNode = currentNode->next;
                index++;
            }
        }
    }
    bool isEmpty() const
    {
        return ( front == nullptr );
    }

    void printAll() const
    {
        CharNode *currentNode = front;
        while ( currentNode != nullptr )
        {
            std::cout << currentNode->data << std::endl;
            currentNode = currentNode->next;
        }
    }
    void clear()
    {
        while ( front != nullptr )
        {
            removeBack();
        }
    }
};

// Linked List of Doubles:
struct DoubleNode
{
    char data;
    DoubleNode *next = nullptr;
};

struct DoubleLL
{
    DoubleNode *front = nullptr;
    //Methods
    DoubleNode *getBackNode()
    {
        DoubleNode *currentNode = front;
        while ( currentNode->next != nullptr )
        {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
    int size() const
    {
        DoubleNode *currentNode = front;
        int size = 0;
        while ( currentNode != nullptr )
        {
            size++;
            currentNode = currentNode->next;
        }
        return size;
    }
    void insertFront(double const data)
    {
        DoubleNode *newNode = new DoubleNode;
        newNode->data = data;
        newNode->next = front;
        front = newNode;
    }

    void insertBack(double const data)
    {
        DoubleNode *newNode = new DoubleNode;
        newNode->data = data;
        newNode->next = nullptr;
        if (front == nullptr )
        {
            front = newNode;
        }
        else
        {
            DoubleNode *backNode = getBackNode();
            backNode->next = newNode;
        }
    }

    void removeFront()
    {
        if (isEmpty())
        {
            std::cout << "List is empty " << std::endl ;
            exit(1);
        }
        else
        {
            DoubleNode *oldFront = front;
            front = front->next;
            oldFront->next = nullptr;
            delete oldFront;
        }
    }

    void removeBack()
    {
        if (isEmpty())
        {
            std::cout << "List is empty " << std::endl ;
            exit(1);
        }
        else
        {
            DoubleNode *currentNode = this->front;
            if ( currentNode->next == nullptr )
            {
                this->front = nullptr;
                delete currentNode;
            }
            else
            {
                while ( currentNode->next->next != nullptr )
                {
                    currentNode = currentNode->next;
                }
                DoubleNode *oldNode = currentNode->next;
                currentNode->next = nullptr;
                delete oldNode;
            }
        }
    }

    void removeAt(int const index)
    {
        if ( index < size() && index >= 0 )
        {
            int counterb4Index = 0;
            DoubleNode *currentNode = front;
            if ( index == 0 )
            {
                removeFront();
            }
            else
            {
                while ( counterb4Index != index - 1 )
                {
                    currentNode = currentNode->next;
                    counterb4Index++;
                }
                DoubleNode *oldNode = currentNode->next;
                currentNode->next = currentNode->next->next;
                oldNode->next = nullptr;
                delete oldNode;
            }
        }
        else
            std::cout << "invalid index: " << index << std::endl;
    }

    int getFront() const
    {
        if ( !isEmpty() ) 
        {
            return front->data;
        }
        else
        {
            std::cout << "Empty list" << std::endl;
        }    
    }


    int getAt(int index) const
    {
        if ( !(index < size()) || index < 0 )
        {
            std::cout << "invalid index" << std::endl;
        }
        else
        {
            DoubleNode *currentNode = front;
            while ( index > 0 )
            {
                currentNode = currentNode->next;
                index--;
            }
            return currentNode->data;
        }
    }

    void filter(double const data)
    {

        while ( front->data == data )
        {
            removeFront();
        }
        int index = 0;
        DoubleNode *currentNode = front;
        while ( currentNode->next != nullptr )
        {
            if ( currentNode->next->data == data )
            {
                removeAt(index + 1);
            }
            else
            {
                currentNode = currentNode->next;
                index++;
            }
        }
    }
    bool isEmpty() const
    {
        return ( front == nullptr );
    }

    void printAll() const
    {
        DoubleNode *currentNode = front;
        while ( currentNode != nullptr )
        {
            std::cout << currentNode->data << std::endl;
            currentNode = currentNode->next;
        }
    }
    void clear()
    {
        while ( front != nullptr )
        {
            removeBack();
        }
    }
};

#endif // LinkedList_HPP
