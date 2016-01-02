// =======================================================

// HW1P1 Queue
// Your name: Samir Asfirane
// Compiler:  g++ compiler
// File type: queue header file queue.cpp

//=====================================================

#include <iostream>

#include "queue.h"

using namespace std;

// Simple Constructor using arrrays must initialize all variables to 0
queue::queue()
{
	count = 0;  // no elements at the beginning 
	front = 0;  // front element initialized to 0
	rear = 0;   // rear element initialized to 0
}

// Simple Destructor does not have to do anything 
queue::~queue() {};

// In the isEmpty() function we check if count is zero then the
// queue is empty and we return true otherwise it is not empty and we return false
bool queue::isEmpty()
{
	if (count == 0)
		return true;  // count = 0 queue is empty
	else
		return false; // count !=0 queue is not empty
}

// The queue is full if count is equal to the size of the array
// which is in this case MAX_SIZE
bool queue::isFull()
{
	if (count >= MAX_SIZE)
		return true; // count >= MAX_SIZE queue is full
	else
		return false; // count < MAX_SIZE queue is not full
}

// function getSize() to return the number of elements in the
// queue in this case count to make accessible to the client
int queue::getSize()
{
	return(count);
}

// Displays "[ empty ]" if the queue is currently empty.
// Otherwise, displays each element, horizontally, in order from front to rear.
void queue::displayAll()
{
	if (isEmpty())
	{
		cout << "[ empty ]" << endl; // if queue is empty display empty brackets
	}
	else
	{
		// if queue is not empty there is at least one element to display
		int i = front; // front element is the first to be displayed
		cout << "[ ";
		do
		{
			cout << el[i] << " "; // display first element
			i = (i + 1) % MAX_SIZE; // incerment the index in a way to wrap around the array
			// when the rear element is wrapped around the array
		} while (i != rear+1); // do that as long as i is at the most equal to the rear element index
		cout << "]" << endl;
	}
}


// Adds an element to the end of the line (at array[rear])
// Checks that there is room on the array, throwing overflow if needed.
// Leaves handling the overthrow to the client
// Otherwise:
// 	place elem at array[rear]
// 	increment the counter var
// 	and change the new rear slot to be rear+1, wrapping around.
void queue::add(el_t elem)
{
	if (isFull())
	{
		throw Overflow(); // if queue is full throw exception
	}
	else
	{
		
		if (count == 0) el[rear] = elem; // if no elements in queue add element at the rear
		else el[(rear + 1) % (MAX_SIZE)] = elem; // else add element after the rear element
		// and wrap around the array if necessary
		count++;
		if (count <= 1) rear = 0; // this is to make sure when there is 1 element rear still points 
		// at the first which front and rear element at the same time
		else rear = (rear + 1) % (MAX_SIZE);  // if the queue has more than 1 element 
		// the rear should be at least 1 and incremented each time we add an element 
		// in a way that allows to wrap around the array 
		
	}
}

// PURPOSE: function add(el_t) takes a reference to a string as parameter 
// if empty an exception is caught and error message displayed
// if not empty, removes the front element to give it back 
// HOW TO CALL: provide a holder for the element removed (pass by ref)
void queue::remove(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow(); // if queue is empty throw Underflow exception
	}
	else
	{
		elem = el[front]; // else if queue not empty store front in elem
		count--; // decrement number of element in queue
		front = (front + 1) % (MAX_SIZE);  // increment the front in away to wrap the array around
	}
}

// PURPOSE:function frontElem if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// TO CALL: provide a holder for the element (pass by ref)
void queue::frontElem(el_t& elem)
{
	if (isEmpty())
	{
		throw Underflow(); // if queue is empty throw Underflow exception
	}
	else
	{
		elem = el[front]; // if not empty copy front into elem but don't remove it
	}
}

// PURPOSE: if empty, throws an exception Underflow
// if queue has just 1 element, does nothing
// if queue has more than 1 element, moves the front one to the rear
// function takes no argument and returns none
void queue::goToBack()
{
	if (isEmpty())
	{
		throw Underflow(); // if queue is empty throw Underflow exception
	}
	else if (getSize() == 1) // if there is only one element no going back is needed
	{
	 // nothing happens here as no action is needed
	}
	else
	{
		el_t elem; // declare an elem
		remove(elem); // by definition remove(elem) removes the front
		add(elem); // add will add the element removed to the rear
	}
}

// PURPOSE: returns the index the front element in the queue
// if the queue is empty throws Underflow exception
int queue::getFront(){
	if (isEmpty())
	{
		throw Underflow(); // if queue is empty throw Underflow exception
	}
	else 	return front; // return front element index to the client
}


// PURPOSE: returns the index the index of the rear
// element if the queue is empty throws Underflow exception
int queue::getRear(){
	if (isEmpty())
	{
		throw Underflow(); // if queue is empty throw Underflow exception
	}
	return rear; // return rear element index to the client
}

