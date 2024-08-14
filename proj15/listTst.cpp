/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Project Number: 15
Test file for a simple linked list that adds and deletes at the head
All traversals are done recursively, either directly or indirectly
*/

#include <iostream>
using namespace std;

#include "list.h"


int main()
{
 List* lst1 = new List;
 
 for (int i = 0; i < 5; i++)
  lst1->PutItemH(i);
  
 cout << endl;
 
 //GetLength()
 cout << "GetLength() -- should return the length of the list." << endl;
 cout << lst1->GetLength() << endl;
 
 cout << endl;
 
 //Print()
 cout << "Print() -- should return the printed list on separate lines in forwards order: 4 3 2 1 0." << endl;
 lst1->Print();
 
 cout << endl;
 
 //PrintRev() 
 cout << "PrintRev() -- should return the printed list on separate lines in backwards order: 0 1 2 3 4." << endl;
 lst1->PrintRev();

 cout << endl;
 
 delete lst1; 
 return 0;
}
