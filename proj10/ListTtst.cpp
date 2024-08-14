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

int main()
{

 cout << "When the list reprints, I don't clear the list, so it'll keep any changes from previous functions in the numbers shown. A static test will affect the first list of numbers, and a dynamic test will affect the second list of numbers." << endl << endl;
 //PutItemH function
 cout << "PutItemH()" << endl;
 //Use of a static list 
 cout << "Expected output is a list 4 3 2 1 0 on different lines (static)." << endl;
 ListT lst;
 for (int i = 0; i < 5; i++) 
  lst.PutItemH(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 cout << "Expected output is a list 40 30 20 10 0 on different lines (dynamic)." << endl;
 ListT* lst1 = new ListT;
 for (int i = 0; i < 5; i++)
  lst1->PutItemH(10*i);
 lst1->Print();
 cout << endl << endl;

 //PutItemT() function
 cout << "PutItemT()" << endl;
 //Use of a static list
 cout << "Expected output is a list 4 3 2 1 0 0 1 2 3 4 on different lines (static)." << endl;
 for (int i = 0; i < 5; i++) 
  lst.PutItemT(i);
 lst.Print();
 cout << endl;
 //Use of a dynamic list
 cout << "Expected output is a list 40 30 20 10 0 0 10 20 30 40 on different lines (dynamic)." << endl;
 for (int i = 0; i < 5; i++)
  lst1->PutItemT(10*i);
 lst1->Print();
 cout << endl << endl;

 //GetItemT() function
 cout << "GetItemT()" << endl;
 cout << "Expected output is the contents of the tail of the list (static)." << endl;
 cout << lst.GetItemT() << endl;
 cout << "Expected output is the contents of the tail of the list (dynamic)." << endl;
 cout << lst1->GetItemT() << endl;
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
 cout << "FindItem()" << endl;
 cout << "Expected output is the index of the list of the number being searched, returns -1 if not found (static)." << endl;
 cout << lst.FindItem(2) << endl;
 cout << "Expected output is the index of the list of the number being searched, returns -1 if not found (dynamic)." << endl;
 cout << lst1->FindItem(10) << endl;
 cout << endl;

 //DeleteItem function
 cout << "DeleteItem()" << endl;
 cout << "Expected output is the list of numbers without the deleted item inputted (static)." << endl;
 lst.DeleteItem(2);
 //Print function -- used to show DeleteItem function (static) worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;
 cout << "Expected output is the list of numbers without the deleted item inputted (dynamic)." << endl;
 lst1->DeleteItem(2);
 //Print function -- used to show DeleteItem function (dynamic) worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;

 //DeleteItemT function
 cout << "DeleteItemT()" << endl;
 cout << "Expected output is the list of numbers without the tail item and the number from DeleteItem() if functions were run after one another (static)." << endl;
 lst.DeleteItemT();
 //Print function -- used to show DeleteItemT function worked
 lst.Print();
 cout << endl;
 lst1->Print();
 cout << endl;
 cout << "Expected output is the list of numbers without the tail item and the number from DeleteItem() if functions were run after one another (dynamic)." << endl;
 lst1->DeleteItemT();
 //Print function -- used to show DeleteItemT function worked
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
