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

int main(int argc, char* argv[])
{
 Calc* C = new Calc(argv[1]);

 delete C;
 return 0;
}
