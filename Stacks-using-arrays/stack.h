// =======================================================

// HW1P1
// Your name: Samir Asfirane
// Compiler:  g++
// File type: headher file stack.h

//=======================================================

const int MAX = 10;   // The MAX number of elements for the stack
// MAX is unknown to the client

typedef int el_t;      // the el_t type is integer
// el_t is unknown to the client


class stack
{

 private: // to be hidden from the client

  el_t     el[MAX];       // el is  an array of el_t's
  int      top;           // top is index to the top of stack

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

  // ************ add good comments for each function *****
  bool isEmpty();
  bool isFull();
  void displayAll();
  void clearIt();

};

// Note: semicolon is needed at the end of the header file

