#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"
template<typename T>
class Queue {
    private:
        Node<T> *mHead;
        Node<T> *mTail;
    public:
        // default
        Queue();
        ~Queue();
        Queue(const Queue<T>& OTHER);
        // method
        void push(T VAL);
        T peak();
        T pop();
        bool isEmpty();
};

// default
template<typename T>
Queue<T>::Queue();
template<typename T>
Queue<T>::~Queue();
template<typename T>
Queue<T>::Queue(const Queue<T>& OTHER);
// method
template<typename T>
void Queue<T>::push(T VAL);
template<typename T>
T Queue<T>::peak();
template<typename T>
T Queue<T>::pop();
template<typename T>
bool Queue<T>::isEmpty();
#endif