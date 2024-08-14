/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 22 April 2021
Assignment: Project 14
Description: Priority Queue
To Compile: make -f makefile_pty
To Execute: ./pqueue
*/

//Queue using List and composition 
#include <iostream>
using namespace std;
#include "queue3.h"

PQueue::PQueue() : Queue()
{}

PQueue::PQueue(PQueue* q) : Queue(q)
{}

void PQueue::Enqueue(itemType newItem)
{
 if(IsEmpty() || (head->item >= newItem))
  PutItemH(newItem);
 else if (newItem >= tail->item || (tail->item <= newItem))
  PutItemT(newItem);
 else
 {
  node* ptA = new node; 
  node* tmp = new node; 
  node* pointer = new node;
  pointer->item = newItem;
   
  ptA = PtrTo(newItem);
  tmp = ptA->next;
  ptA->next = pointer;
  pointer->next = tmp; 
 }
}

node* PQueue::PtrTo(itemType newItem)
{
 node* cur = new node;
 cur = head;
 for(int i = 0; i < length; i++)
 {
  if((newItem > cur->item) && (newItem <= cur->next->item))
   return cur;
  cur = cur->next;
 }
 return NULL;
}

	
