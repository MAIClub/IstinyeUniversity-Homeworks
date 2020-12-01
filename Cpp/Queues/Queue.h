// ********************************************************
// Header file QueueP.h for the ADT queue.
// Pointer-based implementation.
// ********************************************************
#include <stdexcept>
#include <string>
using namespace std;

class QueueException : public logic_error
{
public:
	QueueException(const string &message = "")
		: logic_error(message.c_str())
	{
	}
}; // end QueueException

template<class T>
class Queue
{
public:
// constructors and destructor:
   Queue();                     // default constructor
   Queue(const Queue& Q);       // copy constructor
   ~Queue();                    // destructor

// Queue operations: 
   bool isEmpty() const;
   // Determines whether the queue is empty. 

   void enqueue(T newItem);
   // Inserts an item at the back of a queue.

   void dequeue();
   // Dequeues the front of a queue.

   void dequeue(T& queueFront);
   // Retrieves and deletes the front of a queue.

   void getFront(T& queueFront);
   // Retrieves the item at the front of a queue.

   void print();
   // print whole queue.

   void addFirst(T item);
   // add item to the front.

   void addLast(T item);
   // add item to the back.

   T removeFirst();
   // remove and return the item from the front

   T removeLast();
   // remove and return the item from the back
private:
   // The queue is implemented as a linked list
   // with one external pointer to the front of the queue
   // and a second external pointer to the back of the
   // queue.
   struct QueueNode
   {  T  item;
      QueueNode     *next;
   }; // end struct
   QueueNode *backPtr;
   QueueNode *frontPtr;
};  // end class
// End of header file.
