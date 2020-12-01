// *********************************************************
// Implementation file StackP.cpp for the ADT stack.
// Pointer-based implementation.
// *********************************************************
#include "Stack.h" // header file
#include <cstddef>  // for NULL
#include <cassert>  // for assert
#include <iostream>

template <class T>
Stack<T>::Stack() : topPtr(NULL)
{
} // end default constructor

template <class T>
Stack<T>::Stack(const Stack &aStack)
{
   if (aStack.topPtr == NULL)
      topPtr = NULL; // original list is empty

   else
   { // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of list
      StackNode *newPtr = topPtr; // new list pointer
      for (StackNode *origPtr = aStack.topPtr->next;
           origPtr != NULL;
           origPtr = origPtr->next)
      {
         newPtr->next = new StackNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
      } // end for

      newPtr->next = NULL;
   } // end if
} // end copy constructor

template <class T>
Stack<T>::~Stack()
{
   // pop until stack is empty
   while (!isEmpty())
      pop();
   // Assertion: topPtr == NULL
} // end destructor

template <class T>
bool Stack<T>::isEmpty() const
{
   return topPtr == NULL;
} // end isEmpty

template <class T>
void Stack<T>::print()
{

   StackNode *head = topPtr;
   while (head != NULL)
   {
      std::cout << head->item << " ";
      head = head->next;
   }
}

template <class T>
void Stack<T>::push(T newItem)
{
   // create a new node
   StackNode *newPtr = new StackNode;

   // set data portion  of new node
   newPtr->item = newItem;

   // insert the new node
   newPtr->next = topPtr;
   topPtr = newPtr;
} // end push

template <class T>
void Stack<T>::pop()
{
   if (isEmpty())
      throw StackException("StackException: stack empty on pop");
   else
   { // stack is not empty; delete top
      StackNode *temp = topPtr;
      topPtr = topPtr->next;
      // return deleted node to system
      temp->next = NULL; // safeguard
      delete temp;
   } // end if
} // end pop

template <class T>
void Stack<T>::pop(T &stackTop)
{
   if (isEmpty())
      throw StackException("StackException: stack empty on pop");
   else
   { // stack is not empty; retrieve and delete top
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL; // safeguard
      delete temp;
   } // end if
} // end pop

template <class T>
void Stack<T>::getTop(T &stackTop)
{
   if (isEmpty())
      throw StackException("StackException: stack empty on getTop");
   else
      // stack is not empty; retrieve top
      stackTop = topPtr->item;
} // end getTop
// End of implementation file.

// Used types:
template class Stack<int>;
template class Stack<char>;