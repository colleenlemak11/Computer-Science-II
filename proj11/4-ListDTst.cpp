/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 1 April 2021
Assignment: Project 11
Description: Program illustrates a doubly linked templated list
*/

#include <iostream>
using namespace std;

#include "4-ListD.h"
#include "4-ListD.cpp"

int main()
{
 ListD<int>* lst = new ListD<int>;
 
 //Insert function
 cout << "Insert()" << endl;
 cout << "This function should return a list of integers, 2, 59, 4, 11, 58, 33, 28, 99, 71, 101, on separate lines." << endl;
 lst->Insert(2, 1);
 lst->Insert(59, 2);
 lst->Insert(4, 3);
 lst->Insert(11, 4);
 lst->Insert(58, 5);
 lst->Insert(33, 6);
 lst->Insert(28, 7);
 lst->Insert(99, 8);
 lst->Insert(71, 9);
 lst->Insert(101, 10);
 lst->PrintForward();
 cout << endl;


 //Copy function
 cout << "Copy Constructor: ListD(ListD* lst)" << endl;
 cout << "This function should return a list of integers, 2, 59, 4, 11, 58, 33, 28, 99, 71, 101, on separate lines." << endl;
 ListD<int>* lst1 = new ListD<int>(lst);
 lst1->PrintForward();
 cout << endl;
 
 //PrintBackward function
 cout << "PrintBackward()" << endl;
 cout << "This function should return a list of integers, 101, 71, 99, 28, 33, 58, 11, 4, 59, 11, 4, 59, 2, on separate lines." << endl;
 lst->PrintBackward();
 cout << endl;
 
 //Delete function
 cout << "Delete()" << endl;
 cout << "This function should return the list of integers without the head, tail, and the other indicated position inputted printed out forwards." << endl;
 lst->Delete(1); //deletes head (int 1)
 lst->Delete(9); //deletes tail (int 10)
 lst->Delete(3); //deletes 3rd item in list (int 4)
 lst->PrintForward();
 cout << endl;
 
 //DeleteAll function
 cout << "DeleteAll()" << endl;
 cout << "This function should return the new list without the matches from input, and the number of items that were deleted which matched the input." << endl;
 lst->DeleteAll(58);
 lst->PrintForward();
 cout << endl;
 
 //Sort function
 cout << "Sort()" << endl;
 cout << "This function should return the list sorted in ascending order." << endl;
 lst->Sort();
 lst->PrintForward();

 return 0;
}
