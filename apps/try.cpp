#include <iostream>

struct node
{
    int data;
    node *next = nullptr ;
};

struct LL 
{
    node *head = nullptr ;
    node *rear = nullptr ;

};


    
void insertback ( LL &list , int data )
{
    node *newnode = new node ;
    if (list.head == nullptr )
    {
        list.rear = newnode ;
        list.head = newnode ;
    }
    list.rear->next = newnode ;
    newnode->data = data ;
    newnode->next = nullptr ;
    list.rear = newnode ;
    
}

void printAll (LL &lst)
    {  
        node *temp = lst.head ; 
        while ( temp != nullptr)
        {
            std::cout << temp->data << "," ;
            temp = temp->next ;
        }
        std::cout << std::endl;
    }

int main()
{
    LL lst ;

    for (int i = 0 ; i < 10 ; ++i )
    {
        int input = 0 ;
        std::cout << "elements " << i << " : " ;
        std::cin >> input ;
        insertback (lst , input );
    }
   printAll (lst);
   return 0; 
    
}
