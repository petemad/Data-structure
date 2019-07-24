#include<algorithm>
#include<iostream>

void sort (int *array , int size  )
{
    for (int i=0 ; i<size ; i++ )
    {
        if (array [i+1] > array[i] )
        {   
            std::swap (array[i+1] , array [i] ) ;
            sort (array , size-1 ) ;
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
    sort ( array , 5 ) ; 
    for (int i = 5 ; i >0 ; i--)
    {
        std::cout << array [i] << "/" ;
    }
}
