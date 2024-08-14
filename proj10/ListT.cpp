/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 19 March 2021
Assignment: Project 10
Description: Program illustrates a linked list both head and tail pointers 
*/

#include <iostream>
using namespace std;

#include "ListT.h"

ListT::ListT()
{
 head = NULL;
 tail = NULL;
 length = 0;
}

ListT::~ListT()
{ 
/*
 while(length != 0)
 {
  DeleteItemH();
  length--;
 }
*/
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

bool ListT::IsEmpty() const
{
 if(length == 0)
  return true;
 else
  return false;
}

int ListT::GetLength() const
{
 return length;
}

void ListT::PutItemH(const itemType newItem)
{
 node* temp = new node;
 temp->item = newItem;
 if(length == 0)
 {
  head = temp;
  tail = temp;
  temp->next = NULL;
  length++;
 }
 else
 {
 temp->next = head;
 head = temp;
 length++;
 }
 temp = NULL;
}

itemType ListT::GetItemH() const
{
 return head->item;
}

void ListT::DeleteItemH()
{
 node* tmp = head;
 head = head->next;
 delete tmp;
 tmp = NULL;
 length--;
}

void ListT::PutItemT(const itemType itemIn)
{
 if(length == 0)
 {
  PutItemH(itemIn);
  return;
 }
 else
 {
 node* temp = new node;
 temp->item = itemIn;
 tail->next = temp;
 temp->next = NULL;
 tail = temp;
 length++;
 temp = NULL;
 }
}
	
itemType ListT::GetItemT() const
{
 return tail->item;
}

void ListT::DeleteItemT()
{
 node* tmp = new node;
 tmp = PtrTo();
 delete tmp->next;
 tmp->next = NULL;
 tail = tmp;
 tmp = NULL;
 length--;
}

void ListT::Print() const
{
 node* tmp = head;
 for(int i = 0; i < length; i++)
 {
  cout << tmp->item << endl;
  tmp = tmp->next;
 }
}

int ListT::FindItem(const itemType item1) const
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

int ListT::DeleteItem(const int pos)
{
 node* prev_curr = NULL;
 node* curr = head;
 if(length >= 1)
 {
  if(pos == 0)
   DeleteItemH();
  else
  {
  for(int i = 0; i < pos; i++)
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
 return 1;
}

node* ListT::PtrTo()
{
 node* tmp = new node;
 tmp = head;
 for(int i = 0; i < length - 1; i++)
 {
  tmp = tmp->next; //prev item before last one
 }
 return tmp;
}

