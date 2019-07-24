#include <iostream>
#include "Stack.hpp"
int main(int argc, char **argv)
{
    int numDays = 0;
    std::cout << "Enter Number of days:" << std::endl;
    std::cin >> numDays;
    int *arrayOfDays = new int[numDays];
    std::cout << "Enter the Array of Days:" << std::endl;
    for (int i = 0; i < numDays; i++)
    {
        std::cin >> arrayOfDays[i];
    }
    int *spanArray = new int[numDays];
    IntegerStack theStack;
    for (int i = 0; i < numDays; i++)
    {
        spanArray[i] = 0;
    }
    for (int i = 0; i < numDays; i++)
    {
        while(spanArray[i]==0){
            if(theStack.isEmpty()) spanArray[i]=i+1;
            else {
                if(arrayOfDays[i]>arrayOfDays[theStack.front()]){
                    theStack.pop();
                }
                else spanArray[i]=i-theStack.front();
            }
        }
        theStack.push(i);
    }

    for(int i=0;i<numDays;i++){
        std::cout<<spanArray[i]<<" ";
    }
}
