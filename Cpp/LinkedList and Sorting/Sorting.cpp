//
// Created by Batuhan Yenidunya
// Data Structures and Algorithms Homework 2
// 10 November 2020
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "List.h"
#include "Sorting.h"

using namespace std;

void insertionSort(List *linkedList)
{
    Node *head = linkedList->head;

    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *anchor = head->next;
    while (anchor != NULL)
    {
        int sec_data = anchor->item;
        int found = 0;
        Node *current = head;
        while (current != anchor)
        {
            if (current->item > anchor->item && found == 0)
            {
                sec_data = current->item;
                current->item = anchor->item;
                found = 1;
                current = current->next;
            }
            else
            {
                if (found == 1)
                {
                    int temp = sec_data;
                    sec_data = current->item;
                    current->item = temp;
                }
                current = current->next;
            }
        }
        current->item = sec_data;
        anchor = anchor->next;
    }
}

void swapValues(Node *p1, Node *p2)
{

    // cout << "swapping " << p1->item << " " << p2->item << endl;
    int temp = p1->item;
    p1->item = p2->item;
    p2->item = temp;
}

Node *getNode(Node *head, int index)
{
    Node *pivot = head;
    for (int pos = 0; pos < index; pos++)
    {
        pivot = pivot->next;
    }
    return pivot;
}

int partition(Node *head, int startInd, int endInd)
{

    int pivotPos = endInd;
    Node *pivot = getNode(head, pivotPos);
    int i = (startInd - 1);

    for (int j = startInd; j <= endInd - 1; j++)
    {
        Node *jth = getNode(head, j);
        if (jth->item <= pivot->item)
        {
            i++;
            swapValues(getNode(head, i), getNode(head, j));
        }
    }
    swapValues(getNode(head, i + 1), pivot);
    return (i + 1);
}

void quickSort(List *linkedList, int startInd, int endInd)
{
    Node *head = linkedList->head;

    if (startInd < endInd)
    {
        int pi = partition(head, startInd, endInd);
        quickSort(linkedList, startInd, pi - 1);
        quickSort(linkedList, pi + 1, endInd);
    }
} 