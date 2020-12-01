// *********************************************************
// Implementation file QueueP.cpp for the ADT queue.
// Pointer-based implementation.
// *********************************************************
#include "Queue.h" // header file
#include <iostream>
#include <cstddef>
#include <cassert>

template <class T>
Queue<T>::Queue() : backPtr(NULL), frontPtr(NULL)
{
} // end default constructor

template <class T>
Queue<T>::Queue(const Queue &Q)
{
   QueueNode *head = Q.frontPtr;
   // clone head
   frontPtr = new QueueNode;
   frontPtr->item = head->item;
   frontPtr->next = nullptr;
   // set backPtr
   backPtr = frontPtr;
   head = head->next;
   // loop until Queue finishes 
   while (head != NULL)
   {
      QueueNode *q = new QueueNode;
      q->item = head->item;
      q->next = nullptr;

      backPtr->next = q;

      backPtr = q;
      head = head->next;
   }

} // end copy constructor

template <class T>
Queue<T>::~Queue()
{
   while (!isEmpty())
      dequeue();
   assert((backPtr == NULL) && (frontPtr == NULL));
} // end destructor

template <class T>
void Queue<T>::print()
{
   QueueNode *head = frontPtr;

   while (head != NULL)
   {
      std::cout << head->item << std::endl;
      head = head->next;
   }
}

template <class T>
bool Queue<T>::isEmpty() const
{
   return backPtr == NULL;
} // end isEmpty

template <class T>
void Queue<T>::enqueue(T newItem)
{
   // create a new node
   QueueNode *newPtr = new QueueNode;

   // set data portion of new node
   newPtr->item = newItem;

   newPtr->next = NULL;

   // insert the new node
   if (isEmpty())
      // insertion into empty queue
      frontPtr = newPtr;
   else
      // insertion into nonempty queue
      backPtr->next = newPtr;

   backPtr = newPtr; // new node is at back
} // end enqueue

template <class T>
void Queue<T>::dequeue()
{
   if (isEmpty())
      throw QueueException("QueueException: empty queue, cannot dequeue");
   else
   { // queue is not empty; remove front
      QueueNode *tempPtr = frontPtr;
      if (frontPtr == backPtr) // special case?
      {                        // yes, one node in queue
         frontPtr = NULL;
         backPtr = NULL;
      }
      else
         frontPtr = frontPtr->next;

      tempPtr->next = NULL; // defensive strategy
      delete tempPtr;
   } // end if
} // end dequeue

template <class T>
void Queue<T>::dequeue(T &queueFront)
{
   if (isEmpty())
      throw QueueException("QueueException: empty queue, cannot dequeue");
   else
   { // queue is not empty; retrieve front
      queueFront = frontPtr->item;
      dequeue(); // delete front
   }             // end if
} // end dequeue

template <class T>
void Queue<T>::getFront(T &queueFront)
{
   if (isEmpty())
      throw QueueException("QueueException: empty queue, cannot getFront");
   else
      // queue is not empty; retrieve front
      queueFront = frontPtr->item;
} // end getFront

template <class T>
void Queue<T>::addFirst(T item)
{
   // create a new node
   QueueNode *newPtr = new QueueNode;

   // set data portion of new node
   newPtr->item = item;

   newPtr->next = nullptr;

   // insert the new node
   if (isEmpty())
      // insertion into empty queue
      backPtr = newPtr;
   else
      // insertion into nonempty queue
      newPtr->next = frontPtr;

   frontPtr = newPtr; // new node is at back
} //end addFirst

template <class T>
void Queue<T>::addLast(T item)
{
   // create a new node
   QueueNode *newPtr = new QueueNode;

   // set data portion of new node
   newPtr->item = item;

   newPtr->next = NULL;

   // insert the new node
   if (isEmpty())
      // insertion into empty queue
      frontPtr = newPtr;
   else
      // insertion into nonempty queue
      backPtr->next = newPtr;

   backPtr = newPtr; // new node is at back
}; // end addLast

template <class T>
T Queue<T>::removeFirst()
{
   // Queue check
   if (isEmpty())
   {
      throw QueueException("QueueException: empty queue, cannot remove");
   }
   // get first node
   QueueNode *first = frontPtr;
   T item = first->item;

   // move frontPtr to next node
   frontPtr = frontPtr->next;

   delete first;

   return item;
}; // end removeFirst

template <class T>
T Queue<T>::removeLast()
{
   // Queue check
   if (isEmpty())
   {
      throw QueueException("QueueException: empty queue, cannot remove");
   }

   // move *head to node before backPtr 
   QueueNode *head = frontPtr;
   while (head->next != backPtr)
      head = head->next;

   // get last node
   QueueNode *temp = backPtr;
   T item = temp->item;

   // move backPtr to previous node
   backPtr = head;
   backPtr->next = nullptr;

   delete temp;

   return item;
}; // end removeLast

// Used types:
template class Queue<int>;
template class Queue<char>;