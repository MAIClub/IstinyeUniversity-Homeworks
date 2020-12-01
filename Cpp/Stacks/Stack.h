// *********************************************************
// Header file StackP.h for the ADT stack.
// Pointer-based implementation.
// *********************************************************
#include <stdexcept>
#include <string>
using namespace std;

class StackException : public logic_error
{
public:
      StackException(const string &message = "")
          : logic_error(message.c_str())
      {
      }
};

template <class T>
class Stack
{
public:
   // constructors and destructor:
   Stack();                    // default constructor
   Stack(const Stack &aStack); // copy constructor
   ~Stack();                   // destructor

   // stack operations:
   bool isEmpty() const;
   void push(T newItem);
   void pop();
   void pop(T &stackTop);
   void getTop(T &stackTop);
   void print();

private:
   struct StackNode // a node on the stack
   {
      T item;          // a data item on the stack
      StackNode *next; // pointer to next node
   };                  // end struct

   StackNode *topPtr; // pointer to first node in the stack
};                    // end Stack class
                      // End of header file.