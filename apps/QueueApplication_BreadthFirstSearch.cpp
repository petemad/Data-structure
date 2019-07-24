#include <iostream>

/* The application outputs the number of timeframes needed for an infection to spread in a matrix of 
   infected (insert 2), healthy (insert 1), and vaccinated (insert 0) individuals 
   till the entire matrix is infected. It also outputs the state of the matrix after the maximum 
   spread of infection. The infection can only spread vertically and horizontally not diagonally.
   The size of the matrix is determined by the user. */

int row;      //global variables for input matrix
int column;

struct CellCoordinates  
{
    int x = 0;
    int y = 0;
    CellCoordinates *next = nullptr;
};

struct LLQueue
{
    CellCoordinates *head = nullptr;
    CellCoordinates *rear = nullptr;
    //Methods
    void enqueue ( CellCoordinates *cell )
    {

        if ( isEmpty() )
        {
            this->head = cell;
            this->rear = cell;
        }
        else
        {
            rear->next = cell;
            rear = rear->next;
        }

    }

    void dequeue ()
    {
        if ( isEmpty() )
        {
            exit(1);
        }
        else
        {
            CellCoordinates *oldFront = new CellCoordinates;
            oldFront = this->head;
            this->head = this->head->next;
            delete oldFront;
        }
    }

    bool isEmpty()
    {
        return ( head == nullptr );
    }
};

bool isValid ( int x, int y)
{
    return ( x >= 0 && y >= 0 && x < row && y < column);
}



int main()
{
    LLQueue infected;
    std::cout << "Insert number of rows and columns : "<< std::endl;
    std::cin >> row >> column;
    int **sample = new int*[row];
    std::cout << " Insert matrix sample in rows then columns : " << std::endl;
    
    for ( int i = 0; i < row ; i++ )
        {
            sample[i] = new int[column];             
        }
    for ( int i = 0; i < row ; i++)
    {
        for ( int j = 0; j < column ; j++)
        {
            std::cin >> sample[i][j];
            if ( sample[i][j] == 2 )
            {   
                CellCoordinates *cell = new CellCoordinates;
                cell->x = i;
                cell->y = j;
                infected.enqueue( cell );
                
            }

        }
    }
    CellCoordinates *separate = new CellCoordinates;
    separate->x = -1;
    separate->y = -1;
    infected.enqueue( separate );
    int timeFrame = 0;
    
    CellCoordinates *temp = new CellCoordinates;
    while ( infected.isEmpty() == false )
    {
        bool once = false;
        while ( infected.head->x != -1 && infected.head->y != -1 )
        {
            temp = infected.head;
            
            //check up cell if it can be infected and infect it if it can
            if( isValid ( temp->x - 1, temp->y) && sample[temp->x-1][temp->y] == 1 )
            {
                
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[temp->x-1][temp->y] = 2;
                newCell->x = temp->x - 1;
                newCell->y = temp->y;
                infected.enqueue(newCell);
            } 
            //check down cell

             if( isValid ( temp->x+1, temp->y) && sample[temp->x+1][temp->y] == 1 )
            {
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[temp->x+1][temp->y] = 2;
                newCell->x = temp->x + 1;
                newCell->y = temp->y;
                infected.enqueue(newCell); // push new infected in queue
            } 

            //check right

             if( isValid ( temp->x, temp->y+1) && sample[temp->x][temp->y+1] == 1 )
            {
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[temp->x][temp->y+1] = 2;
                newCell->x = temp->x;
                newCell->y = temp->y + 1;
                infected.enqueue(newCell); 
            } 

            //check left

             if( isValid ( temp->x, temp->y-1) && sample[temp->x][temp->y-1] == 1 )
            {
                // increment timeFrame frame only once
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[temp->x][temp->y-1] = 2;
                newCell->x = temp->x;
                newCell->y = temp->y - 1;
                infected.enqueue(newCell);
            } 

            infected.dequeue();
        }
        
         
        //finished first timeFrame i.e. reached separate
        infected.dequeue();

        if ( !infected.isEmpty() )
        {
            CellCoordinates *newSeparate = new CellCoordinates;
            newSeparate->x = -1;
            newSeparate->y = -1;
            infected.enqueue ( newSeparate );
        }
       

    }

    bool healthyRemains = false;
    std::cout << "The final sample after spread of infection is: " << std::endl;
    for ( int i = 0; i < row ; i++)
    {
        for ( int j = 0; j < column ; j++)
        {
            if ( sample[i][j] == 1)
            healthyRemains = true; 
            std::cout << sample[i][j] << std::endl; 
                     
        }
    }
    if ( healthyRemains )
    {
        std::cout << "Not all will be infected" << std::endl;
    }
    else
    {
        std::cout << "The minimum time Frame for total infection is "<< timeFrame << std::endl;
    }

  

    return 0;
}












