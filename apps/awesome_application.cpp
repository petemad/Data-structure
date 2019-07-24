#include <iostream>

// The same as Merna's BFS but with a little different Logic 


int row;
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
    void enqueue(CellCoordinates *cell)
    {

        if (isEmpty())
        {
            cell->next = nullptr;
            this->head = cell;
            this->rear = cell;
        }
        else
        {
            cell->next = nullptr;
            rear->next = cell;
            rear = cell;
        }
       
    }

    void dequeue()
    {
        
        if (isEmpty())
        {
            exit(1);
        }
        else
        {
            CellCoordinates *oldFront = this->head;
            this->head = this->head->next;
            delete oldFront;
        }
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }
};

bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < row && y < column);
}

int main()
{
    LLQueue rotten;
    std::cout << "insert rows and columns : " << std::endl;
    std::cin >> row >> column;
    int **arr = new int *[row];
    std::cout << " insert matrix row then column: " << std::endl;

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[column];
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            std::cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                CellCoordinates *cell = new CellCoordinates;
                cell->x = i;
                cell->y = j;
                rotten.enqueue(cell);
            }
        }
    }
    CellCoordinates *separate = new CellCoordinates;
    separate->x = -1;
    separate->y = -1;
    rotten.enqueue(separate);
    int time = 0;
    CellCoordinates *temp;
    while (!rotten.isEmpty())
    {

        if (rotten.head != separate)
        {
            temp = rotten.head;
         
            //check left cell if it can be infected and infect it if it can
            if (isValid(temp->x - 1, temp->y) && arr[temp->x - 1][temp->y] == 1)
            {
               
                // increment time frame only once
                CellCoordinates *newCell = new CellCoordinates;
                arr[temp->x - 1][temp->y] = 2;
                temp->x--;
                newCell->x = temp->x;
                newCell->y = temp->y;
                rotten.enqueue(newCell);
                temp->x++;
            }
            //check right cell

            if (isValid(temp->x + 1, temp->y) && arr[temp->x + 1][temp->y] == 1)
            {
                
                // increment time frame only once
                CellCoordinates *newCell = new CellCoordinates;
                arr[temp->x + 1][temp->y] = 2;

                newCell->x = temp->x + 1;
                newCell->y = temp->y;
                rotten.enqueue(newCell); // push new infected in queue
                                         // return to original cell to check other directions
            }

            //check up

            if (isValid(temp->x, temp->y + 1) && arr[temp->x][temp->y + 1] == 1)
            {
                
                // increment  time frame only once
                CellCoordinates *newCell = new CellCoordinates;
                arr[temp->x][temp->y + 1] = 2;
                temp->y++;
                newCell->x = temp->x;
                newCell->y = temp->y;
                rotten.enqueue(newCell);
                temp->y--;
            }

            //check down

            if (isValid(temp->x, temp->y - 1) && arr[temp->x][temp->y - 1] == 1)
            {
               
                // increment time frame only once
                CellCoordinates *newCell = new CellCoordinates;
                arr[temp->x][temp->y - 1] = 2;

                newCell->x = temp->x;
                newCell->y = temp->y - 1;
                rotten.enqueue(newCell);
            }

            rotten.dequeue();
        }

        else
        {

            rotten.dequeue();
            if (!rotten.isEmpty())
            {
                time++;
                separate = new CellCoordinates;
                separate->x = -1;
                separate->y = -1;
                rotten.enqueue(separate);
            }
        }
    }

    bool healthyRemains = false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] == 1)
                healthyRemains = true;
        }
    }
    if (healthyRemains)
    {
        std::cout << "Not all will be infected" << std::endl;
    }
    else
    {
        std::cout << "The minimum time for total infection is " << time;
    }

    return 0;
}
