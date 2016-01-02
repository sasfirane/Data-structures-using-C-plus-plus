// =========================================================

//HW1P1 stack
//Your name: Samir Asfirane
//Complier:  g++
//File type: source file Stack.cpp

//================================================================

#include <iostream>
#include "stack.h"
using namespace std;

// Simple Constructor using arrrays must initialize top to be -1 to begin with.
stack::stack()
{
  top = -1; // indicate an empty stack
} ;

// Simple Destructor does not have to do anything since this is a static array.
stack::~stack()
{
  // nothing to do here
};

// isEmpty returns true if top is equal to -1 which is the intial value of top
// or false if top is different than -1
bool stack::isEmpty()
{
  if (top == -1) return true; // top = -1 means stack is empty
  else return false; // otherwise it is not empty
}

// Boolena isFull checks if top = MAX-1 the biggest value top can have
// and returns true, false otherwise.
bool stack::isFull()
{
  if ((top+1) == MAX) return true; // if top = MAX-1 stack is full
  else return false; // otherwise it is not
}

// method push(el_t elem) takes a parameter of type el_t
// and pushes it into the stack after checking if stack is full or not
// by calling isFull method and if isFull returns true, throws an exception (Overflow)
// Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{
  if (isFull()) throw Overflow(); // if stack is full throws overflow exception
  else {
    top++; el[top] = elem; // if stack is not full push elem into top of the stack
  }
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
    elem = el[top]; top--; // if not empty pops the top and stores it in elem
    // and decrement the top counter
  }
}

// topElem returns the top Elem if the stack is not empty
// without removing it from the stack.topElem calls isEmpty and if true
// throws an underflow exception otherwise stores the top element
// from the stack in elem
void stack::topElem(el_t& elem)
{
  if (isEmpty())  throw Underflow(); // if stack is empty throw undeflow exception
  else { elem = el[top]; // else store a copy of top of stack in elem
  }
}

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
{  if (isEmpty()) cout << "[Empty]" << endl;
  else for (int i=top; i>=0; i--)
    { cout << el[i] << endl; }}

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
  // if the stack is empty nothing to clear
  if (isEmpty()) cout << "The stack is empty nothing to clear" << endl;
  // else if stack not empty as long as the stack is not empty
  else for (int i = top; i >= 0; i--)
    {
      pop(el[i]); // remove the top element from the stack
    }
}
