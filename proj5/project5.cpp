/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: February 5, 2021
Assignment: Project 5
Description: the program uses Caesar cipher to encrypt and decrypt a file using a randomly generated key.
*/

#include <iostream>
#include <fstream> 
#include <cstdlib>  //necessary for the constant EXIT_FAILURE
#include <string>
#include <time.h>
using namespace std;

void fileOpen(fstream&, string, char);
void generateKey(string);
int keyGen();
char encryptMessage(char, int);
char decryptMessage(char, int);
void encryptProcess(string, string, string);
void decryptProcess(string, string, string);

int main(int argc, char* argv[])
{
 int mode = atoi(argv[1]);

 if(mode == 0)
  generateKey(argv[2]);

 if(mode == 1)
 {  
  encryptProcess(argv[2], argv[3], argv[4]);
 }

 if(mode == 2)
 {
  decryptProcess(argv[2], argv[3], argv[4]);
 }
}

/*
Description: function opens a file 
Input: file stream object reference, name of the file, mode of open
Output: void function, but at exit, file stream object is tied to 
the input file name. 
*/ 
void fileOpen(fstream& file, string name, char mode)
{
 string fileType;

 if (mode == 'r')
  fileType = "input";
 if (mode == 'w')
  fileType = "output";

 if (mode == 'r')
  file.open(name, ios::in);  //available thorugh fstream
 if (mode == 'w')
  file.open(name, ios::out);  //available through fstream;

 if (file.fail()) //error condition 
 {
  cout << "Error opening " << fileType << " file" << endl; 
  exit(EXIT_FAILURE);
 }
}

/*
Description: Randomly generates a key (with keyGen() function), and opens file for writing with fileOpen() function)
Input: reference to string keyFile
Output: writes a randomly generated integer in the range [1..25] to keyFile 
*/
void generateKey(string keyFile)
{
 fstream fout;
 int key = keyGen(); 
 fileOpen(fout, keyFile, 'w');
 fout << key;
 fout.close();
}

/*
Description: Randomly generates an integer in the range: [1..25]
Input: no arguments passed in
Output: returns a randomly generated integer in the range [1..25]
*/
int keyGen()
{
 int randNum = 0;
 srand(time(NULL));
 randNum = (rand() % 25) + 1;
 return randNum;
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encryptMessage(char ch, int key)
{
 int pos = ch - 'A';
 pos = (pos + key) % 26;
 ch = pos + 'A';

 return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decryptMessage(char ch, int key)
{
 int pos = ch - 'A';
 pos = (pos - key) % 26;
 ch = pos + 'A';

 return ch;
}

/*
Description: Encrypts an upper case alphabetic character using the Caesar cipher by calling another encrypting function and after it writes to output file
Input: argv[2], argv[3], arg[4]
Returns: none
*/
void encryptProcess(string filename1, string filename2, string filename3)
{
  fstream fin;
  fstream fout;
  char ch = ' ';
  char newCh = ' ';
  int key = 0;
 
  fileOpen(fin, filename1, 'r');
  fin >> key;
  fin.close();
  fileOpen(fin, filename2, 'r');
  fileOpen(fout, filename3, 'w');

  while (fin.peek() != EOF)
  {
  ch = fin.get();
  if(isalpha(ch))
  {
   ch = toupper(ch);
   newCh = encryptMessage(ch, key);
  }
  else
  {
   newCh = ch;
  }
  cout << newCh;
  fout << newCh;
  }

  fin.close();
  fout.close();
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher by calling another decrypting function and after writes to output file
Input: argv[2], argv[3], arg[4]
Returns: none
*/
void decryptProcess(string filename1, string filename2, string filename3)
{
  fstream fin;
  fstream fout;
  char ch = ' ';
  char newCh = ' ';
  int key = 0;
  fileOpen(fin, filename1, 'r');
  fin.close();
  fileOpen(fin, filename2, 'r');
  fileOpen(fout, filename3, 'w');

  while (fin.peek() != EOF)
  {
  ch = fin.get();
  if(isalpha(ch))
  {
   ch = toupper(ch);
   newCh = decryptMessage(ch, key);
  }
  else
   newCh = ch;
  cout << newCh;
  fout << newCh;
  }
  fin.close();
  fout.close();
}

