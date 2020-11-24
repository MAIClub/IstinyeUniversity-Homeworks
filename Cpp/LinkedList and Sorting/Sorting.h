#ifndef SORTING_H
#define SORTING_H
#include <fstream>
#include <iostream>
#include "List.h"

void insertionSort(List *linkedList);
void quickSort(List *linkedList, int startInd, int endInd);
#endif // SORTING_H
