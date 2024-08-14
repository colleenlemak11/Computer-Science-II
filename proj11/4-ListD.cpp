/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 1 April 2021
Assignment: Project 11
Description: Program illustrates a doubly linked templated list
*/

#include <iostream>
#include <climits>
using namespace std;

#include "4-ListD.h"
template <typename T>
ListD<T>::ListD()
{
 length = 0;
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;
}

template <typename T>
int ListD<T>::find_small(int start, int arr[], int length)
{
 int idx_small = start;  //candidate smallest
 int next = start + 1;    //start searching here
 while(next < length)         
 {
  if (arr[next] < arr[idx_small]) //we've found a new smallest integer
     idx_small = next;
  next++;                        //look at the next position whether or not
                                //we've found a new smallest 
 }
 return idx_small;
}

template <typename T>
void ListD<T>::swap(int pos, int idx_small, int arr[])
{
 int tmp = arr[pos];
 arr[pos] = arr[idx_small];
 arr[idx_small] = tmp;
}

template <typename T>
void ListD<T>::selection_sort(int arr[], int length)
{
 int pass = 0;
 int start = 0;
 int idx_small; 
 
 while(pass < length - 1 )      //option 1 
 //while(start < length - 1 )   //option 2 
 {
  int idx_small = find_small(start, arr, length);
  swap(start,idx_small,arr);
  start++;
  pass++; 
 }
}

template <typename T>  
void ListD<T>::Insert(T item, int pos)
{
 //new node goes between these two nodes
 doubleNode<T>* insertPtA = FindPosition(pos);  
 doubleNode<T>* insertPtB = insertPtA->next; 

 //create new node and set its values
 doubleNode<T>* tmp = new doubleNode<T>; 
 tmp->prev = insertPtA;
 tmp->item = item;
 tmp->next = insertPtB;

 //set pointers for nodes before and after the insertion point
 insertPtA->next = tmp;
 insertPtB->prev = tmp;

 length++;
}

template <typename T>
void ListD<T>::PrintForward()
{
 doubleNode<T>* cur = head->next;
 int i = 0;
 while (i < length)
 {
  cout << cur->item << endl;
  cur = cur->next;
  i++;
 }
}

template <typename T>
doubleNode<T>* ListD<T>::FindPosition(int pos)
{
 doubleNode<T>* cur = head;
 int i = 0;  //begin at the dummy node
 while (i < pos - 1)
 {
  cur = cur->next;
  i++;
 }
 return cur;
} 

template <typename T>
ListD<T>::ListD(ListD<T>* lst)
{
 length = 0; 
 
//create dummy nodes;
 head = new doubleNode<T>;
 tail = new doubleNode<T>;

 //set values for head dummy node;
 head->prev = NULL;
 head->item = INT_MIN;
 head->next = tail;

 //set values for tail dummy node;
 tail->prev = head; 
 tail->item = INT_MAX;
 tail->next = NULL;

 //returns pointer to the first node, which is what we want here
 doubleNode<T>* cur = lst->FindPosition(2);
 for (int i = 1; i <= lst->length; i++)
 {
  Insert(cur->item,i);
  cur = cur->next;
 }
}

template <typename T>
void ListD<T>::PrintBackward()
{
 while (tail->next != NULL)
  tail = tail->next;
  
 doubleNode<T>* curr = tail->prev;
 int i = 0;
 
 while(i < length)
 {
  cout << curr->item << endl;
  curr = curr->prev;
  i++;
 }
}

template <typename T>
void ListD<T>::Delete(int pos)
{
 doubleNode<T>* A = FindPosition(pos);
 doubleNode<T>* B = A->next->next;
 delete A->next;
 A->next = B;
 B->prev = A;
 length--;
 A = NULL;
 B = NULL;
}

template <typename T>
int ListD<T>::DeleteAll(T item)
{
 int count = 0;
 doubleNode<T>* curr = head;
 for(int i = 1; i <= length; i++)
 {
  if(curr->item == item)
  {
   Delete(i - 1);
   count++;
  }
  curr = curr->next;
 }
 cout << "Number of item(s) deleted as an item match: " << count << endl;
 return count;
}

template <typename T>
void ListD<T>::Sort()
{
 int arr[length];
 doubleNode<T>* temp = head;
 doubleNode<T>* newTemp = head;
 
 for(int i = 0; i < length; i++)
 {
  arr[i] = temp->next->item;
  temp = temp->next;
 }
 
 selection_sort(arr, length);
 
 for(int i = 0; i < length; i++)
 {
  newTemp->next->item = arr[i];
  newTemp = newTemp->next;
 }
}




