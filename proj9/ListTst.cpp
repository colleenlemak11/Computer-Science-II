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

int main()
{
 //PutItemH function
 cout << "PutItemH()" << endl;
 //Use of a static list 
 cout << "Expected output is a list 4 3 2 1 0 on different lines (static)." << endl;
 List lst;
 for (int i = 0; i < 5; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 cout << "Expected output is a list 40 30 20 10 0 on different lines (dynamic)." << endl;
 List* lst1 = new List;
 for (int i = 0; i < 5; i++)
  lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl;

 //IsEmpty function
 cout << "IsEmpty()" << endl;
 cout << "Expected output is 0 (false) or 1 (true) based on the assumption that the list is empty (static)." << endl;
 cout << lst.IsEmpty() << endl;
 cout << "Expected output is 0 (false) or 1 (true) based on the assumption that the list is empty (dynamic)." << endl;
 cout << lst1->IsEmpty() << endl;
 cout << endl;

 //GetLength function
 cout << "GetLength()" << endl;
 cout << "Expected output is the length of the list (static)." << endl;
 cout << lst.GetLength() << endl;
 cout << "Expected output is the length of the list (dynamic)." << endl;
 cout << lst1->GetLength() << endl;
 cout << endl;

 //GetItemH function
 cout << "GetItemH()" << endl;
 cout << "Expected output is the contents of the head of the list (static)." << endl;
 cout << lst.GetItemH() << endl;
 cout << "Expected output is the contents of the head of the list (dynamic)." << endl;
 cout << lst1->GetItemH() << endl;
 cout << endl;

 //Find function
 cout << "Find()" << endl;
 cout << "Expected output is the index of the list of the number being searched, returns -1 if not found (static)." << endl;
 cout << lst.Find(2) << endl;
 cout << "Expected output is the index of the list of the number being searched, returns -1 if not found (dynamic)." << endl;
 cout << lst1->Find(10) << endl;
 cout << endl;

 //DeleteItem function
 cout << "Expected output is the list of numbers without the deleted item inputted (static)." << endl;
 lst.DeleteItem(1);
 //Print function -- used to show DeleteItem function (static) worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;
 cout << "Expected output is the list of numbers without the deleted item inputted (dynamic)." << endl;
 lst1->DeleteItem(1);
 //Print function -- used to show DeleteItem function (dynamic) worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;

 //DeleteItemH function
 cout << "Expected output is the list of numbers without the head item (static)." << endl;
 lst.DeleteItemH();
 //Print function -- used to show DeleteItemH function worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;
 cout << "Expected output is the list of numbers without the head item (dynamic)." << endl;
 lst1->DeleteItemH();
 //Print function -- used to show DeleteItemH function worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;

 delete lst1; //necessary to invoke destructor on dynamic list
 cout << endl;

 return 0;
}
