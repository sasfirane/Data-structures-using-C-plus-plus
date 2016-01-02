// =======================================================

// HW1P2
// Your name: Samir Asfirane
// Compiler:  g++ 
// File type: headher file vstack.h

//=======================================================

#include <vector> 
using  std::vector;

typedef int el_t;      // the el_t type is integer 
// el_t is unknown to the client


class stack
{

private: // to be hidden from the client

	vector<el_t> el;       // el is vector of element type el_t
	

public: // prototypes to be used by the client

	// exception handling classes  
	class Overflow{};
	class Underflow{};

	stack();   // constructor
	~stack();  // destructor  

	// HOW TO CALL: pass the element to be pushed
	// PURPOSE: if not full, enters an element at the top;
	//          otherwise throws an exception - Overflow
	void push(el_t);

	// HOW TO CALL: provide variable to receive the popped element
	// PURPOSE: if not empty, removes and gives back the top element;
	//          otherwise throws an exception - Underflow
	void pop(el_t&);

	// HOW TO CALL: provide variable to receive the top element
	// PURPOSE: if not empty, gives the top element without removing it;
	//          otherwise, throws an exception - Underflow
	void topElem(el_t&);

	// HOW TO CALL: takes no arguments and returns no arguments
	// PURPOSE: if full returns true, and if not full returns false
	bool isFull();

	// HOW TO CALL: takes no arguments and returns a boolean
	// PURPOSE: if not empty, returns false, if empty returns
	// true
	bool isEmpty();

	// HOW TO CALL: takes no arguments and returns no arguments
	// PURPOSE: if empty display a message saying nothing to display
	// if not empty display all the elements of the stack from top
	// to bottom
	void displayAll();

	// HOW TO CALL: takes no arguments and returns no arguments
	// PURPOSE: if empty does nothing, else clears the stack of
	// all its elements
	// to bottom
	void clearIt();

};

// Note: semicolon is needed at the end of the header file

