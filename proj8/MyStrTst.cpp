/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: 2 March 2021
Assignment: Project 8
Description: Program illustrates using class MyString 
*/

#include "MyStr.h"
#include <iostream> 
using namespace std;


int main(int argc, char* argv[])
{
 MyString str1(argv[1]);
 MyString* str2 = new MyString(argv[1]);

 /*
 //Test of myDisplay
 cout << "***************************************" << endl;
 cout << "*****Test 1 myDisplay*****" << endl;
 cout << "static test" << endl;
 cout << "output should be the command line input." << endl;
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 myDisplay*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be the command line input." << endl;
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myDisplay
 */
 
 /*
 //Test of myStrcpy
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrcpy*****" << endl;
 cout << "static test" << endl;
 cout << "contents of strIn should replace MyString and should be outputted." << endl;
 str1.myStrcpy("howdy");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 myStrcpy*****" << endl;
 cout << "dynamic test" << endl;
 cout << "contents of strIn should replace MyString and should be outputted." << endl;
 str2->myStrcpy("howdy");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrcpy
 */

 /*
 //Test of myStrlen
 cout << "***************************************" << endl;
 cout << "*****Test 1 myStrlen*****" << endl;
 cout << "static test" << endl;
 cout << "output should be length of str." << endl;
 str1.myStrlen();
 cout << endl;
 cout << "*****Test 2 myStrlen*****" << endl;
 cout << "dynamic test" << endl;
 cout << "output should be length of str." << endl;
 str2->myStrlen();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of myStrlen
 */

 /*
 //Test of isEqual
 cout << "***************************************" << endl;
 cout << "*****Test 1 isEqual*****" << endl;
 cout << "static test" << endl;
 cout << "should return T/F (1/0) based on if strings are equal or not." << endl;
 cout << str1.isEqual("hello");
 cout << endl;
 cout << "*****Test 2 isEqual*****" << endl;
 cout << "dynamic test" << endl;
 cout << "should return T/F (1/0) based on if strings are equal or not." << endl;
 cout << str2->isEqual("hello");
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of isEqual
 */

 /*
 //Test of concat
 cout << "***************************************" << endl;
 cout << "*****Test 1 concat*****" << endl;
 cout << "static test" << endl;
 cout << "should return string with added message." << endl;
 str1.concat("abcd");
 str1.myDisplay();
 cout << endl;
 cout << "*****Test 2 concat*****" << endl;
 cout << "dynamic test" << endl;
 cout << "should return string with added message." << endl;
 str2->concat("abcd");
 str2->myDisplay();
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of concat
 */

 /*
 //Test of find
 cout << "***************************************" << endl;
 cout << "*****Test 1 find*****" << endl;
 cout << "static test" << endl;
 cout << "returns T/F (1/0) if the strIn is a substring of str, and second number represents the index of substring match." << endl;
 cout << str1.find("llo");
 cout << endl;
 cout << "*****Test 2 find*****" << endl;
 cout << "dynamic test" << endl;
 cout << "returns T/F (1/0) if the strIn is a substring of str, and second number represents the index of substring match." << endl;
 cout << str2->find("llo");
 cout << endl;
 cout << "***************************************" << endl;
 //End Test of find
 */

 delete str2;
 return 0;  
}
   
  
