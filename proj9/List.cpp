/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 12 March 2021
Assignment: Project 9
Description: Program illustrates a simple linked list 
*/

#include <iostream>
using namespace std;

#include "List.h"

List::List()
{
 head = NULL;
 length = 0;
}

List::~List()
{ 
 if(length > 0)
 {
  node* nxt = head->next;
  node* curr = head;
  while(nxt != NULL)
  {
   delete curr;
   curr = nxt;
   nxt = nxt->next;
  }
 delete curr;
 }
}

bool List::IsEmpty() const
{
 if(length == 0)
  return true;
 else
  return false;
}

int List::GetLength() const
{
 return length;
}

void List::PutItemH(const itemType newItem)
{
 node* temp = new node;
 temp->item = newItem;
 temp->next = head;
 head = temp;
 length++;
 temp = NULL;
}

itemType List::GetItemH() const
{
 return head->item;
}

void List::DeleteItemH()
{
 node* tmp = head;
 head = head->next;
 delete tmp;
 tmp = NULL;
 length--;
}
	
void List::Print() const
{
 node* tmp = head;
 for(int i = 0; i < length; i++)
 {
  cout << tmp->item << endl;
  tmp = tmp->next;
 }
}

int List::Find(const itemType item1) const
{
 node* tmp = head;
 if(length >= 1)
 {
  for(int i = 0; i < length; i++)
  {
   if(tmp->item == item1)
   { 
    return i;
   }
   tmp = tmp->next;
  }
 }
 return -1;
}

void List::DeleteItem(const int pos)
{
 node* prev_curr = NULL;
 node* curr = head;
 if(length >= 1)
 {
  if(pos == 0)
   DeleteItemH();
  else
  {
  for(int i = 0; i <= pos; i++)
  {
   prev_curr = curr;
   curr = curr->next;
  }
  prev_curr->next = curr->next;
  delete curr;
  curr = NULL;
  length--;
  }
 }
}

