#pragma once
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{

private:
	
	template <typename U>
	class LLNode
	{
	private:
		U data; // the data stored in the node (can be any object)
		LLNode<U>* next; // pointer to the next node in the list

	public:
		// constructor
		LLNode();
		LLNode(const U data, LLNode<U>* next); // takes in the data and the next node (can be nullptr)
		//destructor
		~LLNode();

		void setNext(LLNode<U>* next); // sets the next node in the list
		LLNode<U>* getNext() const;
		U getData();

		int getLength();
		void setData(U item); 
	};

	LLNode<T>* head;
	LLNode<T>* tail;

public:

	LinkedList();
	~LinkedList();

	int getNoOfItems();

	// ------------------- These two methods are giving me trouble ---------------------------//
	LLNode<T>* getHead();
	LLNode<T>* getTail();


	void addFront(T item);

};

// this all needs going into the header file (from the CPP file)

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
	return (head?head->getNoOfItems():0);	// you need to implement the getNoOfItems in the LLNode nested class
}

// try this definition, although you probably don't want to provide these methods as public because items in a linked list should just
// be accessed via index (or iterator) using a get or elementAt method.  Not entirely sure what would happen here either as logically it doesn't make sense: your LLNode 
// is a private inner class, which is correct, but this method allows the outside world to see a LLNode (and potentially change it).  
// A real-world example is a car engine that has lots of working parts to make it work, but all private to the engine to allow it to operate.  
// You interact with the engine using the accelerator and that is all.  
// Your code kind of allows the outside world to get the engine pistons and maybe change them, which is not what you want and if it is, then the inner class should be declare public

template<typename T>
LinkedList<T>::LLNode<T>* LinkedList<T>::getHead()
{
	return head;
}

// try this definition
template<typename T>
LinkedList<T>::LLNode<T>* LinkedList<T>::getTail()
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
LinkedList<T>::LLNode<U>* LinkedList<T>::LLNode<U>::getNext() const
{
	return next;
}

template <typename T>
template <typename U>
U LinkedList<T>::LLNode<U>::getData()
{
	return data;
}

template<typename T>
template<typename U>
int LinkedList<T>::LLNode<U>::getLength()
{
	return (next?1 + next->getLength():1);
}

template<typename T>
template<typename U>
void LinkedList<T>::LLNode<U>::setData(U item)
{
	data = item;
}

