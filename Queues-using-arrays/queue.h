// =======================================================

// HW1P1 Queue
// Your name: Samir Asfirane
// Compiler:  g++ compiler
// File type: queue header file queue.h

//=====================================================


# include <string>

using namespace std;

typedef string el_t; // el_t is an alias for the data type string

const int MAX_SIZE = 25;  // define MAX size as 25 to display 25 string at least

class queue  {

private:
	// Data members are:
	el_t el[MAX_SIZE]; // an array called el.
	//  Elements will be found between front and rear but
	// front may be behind rear since the queue wraps around
	int  count;          // how many elements do we have right now?
	int  front;          // where the front element of the queue is.
	int  rear;           // where the rear element of the queue is.

public:    // prototypes to be used by the client

	// constructor 
	queue();

	//destructor 
	~queue();

	// Exception handling classes.
	class Overflow {};  // Class Overflow to capture overflow exceptions when queue is full
	class Underflow {}; // Class Underflow to capture Underflow exceptions when queue is empty
	

	// PURPOSE:function isEmpty takes no argument and return a boolean
    //  returns true if queue is empty, otherwise false
	bool isEmpty();

	// PURPOSE:function isFull takes no argument and return a boolean
	// returns true if queue is full, otherwise false
	bool isFull();

	// PURPOSE: function add(el_t) takes a string as parameter 
	// and adds it to the array if full, throws an exception Overflow
	// if not full, enters an element at the rear 
	// HOW TO CALL: provide the element to be added
	void add(el_t);

	// PURPOSE: function add(el_t) takes a reference to a string as parameter 
	// if empty an exception is caught and error message displayed
	// if not empty, removes the front element to give it back 
	// HOW TO CALL: provide a holder for the element removed (pass by ref)
	void remove(el_t&);

	// PURPOSE:function frontElem if empty, throws an exception Underflow
	// if not empty, give back the front element (but does not remove it)
	// TO CALL: provide a holder for the element (pass by ref)
	void frontElem(el_t&);

	// PURPOSE: function getSize() takes no arguments
	// and returns the number of elements in the queue
	int getSize();

	// PURPOSE: display everything in the queue from front to rear
	//  enclosed in []
	// if empty, displays [ empty ]
	void displayAll();

	// PURPOSE: if empty, throws an exception Underflow
	// if queue has just 1 element, does nothing
	// if queue has more than 1 element, moves the front one to the rear
	// function takes no argument and returns none
	void goToBack();

	// PURPOSE: returns the index the front element in the queue
	// if the queue is empty throws Underflow exception
	int getFront();


	// PURPOSE: returns the index the index of the rear
	// element if the queue is empty throws Underflow exception
	int getRear();


};

