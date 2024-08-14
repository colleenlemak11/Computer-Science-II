/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 5 April 2021
Assignment: Project 12
Description: Part 1 of Calculator Assignment 
To Compile: make
To Execute: ./calc "(121+12)"
*/
#include <iostream>
using namespace std;

#include "calc.h"
#include <cstring>


Calc::Calc(char* argvIn)
{
 inFix = new char[strlen(argvIn) + 1];
 strcpy(inFix, argvIn);
 
 //CheckTokens() -- check input string's validity
 if(!CheckTokens())
 {
  cout << "Invalid string entered." << endl << endl;
  exit(EXIT_FAILURE);
 }
 else
  cout << "Valid string entered." << endl << endl;
 
 //CheckParens() -- see if parentheses match together properly
 if(!CheckParens())
  cout << "Incorrectly balanced parentheses." << endl << endl;
 else
  cout << "Correctly balanced parentheses." << endl << endl;
 
 //MakeValueTbl() -- create new integer array
 MakeValueTbl();
 
 //DisplayInFix() -- print inFix
 DisplayInFix();
 
 //Parse() -- convert string to symbols, use stack, fill value table
 Parse();
}

Calc::~Calc()
{
 delete inFix;
 delete valueTbl;
 delete stk;
 valueIdx = 0;
}

bool Calc::CheckTokens()
{
 int count = 0;
 //cout << "size of infix: " << sizeof(inFix) - 1 << endl;
 for(int i = 0; i < strlen(inFix); i++)
 {
  if((inFix[i] >= '0' && inFix[i] <= '9') || ((int(inFix[i]) >= 40 && int(inFix[i]) <= 43) || (int(inFix[i]) == 45 ||(int(inFix[i]) == 47))))
   count++;
  else
   return false;
 }
 
 if(count == strlen(inFix))
  return true;
 else
  return false;
}

void Calc::MakeValueTbl()
{
 valueTbl = new int[26];
 valueIdx = 0;
 for(int i = 0; i < 26; i++)
  valueTbl[i] = 0;
 cout << "Value table created." << endl << endl;
}

void Calc::Parse()
{ 
 int i = 0;
 int curIdx = 0;
 int lastIdx = 0;
 int digitLength = 0;
 int value = 0;
 int count = 0;
 int pos = 0;

 //put values into valueTbl
 while(i < strlen(inFix))
 {
  if(inFix[i] >= '0' && inFix[i] <= '9')
  { 
   curIdx = i;
   lastIdx = FindLast(curIdx);
   lastIdx--;
   digitLength = (lastIdx - curIdx) + 1;
   cout << endl;

   char arr[digitLength + 1];
    
   for(int p = curIdx; p <= lastIdx; p++)
   {
    arr[pos] = inFix[p];
    pos++;
   }
   value = atoi(arr);
   
   valueTbl[valueIdx] = value;
   cout << valueTbl[valueIdx] << endl;
   valueIdx++;
   count++;
  }
  pos = 0;
  i += digitLength + 1;
 }

 //convert inFix to have symbols A B C...
 char ch;
 int f = 0;
 char copyArr[digitLength + 500];
 pos = 0;
 
 for(int i = 0; i < strlen(inFix); i++)
 {
  ch = f + 65;
  if(inFix[i] >= '0' && inFix[i] <= '9')
  {
   curIdx = i;
   lastIdx = FindLast(curIdx);
   lastIdx--;
   digitLength = (lastIdx - curIdx) + 1;
   
   copyArr[pos] = ch;  
   pos++;
  
   i = i + digitLength;
   f++;
  }
  if((int(inFix[i]) >= 40 && int(inFix[i]) <= 43) || (int(inFix[i]) == 45 || (int(inFix[i]) == 47)))
  {
   copyArr[pos] = inFix[i];
   pos++;
  }
 }
 strcpy(inFix, copyArr);
  
 for(int i = 0; i < strlen(inFix); i++)
  cout << inFix[i];
 cout << endl;
}

int Calc::FindLast(int cur)
{
 while(inFix[cur] >= '0' && inFix[cur] <= '9')
  cur++;

 return cur;
}

bool Calc::CheckParens()
{
 bool balance = true;
 int count = 0;
 int i = 0;
 Stack stk;
 
 while(balance == true && count != strlen(inFix))
 {
  if(inFix[i] == '(')
   stk.Push(inFix[i]);
  else
  {
   if(inFix[i] == ')')
   {
    if(!stk.IsEmpty())
     stk.Pop();
    else
     balance = false;
   }
  }
  count++;
  i++;
 }
 
 if(balance == true && stk.IsEmpty() == true)
  return true;
 else
  return false; 
}

void Calc::DisplayInFix()
{
 cout << "InFix is ";
 for(int i = 0; i < strlen(inFix); i++)
  cout << inFix[i];
 cout << endl;
}

