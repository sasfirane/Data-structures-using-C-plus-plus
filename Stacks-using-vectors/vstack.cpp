// =========================================================

//HW1P1 stack
//Your name: Samir Asfirane
//Complier:  g++
//File type: source file vstack.cpp

//================================================================

#include <iostream> 
#include "vstack.h"
using namespace std;

// Simple Constructor does nothing
stack::stack()
{
	// nothing to do in here
};

// Simple destructor that makes sure the vector is deleted once the work is done
stack::~stack()
{
	while (!el.empty())  el.pop_back(); //as long as there are elements delete the element
};

// Boolean isEmpty calls vector member method empty() and
// checks if vector implementing the stack is empty if it is
// returns true, if it isn't it returns false
// function isEmpty takes no argument and returns boolean
bool stack::isEmpty()
{
	if (el.empty()) return true; // the vector is empty 
	else return false; // otherwise it is not empty
}

// boolean isFull checks if stack is full and since we using
// a vector it is never going to be full and will always return
// false and never return true. 
// function takes no arguments and return a boolean
bool stack::isFull()
{
	return false;
}

// method push(el_t elem) takes a parameter of type el_t
// and pushes it into the stack, function takes an argument
// of type el_t and return no arguments
void stack::push(el_t elem)
{
	el.push_back(elem); // element is added at the end of the top of the stack
}

// method pop(el_t elem) takes a reference to an element elem 
// and pops the top of the stack into elem if stack is not empty. 
// pop checks first if stack is empty by calling is empty method 
// and if stack is empty throws an underflow exception, 
// if not empty pops the top element and store it into elem
// and decrement the top counter
void stack::pop(el_t& elem)
{
	if (isEmpty()) throw Underflow(); // if stack is empty throws underflow exception
	else {
		elem = el.at(el.size()-1); // if not empty assigns the last element in the
		// vector which is at position size()-1 to elem
		el.pop_back(); // and then removes the element from the vector
	}
}

// topElem returns the top Elem if the stack is not empty
// without removing it from the stack.topElem calls isEmpty and if true
// throws an underflow exception otherwise stores the top element
// from the stack in elem
void stack::topElem(el_t& elem)
{
	if (isEmpty())  throw Underflow(); // if stack is empty throw undeflow exception
	else {
		elem = el.at(el.size()-1); // if stack is not empty returns element at position size()-1
		// which is the last element in the vector and stores it in elem without removing it
	}
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{
	if (isEmpty()) cout << "[Empty]" << endl; // if empty display empty brackets

	// otherwise starting from the last position size()-1 display all the elements
	else for (int i = el.size()-1; i >= 0; i--)
	{
		cout << el[i] << endl; // go to the next line after displaying each element
	}
}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
	// if the stack is empty nothing to clear
	if (isEmpty()) cout << "The stack is empty nothing to clear" << endl;
	// else if stack not empty as long as the stack is not empty
	else el.clear();
}
