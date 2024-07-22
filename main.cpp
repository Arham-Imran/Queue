#include <iostream>
#include "queue.hpp"

int main()
{
    kyu::queue<int> queue;
    queue.en_queue(5);
    for (int i=0; i<15; i+=2)
    {
        queue.en_queue(i);
        queue.print();
    }
    for (int i=0; i<5; i++)
    {
        std::cout << "Value DeQueued: " << queue.de_queue() << std::endl;
        queue.print();
    }
    std::cout << "Value at Front: " << queue.peek() << std::endl;
    std::cout << "Queue is Empty: " << queue.is_empty() << std::endl;
}
