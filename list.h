#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

struct List
{
       int data;
       List *next;
};
typedef List *PList;


PList createList(int count);
void printList(PList list);
void clearList(PList list);
PList searchNode(int data, PList list);
PList deleteNode(int data, PList list);
void addAfter (int element, int data,  PList list);
void addBefore (int element, int data,  PList list);
