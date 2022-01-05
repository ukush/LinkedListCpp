#include "LinkedList.h"


//------------------------------------------------------------- Linked List ---------------------------------------------//
// constructor
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr)
{

}

// destructor
template <typename T>
LinkedList<T>::~LinkedList()
{

}


template <typename T>
int LinkedList<T>::getNoOfItems() // recursive
{
	return (head ? head->getNoOfItems() : 0);
}


template<typename T>
LLNode<T>* LinkedList<T>::getHead()
{
	return head;
}

template<typename T>
LLNode<T>* LinkedList<T>::getTail()
{
	return tail;
}

template<typename T>
void LinkedList<T>::addFront(T item)
{
	LLNode<T>* newHead = new LLNode<T>(item, head);
	head = newHead;

}


//--------------------------------------- LLNode ------------------------------------//


template<typename T>
template<typename U>
LinkedList<T>::LLNode<U>::LLNode()
{
}

// nested LL node Class
template <typename T>
template <typename U>
LinkedList<T>::LLNode<U>::LLNode(const U data, LLNode<U>* next) : data(data), next(next)
{
}

template <typename T>
template <typename U>
LinkedList<T>::LLNode<U>::~LLNode()
{
	delete next;
}


template <typename T>
template <typename U>
void LinkedList<T>::LLNode<U>::setNext(LLNode<U>* next)
{
	this->next = next;
}

template <typename T>
template <typename U>
LinkedList<T>::LLNode<U>* LinkedList<T>::LLNode<U>:: getNext() const
{
	return next;
}

template <typename T>
template <typename U>
U LinkedList<T>::LLNode<U>:: getData()
{
	return data;
}

template<typename T>
template<typename U>
int LinkedList<T>::LLNode<U>::getLength()
{
	return (next ? 1 + next->getLength() : 1);
}

template<typename T>
template<typename U>
void LinkedList<T>::LLNode<U>::setData(U item)
{
	data = item;
}

