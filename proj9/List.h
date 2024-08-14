/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 12 March 2021
Assignment: Project 9
Description: Program illustrates a simple linked list 
*/

#ifndef LIST_H
#define LIST_H

typedef int itemType;

struct node
{
 itemType item;
 node* next;
};

class List
{
 public:
   List();
   ~List();

   /*
   pre: an instance of lists exists
   post: returns true if list is empty, false otherwise
   */
   bool IsEmpty() const;

   /*
   pre: an instance of list exists
   post: returns length of the list 
   */
   int GetLength() const;

   /*
   pre: an instance of list exists
   post: newItem is at the head of the list 
   */
   void PutItemH(itemType newItem);

   /*
   pre: an instance of list exists and is not empty
   post: Returns the contents of the head of the list. 
   */
   itemType GetItemH() const;

   /*
   pre: an instance of list exists and is not empty
   post: head of the list is deleted 
   */
   void DeleteItemH();

   /*
   pre: an instance of list exists and is not empty
   post: contents of list nodes are displayed on subsequent lines 
   */
   void Print() const;
  
   /*
   pre:  an instance of List exists and contains n items, n >= 1.
   post: returns the position of item if item is in the list, -1 
         otherwise.  
   */
   int Find(itemType item) const;

   /*
   pre:  an instance of List exists and contains n items, n >= 1; 
   post: item at position, pos is deleted 
	 Notice you've alread written a function to handle the case 
         where n = 1. Make use of it here. 
   */
   void DeleteItem(const int pos);

 private:
   int length;   //length of the List
   node* head;   //pointer to the first node on the list 
};
#endif

