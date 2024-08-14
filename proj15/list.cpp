/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Project Number: 15
CPP file for a simple linked list that adds and deletes at the head
All traversals are done recursively, either directly or indirectly
*/

#include <iostream>
using namespace std;

#include "list.h"


//Non-recursive functions. I have written them for you.
List::List()
{
 head = NULL;
}

bool List::IsEmpty() 
{
 if (head == NULL)
  return true;
 return false; 
}

void List::PutItemH(itemType item)
{
 node* tmp = new node;
 tmp->item = item;
 tmp->next = head;
 head = tmp;
 tmp = NULL;
}

itemType List::GetItemH() 
{
 return head->item; 
}

void List::DeleteItemH()
{
 node* cur = head;
 head = head->next;
 delete cur;
 cur == NULL;
}

//Write the following functions recursively or in such a way that they use
//recursive functions.  You may add recursive utility functions to the 
//private section of the header (.h) file.

List::~List()
{
}

int List::GetLength()
{
 node* cur = head;

 for(int i = 0; i < length; i++)
  cur = cur->next;
   
 if(IsEmpty())
 {
  cout << "List is empty." << endl;
  return 0;
 }
 else
  length++;
 
 if(cur->item == '\0')
  return length;
 else
  return GetLength();
}

void List::Print( )
{
 node* cur = head;

 for(int i = 0; i < count; i++)
  cur = cur->next;

 if(cur == NULL)
  return;

 node* value = new node;
 value = cur;
 cur = cur->next;
 Print(value);
 count++;
 Print();
}

void List::PrintRev( )
{
 node* cur = head;

 for(int i = 0; i < num; i++)
  cur = cur->next;

 if(cur == NULL)
  return;

 node* value = new node;
 value = cur;
 cur = cur->next;
 num++;
 PrintRev();
 Print(value);
}

void List::Print(node* cur) 
{
 cout << cur->item << endl;
}
