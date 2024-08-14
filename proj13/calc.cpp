/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 20 April 2021
Assignment: Project 13
Description: Part 2 of Calculator Assignment 
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
 postFix = new char[strlen(argvIn) + 1];
 
 //CheckTokens() -- check input string's validity
 if(!CheckTokens())
 {
  cout << "Invalid string entered." << endl;
  exit(EXIT_FAILURE);
 }
 else
  cout << "Valid string entered." << endl;
 
 //CheckParens() -- see if parentheses match together properly
 if(!CheckParens())
  cout << "Incorrectly balanced parentheses." << endl;
 else
  cout << "Correctly balanced parentheses." << endl;
 
 //MakeValueTbl() -- create new integer array
 MakeValueTbl();
 
 //Parse() -- convert string to symbols, use stack, fill value table
 Parse();
 
 //InFix to PostFix -- turning inFix format to postFix
 InFixToPostFix();
 
 //DisplayInFix(), DisplayPostFix(), Evaluate() called in test file
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
 
   char arr[digitLength + 1];
    
   for(int p = curIdx; p <= lastIdx; p++)
   {
    arr[pos] = inFix[p];
    pos++;
   }
   value = atoi(arr);
   
   valueTbl[valueIdx] = value;
   valueIdx++;
   count++;
   i += digitLength;
  }
  pos = 0;
  i++;
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
 cout << endl << endl;
}

void Calc::InFixToPostFix()
{
 int pos = 0;
 char value;
 Stack stk;
 
 for(int i = 0; i < strlen(inFix); i++)
 {
  if(inFix[i] >= 'A' && inFix[i] <= 'Z')
  {
   postFix[pos] = inFix[i];
   pos++;
  }
  if((int(inFix[i]) >= 40 && int(inFix[i]) <= 43) || (int(inFix[i]) == 45 || (int(inFix[i]) == 47)))
   stk.Push(inFix[i]);
  if(inFix[i] == '(')
   stk.Push(inFix[i]);
  if(inFix[i] == ')')
  {
   if(stk.Peek() != '\0')
   {
    stk.Pop();
    value = stk.Peek();
    postFix[pos] = value;
    pos++;
    stk.Pop();
   }
  }
 }
}

void Calc::DisplayPostFix()
{
 cout << "PostFix is ";
 for(int i = 0; i < strlen(postFix); i++)
  cout << postFix[i];
 cout << endl << endl;
}

int Calc::Evaluate()
{
 char op1;
 char op2;
 int num = 0;
 char actionSymbol;
 int pos = 0;
 int second = 0;
 int first = 0;
 int result = 0;
 char newCh;
 int finalResult = 0;
 Stack stk;
 
 for(int i = 0; i < strlen(postFix); i++)
 {
  if(isupper(postFix[i]))
   stk.Push(postFix[i]);
  else
  {
   actionSymbol = postFix[i];
   op2 = stk.Peek();
   stk.Pop();
   op1 = stk.Peek();
   stk.Pop();
      
   //calculate value
   //op2 (ABC symbol) -> second value (value @ op2) || op1(ABC symbol) -> first value (value @ op1)
   pos = op2 - 65;
   second = valueTbl[pos];
   //pos = 0;
   pos = op1 - 65;
   first = valueTbl[pos];
   
   if(actionSymbol == '+')
    result = first + second;
   if(actionSymbol == '-')
    result = first - second;
   if(actionSymbol == '/')
    result = first / second;
   if(actionSymbol == '*')
    result = first * second;
   
   valueTbl[valueIdx] = result;
   newCh = valueIdx + 65;
   valueIdx++;
   stk.Push(newCh);
  }
 }
 finalResult = valueTbl[valueIdx - 1];
 cout << "FINAL RESULT: " << finalResult << endl;
 
 return finalResult;
}
