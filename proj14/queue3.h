/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 22 April 2021
Assignment: Project 14
Description: Priority Queue
To Compile: make -f makefile_pty
To Execute: ./pqueue
*/

//Priority Queue

#ifndef PQUEUE
#define PQUEUE
 
#include "queue2.h"
/*
PQueue is a priority queue.  Nodes in PQueue are in ascending order by item
*/
class PQueue : public Queue
{
 public:
   PQueue();
   PQueue(PQueue* q);

   /*
   pre: an instance of PQueue  exists. nodes in queue are in ascending order by 
        item;
   post: A new node is added to PQueue, which remains in sorted order 
   */
   void Enqueue(itemType newItem);

 private:
   /*
   use: Used in Enqueue. 
   pre: Item to be inserted belongs somewhere between the head and tail  
   post: Returns the insertion point of the new item 
   */
  node* PtrTo(itemType newItem);
};
#endif

