
#include <iostream> 

int fact( int n )
{
    if( n == 0 )
        return 1;
    else
        return n * fact ( n - 1 );
}

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


int main ()
{
    int x=0 ;
    int x2=0 ;
    int y=0 ;
    std::cout << "input = " ;
    std::cin >> x ; 
    std::cout << "factorial =" << factorial (x) << std::endl ;
    std::cout << "x = " ;
    std::cin >> x2 ;
    std::cout << "^" ;
    std::cin >> y ;
    std::cout << power (x2 , y) << std::endl ;
}
