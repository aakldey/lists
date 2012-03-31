#include "list.h"
//***EXAMPELS OF USING FUNCTIONS TO WORK WITH LISTS***
//****************************************************

//***struct List, init List***
//PList list = new List;

//***creating the list***
//PList list;
//list = createList(int count);

//***print list***
//printList(list); 

//***clear list***
//clearList(list);

//***search in list***
/*
if(searchNode(element,list)!=NULL)
 {
	 cout << "found: " << searchNode(element,list)->data << "\n";
 }

 or

PList found = searchNode(element,list);
found == NULL if not found;
*/

//***delete element***
//list = deleteNode(element,list);

//***add before element***
//addBefore(element, element_you_insert,list);

//***add after element***
//addAter(element,element_you_insert,list);



PList head = NULL;


PList createList(int count)
{
 if (count == 0)
 {  head = NULL;
    return NULL; 
 }
 else
 {
       PList first = NULL;
       for (int i=0;i<=count;i++)
       {   
       PList newElement = new List;
       newElement->data = rand()%10;
      // newElement->data = 10;
       //cout << newElement->data << "\n";
       if (first == NULL)
          newElement->next = NULL;
       else
          newElement->next = first;
          first = newElement;
        }
          head = first; 
          return first;
  }
}

void printList(PList list)
{    
     if (head == NULL)
     cout << "List is clear" << "\n";
     else
     if (list->next != NULL)
     {
     cout << list->data << "\n";
     printList(list->next);
     }
     
}

void clearList(PList list)
{    if (head != NULL)
     {
        while (head->next != NULL)
        {
         head = list->next;
         delete list;
         list = head;
        }
      if (head->next == NULL)
         {
          delete list; 
          head = NULL;
         }
      }
}

PList searchNode(int data, PList list)
{
PList q = list;
while (q && q->data != data)
q = q->next;
return q;
}

PList deleteNode(int data, PList list)
{    
	
	PList tmp = list;
	head = tmp;
	PList OldNode = searchNode(data,list);
		if (OldNode)
			{
				if (list == OldNode)
				{
					list = list->next;
					head = list;
					delete OldNode;
					return list;
				}
				else {
			
					while (list != NULL && list->next != OldNode)
						list = list->next;
					list->next = OldNode->next;
					delete OldNode;
				return head;
				}
			}
		else return tmp;
	
	
}

void addAfter (int element, int data,  PList list)
{
PList elem = searchNode(element,list);
if (elem)
	{
		PList newElem = new  List;
		newElem->data = data;
		newElem->next = elem->next;
		elem->next = newElem;
		
	}
}

void addBefore (int element, int data,  PList list)
{
	while (list && list->next!=NULL && list->next->data != element)
		list = list->next;

	if (list != NULL)
	{
		PList newElem = new  List;
		newElem->data = data;
		newElem->next = list->next;
		list->next = newElem;
	}
	
}
