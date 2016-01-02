// =========================================================

//HW1P2 stack client using vectors
//Your name: Samir Asfirane
//Complier:  g++
//File type: source file client1.cpp

//================================================================

#include <iostream>
#include <string>
#include "vstack.h"
using namespace std;


// prototype of catch underflow and overflow functions
void catchOverflow(stack& Stack, string& str);
void catchUnderflow(stack& Stack, string& str);

int main()
{
	stack postfixstack;  // integer stack
	string expression;   // expression entered by user

	cout << "type a postfix expression: ";
	cin >> expression;

	int i = 0;  // character position within expression
	char item;
	string errorcode = "Invalid item Error";

	int box1;  // receive things from pop and represents the left handside operand
	int box2;  // receive things from pop and represents the right handside operand

	while (expression[i] != '\0')
	{
		try
		{

			item = expression[i]; // read an item.

			if ((int(item) >= 48) && (int(item) <= 57)) // if it is an operand (number) 
			{
				int x = int(item) - 48; // 48 is ASCII code for 0, by substracting it from the
				// the ASCII code of ite and store the result in x

				// push it into the stack 
				try
				{
					postfixstack.push(x); // try to push x into the stack
					// display the stack after this push
					postfixstack.displayAll();
					cout << "--------------------" << endl; // separation

				}
				catch (stack::Overflow) // catch the overflow exception
				{
					catchOverflow(postfixstack, expression); // use the catchOverflow function to display message
					return(1); // exit with error message
				}
			}

			// else if it is an operator one of the three operators
			else if ((item == '+') || (item == '-') || (item == '*')) {
				// pop the operands from the stack
				try
				{
					int result;

					postfixstack.pop(box1);
					postfixstack.pop(box2);


					// first case if it is subtraction subtract box1 from box2
					// and store the result in result
					if (item == '-') result = box2 - box1;
					// second case if it is an addition add the two operands
					// and store the result in result
					if (item == '+') result = box2 + box1;
					// third case if it is an multiplication multiply the two operands
					// and store the result in result
					if (item == '*') result = box2 * box1;
					// push the result back into the stack
					postfixstack.push(result);
					// display the stack after this push
					postfixstack.displayAll();
					cout << "--------------------" << endl; // separation
				}
				// catch stack underflow and show an error message
				catch (stack::Underflow)
				{
					catchUnderflow(postfixstack, expression); // display the error message
					return(1); // exit with an error code
				}
				// Catch overflow exception and display error message
				catch (stack::Overflow)
				{
					catchOverflow(postfixstack, expression);
					return(1);
				}
			}

			// if the character entered
			else  throw errorcode;

		}  // this closes try

		catch (string errorcode) // for invalid item
		{
			cout << item << " is not a valid operator or number  " << errorcode << endl;
			return(1);
		}

		// Catch exceptions and report problems and quit the program now.
		catch (stack::Overflow)
		{
			catchOverflow(postfixstack, expression);
			return(1);
		}
		catch (stack::Underflow)
		{
			catchUnderflow(postfixstack, expression);
			return(1);
		}


		i++; // increment i and continue looping

	} // end of while

	//  After the loop successfully completes:
	//  The result will be at the top of the stack. Pop it and show it.

	int result; // declare the variable to hold the result
	// try to pop the result from the top of the stack to result
	try
	{
		postfixstack.pop(result); // store the result
	}

	// catch any underflow exception
	catch (stack::Underflow)
	{
		catchUnderflow(postfixstack, expression);
		return(1);
	}

	//  If anything is left on the stack, an incomplete expression was found
	// inform the user
	if (postfixstack.isEmpty() != true)
	{
		cout << "There was a problem with your expression" << endl;
		cout << "You expression " << expression << " is incomplete" << endl;
		return(1);
	}

	// display the result   
	cout << "result : " << result << endl; // separation
	return(0);

}

// catchOverflow function takes a reference to a stack and string
// entered by the user and displays an explicit error message to help the user
// figure out the mistake or the problem in case of overflow
void catchOverflow(stack& stack, string& str)
{
	cout << "The expression is too large to fit in the stack " << endl;
	cout << "The expression entered is : " << str << endl;

}


// catchUnderflow function takes a reference to a stack and string
// error message and displays an explicit error message to help the user
// figure out the mistake or the problem in case of underflow
void catchUnderflow(stack& stack, string& str)
{
	cout << "The expression you entered is not complete, it is missing an operand or operator " << endl;
	cout << "The expression entered is : " << str << endl;

}
