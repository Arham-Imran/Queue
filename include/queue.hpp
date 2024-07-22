#ifndef __QUEUE__
#define __QUEUE__
#include <iostream>

namespace kyu
{
    template <class T>
    struct Node
    {
        T val;
        Node<T>* next;
        Node(T);
    };

    template <class T>
    Node<T>::Node(T new_val) : val(new_val), next(nullptr) {}

    template <class T>
    class queue
    {
        private:
        Node<T> *front, *rear;

        public:
        queue();
        void en_queue(T);
        T de_queue();
        T peek();
        bool is_empty();
        void print();
    };

    template <class T>
    queue<T>::queue() : front(NULL), rear(NULL) {}

    template <class T>
    void queue<T>::en_queue(T new_val)
    {
        if(front == NULL)
        {
            front = new Node<T>(new_val);
            rear = front;
        }
        else
        {
            Node<T>* temp = new Node<T>(new_val);
            rear->next = temp;
            rear = rear->next;
        }
    }

    template <class T>
    T queue<T>::de_queue()
    {
        Node<T>* temp = front;
        T temp_val = temp->val;
        front = front->next;
        delete temp;
        if(front == NULL)
            rear = NULL;
        return temp_val;
    }

    template <class T>
    T queue<T>::peek()
    {
        return front->val;
    }

    template <class T>
    bool queue<T>::is_empty()
    {
        if(front == NULL)
            return true;
        else
            return false;
    }

    template <class T>
    void queue<T>::print()
    {
        if(front != NULL)
        {
            std::cout << "front-->";
            Node<T>* temp = front;
            while(temp->next != NULL)
            {
                std::cout << temp->val << "-->";
                temp = temp->next;
            }
            std::cout << temp->val << "<--rear\n"; 
        }
        else
        {
            std::cout << "NULL\n";
        }
    }
}

#endif