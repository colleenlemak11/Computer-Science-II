/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 2 March 2021
Assignment: Project 8
Description: Program illustrates using class MyString
*/

#include <iostream>
using namespace std;

#include "MyStr.h"
#include <cstring>

//Constructor function
MyString::MyString(char const* strIn)
{
 int length = 0;

 while(strIn[length] != '\0')
  length++;

 str = new char[length + 1];

 for(int i = 0; i < length; i++)
  str[i] = strIn[i];
}

//Destructor function
MyString::~MyString()
{
 delete []str;
}

//Display function
void MyString::myDisplay()
{
  cout << str << endl;
}

//Copy function
void MyString::myStrcpy(char const* strIn)
{
 char* tmp = new char[strlen(strIn) + 1];
 strcpy(tmp, strIn);
 delete []str;
 str = tmp;
 tmp = NULL;
 length = strlen(str);
}

//Length of string function
int MyString::myStrlen()
{
 length = 0;
 int i = 0;
 while(str[i] != '\0')
 {
  length++; 
  i++;
 }
 cout << length;
 return length;
}

//Comparison function
bool MyString::isEqual(char const* strIn)
{
 int i = 0;
 int s = 0;

 while(strIn[i] != '\0')
  i++;

 while(str[s] != '\0')
  s++;

 if(s != i)
  return false;

 if(s == i)
 {
  i = 0;
  while(str[i] != '\0')
  {
   if(str[i] == strIn[i])
    i++;
  }
 }
 if(i == s)
  return true;
 else
  return false;
}


//Find substring function
int MyString::find(char const* strIn)
{
 int i = 0;

 while(str[i] != strIn[0])
 {
  i++;
  if(i == strlen(str))
  {
   cout << "Not found." << endl;
   return -1;
  }
 }

 if(str[i] == strIn[0])
 {
  cout << isSub(strIn, i) << endl;
  return i;
 }
 else
  return -1;
}

//Concat function
void MyString::concat(char const* strIn)
{
 length = 0;

 while(strIn[length] != '\0')
  length++;

 strncat(str, strIn, length);
}

//isSub function
bool MyString::isSub(char const* strIn, int idx)
{
 int i = 1;
 int s = 0;

 while(s < strlen(strIn) - 1)
 {
  if(str[idx + 1] == strIn[i])
  {
   s++;
   idx++;
   i++;
  }
  else
   return false;
 }
 if(s = strlen(strIn) - 1)
  return true;
 else
  return false;
}

