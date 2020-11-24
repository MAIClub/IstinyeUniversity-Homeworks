#ifndef LIST_H
#define LIST_H
#include <fstream>
#include <iostream>

struct Node {
    int item;
    Node *next;
};

class List
{
    public:
        List();
        virtual ~List();
        void getHead(Node *inp);
        void insert_end(int i);
        void insert_front(int i);
        void delete_end();
        void delete_front();
        void delete_list();
        void print();
        void writeToFile(std::string fileName);
        void readFromFile(std::string fileName);
        friend void insertionSort(List *linkedList);
        friend void quickSort(List *linkedList, int startInd, int endInd);
    protected:

    private:
        Node *head;
};

#endif // LIST_H
