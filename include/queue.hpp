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
        void push(T);
        void pop();
        T first();
        T back();
        bool empty();
        int size();
        void print();
    };

    template <class T>
    queue<T>::queue() : front(NULL), rear(NULL) {}

    template <class T>
    void queue<T>::push(T new_val)
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
    void queue<T>::pop()
    {
        if(front == NULL)
            return;
        else
        {
            Node<T>* temp = front;
            T temp_val = temp->val;
            front = front->next;
            delete temp;
            if(front == NULL)
                rear = NULL;
        }
    }

    template <class T>
    T queue<T>::first()
    {
        if(front != NULL)
            return front->val;
        else
            return T();
    }

    template <class T>
    T queue<T>::back()
    {
        if(front != NULL)
            return rear->val;
        else
            return T();
    }

    template <class T>
    bool queue<T>::empty()
    {
        if(front == NULL)
            return true;
        else
            return false;
    }

    template <class T>
    int queue<T>::size()
    {
        Node<T>* temp = front;
        int queue_size = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            queue_size++;
        }
        return queue_size;
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
            std::cout << temp->val << "<--rear"<<std::endl; 
        }
        else
        {
            std::cout << "NULL"<<std::endl;
        }
    }
}

#endif