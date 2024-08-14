/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: February 12, 2021
Assignment: Project 6
Description: the program uses Affine Cipher to encrypt and decrypt a file using randomly generated keys.
*/

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

void fileOpen(fstream&, string, char);
void keyGen(string);
char encrypt(char, int, int);
char decrypt(char, int, int, int[]);
void fileControl(string, string, string, int);

int main(int argc, char* argv[])
{
 int mode = atoi(argv[1]);
 string keyFile;
 string inFile;
 string outFile;

 if(mode == 0)
 {
  keyFile = argv[2];
  keyGen(keyFile);
 }
 else
 {
  keyFile = argv[2];
  inFile = argv[3];
  outFile = argv[4];
  fileControl(keyFile, inFile, outFile, mode);
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
Description: Randomly generates alpha and beta keys and opens file for writing with fileOpen() function), randomly generates and stores alpha and beta values in keyFile file.
The alpha value is randomly drawn from the the set:  {1,3,5,7,11, 17,19,25}
The beta value is randomly drawn from the range: [1..25]  
Input: reference to string keyFile
Output: writes a randomly generated integer in the range [1..25] to keyFile, alpha and beta values on subsequent lines of keyFile
*/
void keyGen(string keyFile)
{
 fstream fout;
 int randNum = 0;
 int betaValue = 0;
 int alphaValue = 0;
 int alphaRand = 0;
 int alphaVals[8] = {1,3,5,7,11, 17,19,25};

 srand(time(NULL));
 betaValue = (rand() % 25) + 1;
 
 alphaRand = rand() % 7;
 alphaValue = alphaVals[alphaRand]; 

 fileOpen(fout, keyFile, 'w');
 fout << alphaValue << endl;
 fout << betaValue << endl;
 fout.close();
}

/*
Description: Encrypts an upper case alphabetic character
Input: upper case alphabetic character, valid key
Returns: encrypted version of ch
*/
char encrypt(char ch, int alpha, int beta)
{
 ch -= 'A';
 ch = ((alpha * ch) + beta) % 26;
 ch += 'A';

 return ch;
}

/*
Description: Decrypts an upper case alphabetic character using the Caesar cipher
Input: upper case alphabetic character, valid key
Returns: decrypted version of input
*/
char decrypt(char ch, int alpha, int beta, int MI[])
{
 ch -= 'A';
 ch = ((MI[alpha] * ch) - (MI[alpha] * beta) + 650) % 26;
 ch += 'A';

 return ch;
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2, decrypt file name to write decrypted message in
Output: none, but writes to the output file
*/
void fileControl (string keyFile, string fileIn, string fileOut, int mode)
{
  fstream fin;
  fstream fout;
  char ch;
  int alpha = 0;
  int beta = 0;
  int MI[27] = {0,1,0,9,0,21,0,15,0,3,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0,25,0};

  fileOpen(fin, keyFile, 'r');
  fin >> alpha;
  fin >> beta;
  fin.close();

  fileOpen(fin, fileIn, 'r');
  fileOpen(fout, fileOut, 'w');

  while (fin.peek() != EOF)
  {
   ch = fin.get();
   if(isalpha(ch))
   {
    ch = toupper(ch);
     if(mode == 1)
     {
      ch = encrypt(ch, alpha, beta);
     }
     if(mode == 2)
     {
      ch = decrypt(ch, alpha, beta, MI);
     }
   }
   fout.put(ch);

  fin.close();
  fout.close();
  }
}


