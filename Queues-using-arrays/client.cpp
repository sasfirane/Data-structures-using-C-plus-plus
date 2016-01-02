// =======================================================

// HW1P1 Queue
// Your name: Samir Asfirane
// Compiler:  g++ compiler
// File type: queue header file client.cpp

//=====================================================

#include <iostream>

#include "queue.h"

#include <string>

using namespace std;

int main()
{
	queue queue1; // declare a queue1 of type queue

	// 
	try
	{
		
		queue1.add("A");	// add string "A" to the queue	
		queue1.add("B");	// add string "B" to the queue	
		queue1.add("C");    // add string "C" to the queue
		// display some useful information
		cout << "Count = " << queue1.getSize() << " ";  // displays the number of elements in queue1 so far
		cout << "Front = " << queue1.getFront() << " "; // displays the index of the front element in the queue
		cout << "Rear = " << queue1.getRear() << " ";   // displays the index of the rear element in the queue
		// go to the next line
		cout << endl;
		// displays all the elements in the queue with brackets by calling displayAll()
		queue1.displayAll();
		// go to the next line
		cout << endl;
	}
	
	catch (queue::Overflow)  // if there is no room for elements to be added
	{
		cout << "The queue is Full" << endl; // display an error message 
		cout << "Adding elements is impossible at this time! " << endl;
	}

	// we start removing elements from the front and concatenate 
	// them to A, B and C and adding them back to the queue
	// until there is no room to do so and the program throws an overflow 
	// exception and quits
	while (true) // as long as we can
	{
		el_t elem; // declare an elem of type el_t

		// Get elem from the front of the queue
		try
		{
			queue1.remove(elem); // remove the front
		}
		// If the queue is empty throws an exception
		catch (queue::Underflow)
		{
			cout << "The queue is empty, there are no elements in the queue! " << endl;
		}
		// display the element removed after it was removed
		cout << elem << endl;

		// Concatenate the removed element with A, B and C to the front
		try
		{
			queue1.add(elem + 'A'); //concatenate the removed element to the front of "A" and add it to queue1
			queue1.add(elem + 'B'); //concatenate the removed element to the front of "B" and add it to queue1
			queue1.add(elem + 'C'); //concatenate the removed element to the front of "C" and add it to queue1
			cout << "Count = " << queue1.getSize() << " ";  // displays the number of elements in queue1 so far
			cout << "Front = " << queue1.getFront() << " "; // displays the index of the front element in the queue
			cout << "Rear = " << queue1.getRear() << " ";   // displays the index of the rear element in the queue
			// go to the next line
			cout << endl;
			// displays all the elements in the queue with brackets by calling displayAll()
			queue1.displayAll();
			// go to the next line
			cout << endl;
		}

		

		// Once we reach the full capacity of the queue which is MAX_SIZE in our case
		// throw Overflow exception
		catch (queue::Overflow)
		{
			cout << endl; // go to the next line
			cout << "The queue is Full" << endl; // display error message 
			cout << "Adding elements is impossible at this time! " << endl;	 
			cout << endl;

			return(1);  // exit program with error
		}
		
	}
}
