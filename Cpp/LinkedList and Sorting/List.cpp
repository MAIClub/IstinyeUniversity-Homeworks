#include "List.h"
#include <iostream>

List::List()
{
    head = nullptr;
}

List::~List()
{
    delete_list();
}

void List::delete_list()
{
    while(head != nullptr)
    {
        delete_front();
    }
}

void List::getHead(Node *inp){
    inp = head;
}

// Inserts an element of value i at the end of the list
void List::insert_end(int i)
{
    Node *p = new Node;
    p->item = i;

    if(head == nullptr)
    {
        head = p;
    }
    else
    {
        Node *prev = head;
        Node *cur = head->next;

        for(; cur != nullptr; cur = cur->next, prev = prev->next)
            ;

        prev->next = p;
        p->next = cur;
    }
}

// Inserts an element of value i at the front of the list
void List::insert_front(int i)
{
    Node *p = new Node;
    p->item = i;

    p->next = head;
    head = p;
}

void List::delete_end()
{
    if(head == nullptr)
    {
        std::cout << "Error! No element to delete." << std::endl;
    }
    else if(head->next == nullptr)
    {
        head = nullptr;
    }
    else
    {
        Node *prev = head;
        Node *cur = head->next;

        for(; cur->next != nullptr; cur = cur->next, prev = prev->next)
            ;

        prev->next = cur->next;

        cur->next = nullptr;
        delete cur;
        cur = nullptr;
    }
}

void List::delete_front()
{
    if(head == nullptr)
    {
        std::cout << "Error! No element to delete." << std::endl;
    }
    else
    {
        Node *temp = head;
        head = head->next;

        delete temp;
        temp = nullptr;
    }
}

void List::print()
{
    for(Node *cur = head; cur != nullptr; cur = cur->next)
        std::cout << cur->item << std::endl;
}

void List::writeToFile(std::string fileName)
{
    std::ofstream out(fileName);
    for(Node* cur = head; cur != nullptr; cur = cur->next)
    {
        out << cur->item << std::endl;
    }

    out.close();
}

void List::readFromFile(std::string fileName)
{
    std::ifstream in(fileName);
    Node *temp = nullptr;
    int nextItem;

    if(in >> nextItem)
    {
        head = new Node;
        head->item = nextItem;
        head->next = nullptr;
        temp = head;
        while(in >> nextItem)
        {
            temp->next = new Node;
            temp = temp->next;
            temp->item = nextItem;
            temp->next = nullptr;
        }
    }
    in.close();
}
