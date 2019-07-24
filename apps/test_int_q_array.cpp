#include <iostream>
#include "int_q_array.hpp"

int main()
{
    queue::IntegersQueueArray testQ;
    queue::printAll(testQ);

    std::cout << "enqueue: 9" << std::endl;
    queue::enqueue(testQ, 9);
    queue::printAll(testQ);

    std::cout << "enqueue: 12" << std::endl;
    queue::enqueue(testQ, 12);
    queue::printAll(testQ);

    std::cout << "enqueue: 33, 44" << std::endl;
    queue::enqueue(testQ, 33);
    queue::enqueue(testQ, 44);
    queue::printAll(testQ);

    std::cout << "dequeue" << std::endl;
    queue::dequeue(testQ);
    queue::printAll(testQ);

    std::cout << "dequeue" << std::endl;
    queue::dequeue(testQ);
    queue::printAll(testQ);

    std::cout << "enqueue: 12, 3, 4, 5, 6, 7, 32" << std::endl;
    queue::enqueue(testQ, 12);
    queue::enqueue(testQ, 3);
    queue::enqueue(testQ, 4);
    queue::enqueue(testQ, 5);
    queue::enqueue(testQ, 6);
    queue::enqueue(testQ, 7 );
    queue::enqueue(testQ, 32);
    queue::printAll(testQ);


    std::cout << "dequeue X3" << std::endl;
    queue::dequeue(testQ);
    queue::dequeue(testQ);
    queue::dequeue(testQ);
    queue::printAll(testQ);

}
