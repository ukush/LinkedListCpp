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

