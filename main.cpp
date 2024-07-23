#include <iostream>
#include "queue.hpp"

int main()
{
    kyu::queue<int> queue;
    queue.push(5);
    queue.pop();

    for (int i=0; i<15; i+=2)
    {
        queue.push(i * 5);
        std::cout << "Queue size: " << queue.size() << std::endl;
        queue.print();
    }
    for (int i=0; i<16; i++)
    {
        queue.pop();
        queue.print();
    }
    std::cout << "Queue is Empty: " << queue.empty() << std::endl;
    std::cout << "First Element: " << queue.first() << "\nLast Element: " << queue.back() << std::endl;
}
