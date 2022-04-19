#ifndef DOUBLYNODE_HPP
#define DOUBLYNODE_HPP
/**
 * @brief a single element of a doubly linked list
 * 
 */
template<typename T>
struct DoublyNode {
    /**
     * @brief the value of the node
     * 
     */
    T value;
    /**
     * @brief pointer to the next element of the doubly linked list
     * 
     */
    DoublyNode<T> *pNext;
    /**
     * @brief pointer to the last element of the doubly linked list
     * 
     */
    DoublyNode<T> *pLast;
};
#endif