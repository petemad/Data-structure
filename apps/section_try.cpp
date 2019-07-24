#include <iostream>

void  RGB ( int *r , int *b , int *g , int *gray );

int main()
{
    int red[6] = {50,60,70,80,90,100} ;
    int blue[6] = {100,110,120,130,140,150} ;
    int green[6] = {200,210,220,230,240,250} ;
    int gray[6];
    RGB ( &red[0] , &blue[0] , &green[0] , &gray[0] ) ;
    for (int i=0 ; i < 5; ++i )
        {
            std::cout << gray[i] << ",";
        }   
    std::cout << std::endl ;
}

//functions

void  RGB ( int *r , int *b , int *g , int *gray )
{
   
    for ( int i=0 ; i < 6 ; ++i)
        {
            gray[i]=(r[i]+g[i]+b[i])/3 ;
        }
               
}        