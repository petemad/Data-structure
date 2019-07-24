#include<algorithm>

int factorial (int x)
{    
    if (x-1 != 0 )
    {
        return  x * factorial (x-1) ;
    }  
}

int power (int x , int y)
{
    if (y != 1)
    {
        return x * power (x , y-1) ;
    }
}

void bubbleSort (int *array , int size  )
{
    for (int i=0 ; i<size ; i++ )
    {
        if (array [i+1] > array[i] )
        {   
            std::swap (array[i+1] , array [i] ) ;
            bubbleSort (array , size-1 ) ;
        }
    }
}

