//lang::CwC
/*
* Authors: Leslie Xie, Bojun Lin
*
*
*/
#pragma once

#include "object.h"
#include <cstdio>

//Interface for Queue class, a child of the Object class.

#define DEFAULT_SIZE 5

class Queue : public Object {

public:

	Object** elements;	//the elements in the Queue
	int capacity;		//max size of a Queue
	int size;			//current amount of elements in Queue
    int popped;         //amount of elements that are popped

	/*
	* Constructor.
	*/
	Queue() 
	{
		elements = new Object*[DEFAULT_SIZE]();
		capacity = DEFAULT_SIZE;
		size = 0;
		popped = 0;
	}

	/*
	* Constructor that creates a Queue with a non-default capacity
	*/
	Queue(int diffCapacity)
	{
		elements = new Object*[diffCapacity]();
		capacity = diffCapacity;
		size = 0;
		popped = 0;
	}
	
	/*
	* Deconstructor.
	*/
	~Queue() 
	{
		delete elements;
	}

	/*
	* Adds o to the rear of this Queue.
	*
	* @param o is the object to add to this Queue.
	*/
	void enqueue(Object* o) 
	{
		if (is_queue_full()) 
        {
			capacity *= 2;
            Object** temp = new Object*[capacity]();
            memcpy(temp, (elements + popped), (size - popped) * sizeof(Object*));
            delete[] elements;
            elements = temp;
            size -= popped;
            popped = 0;
		}
		
        elements[size] = o;
        size++;
	}

	/*
	* Removes the Object at the front of this Queue.
	*
	* @return Object* at the front of this Queue.
	*/
	Object* dequeue() 
	{
		if (is_queue_empty())
		{
			printf("This queue is already empty. Cannot dequeue.");
			return nullptr;
		}
		else
		{
            Object *ret = elements[popped];
            popped ++;
			return ret;
		}
	}

	/*
	* Returns the object at the front of this Queue without
	* removing it.
	*
	* @return Object* at the front of this Queue.
	*/
	Object* peek() 
	{
		if (!is_queue_empty()) {
			return elements[popped];
		}
		else
		{
			return nullptr;
		}
	}

	/*
	* Is this Queue empty?
	*
	* @return bool True if this Queue is empty, false if not.
	*/
	bool is_queue_empty() 
	{
		return !(size - popped);
	}

	/*
	* Is this Queue full?
	
	* @return bool True if this Queue is full, false if not
	*/
	bool is_queue_full()
	{
		return (size == capacity);
	}
	/*
	* Returns the length of this Queue.
	*
	* @return int number of elements in this Queue.
	*/
	int get_queue_length() 
	{
		return size - popped;
	}

	/*
	* Generates a hash code unique to this Queue.
	*/
	size_t hash() 
	{
		size_t ret = 4096;
		for (int ii = popped; ii < size; ii++)
		{
			ret += elements[ii]->hash();
		}
		return ret;
	}


	/*
	* Is this Object equal to the given one?
	*
	* @param other The object to check against this.
	*
	* @return true if other equates this, false if not.
	*/
	bool equals(Object* other)
	{		
		return (this->hash() == other->hash());
	}
};