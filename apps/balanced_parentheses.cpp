#include <iostream>
#include "Stack.hpp"

int main(int argc, char **argv)
{
    std::string input;
    std::cin >> input;
    int stringSize = input.size();
    CharStack theStack;
    for (int i = 0; i < stringSize; i++)
    {
        if (input[i] == '(')
        {
            theStack.push(input[i]);
        }
        else
        {
            if (theStack.isEmpty())
            {
                std::cout << "Unbalanced" << std::endl;
                exit(0);
            }

            else
                theStack.pop();
        }
    }

    if (theStack.isEmpty())
    {
        std::cout << "balanced" << std::endl;
    }

    else
        std::cout << "Unbalanced" << std::endl;
}
