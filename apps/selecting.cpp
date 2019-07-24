#include<algorithm>
#include<iostream>


void selectionSort( int *array , int size )
{
    // One by one move boundary of unsorted subarray
       // Find the minimum element in unsorted array
        
        int min_idx = 0;
        for (int j = 0 ; j < size ; j++)
        {
            if ( array[j] < array[min_idx] )
                min_idx = j;
        }

        // Swap the found minimum element with the first element
        std::swap( array[min_idx] ,  array[size] );
    if ( size > 0 )     
    selectionSort(array , size-1 ) ;
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



int main ()
{
    int n = 1 ;
    int array [5] ;
    for (int i = 5 ; i >0 ; i--)
    {
        n = n*-3 ;
        array[i]=i*n ;
    }
    for (int i = 5 ; i >0 ; i--)
    {
        std::cout << array [i] << std::endl ;
    }
    selectionSort ( array , 5 ) ; 
    for (int i = 5 ; i >0 ; i--)
    {
        std::cout << array [i] << "/" ;
    }
}