#include <iostream>
#include "Queue.h"
using namespace std;

int main(int argc, char const *argv[])
{
    // init Queue Obj
    Queue<int> q;
    // addFirst
    q.addFirst(4);
    q.addFirst(5);
    // addLast
    q.addLast(6);
    q.addLast(7);

    q.print();

    int f = q.removeFirst();
    cout << "removed first item which is " << f << endl;

    int c = q.removeLast();
    cout << "removed last item which is " << c << endl;

    q.print();

    // Copy constructor
    cout << "Cloning to b" << endl;
    Queue<int> b(q);

    b.print();

    return 0;
}
