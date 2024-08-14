
/*
Name: Colleen Lemak
Class: CPSC 122, Section 2
Date: February 20, 2021
Assignment: Project 7
Description: the program uses the Transposition Cipher to encrypt and decrypt a file using randomly generated keys.
*/

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;

const int SIZE = 26;

void fileOpen(fstream&, string, char);
void keyGen(string);
void fileControl(string, string, string, int);
char transform(char, int[][2]);
void selection_sort(int arr[][2], int length);
int find_small(int start, int arr[][2], int length);
void swap(int pos, int idx_small, int arr[][2]);

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
Description: Opens key file.  Generates and stores encrypt and decrypt keys.  This can be stored any way that you like as long as two 2-D arrays can be constructed from the file, one for encryption and one for decryption. 
Input: name of the file in which to store generated keys
Output: file holds generated encryption and decryption keys 
*/
void keyGen(string keyFile)
{
 fstream fout;
 int encryptArray[SIZE][2];
 int decryptArray[SIZE][2];
 int keyStorage[SIZE];
 bool validate[SIZE];
 int pos = 0;
 int k = 0;

 for(int i = 0; i < SIZE; i++) 
  validate[i] = false;

 srand(time(NULL));
 fileOpen(fout, keyFile, 'w');

 while(pos < SIZE)
 {  
  k = rand() % SIZE;
  if(validate[k] == 0)
  {
   keyStorage[pos] = k;
   fout << keyStorage[pos] << endl;
   encryptArray[pos][1] = keyStorage[pos];
   decryptArray[pos][0] = encryptArray[pos][1];
   validate[k] = true;
   pos++;
  }
 }
      
  for(int i = 0; i < SIZE; i++)
   encryptArray[i][0] = i;

  for(int i = 0; i < SIZE; i++)
   decryptArray[i][1] = i;

  selection_sort(decryptArray, SIZE);

  for(int i = 0; i < SIZE; i++)
   fout << decryptArray[i][1] << endl;

  fout.close();
}

/*
Description: invokes fileOpen on all files.  closes all files.  Reads key file. Constructs two 2-D arrays, one for encryption, one for decryption.  Reads the input file and either invokes encrypt or decrypt,  depending on the value of mode.  Writes to the output file. 
Input: names of key file, input file and output file. mode value of 1 or 2
Output: writes to the output file
*/
void fileControl(string keyFile, string fileIn, string fileOut, int mode)
{
  fstream fin;
  fstream fout;
  int encryptedValues[SIZE][2];
  int decryptedValues[SIZE][2];
  char ch;
  int temp = 0;
  int temp2 = 0;

  fileOpen(fin, keyFile, 'r');
  
  for(int i = 0; i < SIZE; i++)
   encryptedValues[i][0] = i;

  for(int i = 0; i < SIZE; i++)
   fin >> encryptedValues[i][1];
  
  for(int i = 0; i < SIZE; i++)
   decryptedValues[i][0] = i;

  for(int i = 0; i < SIZE; i++)
   fin >> decryptedValues[i][1];

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
     ch = transform(ch, encryptedValues);
    if(mode == 2)
     ch = transform(ch, decryptedValues);
   }
  fout.put(ch);
  }
  
  fin.close();
  fout.close();

}

/*
Description: Encrypts/Decrypts an upper case alphabetic character using the transposition cipher. Operation depends on whether it is sent the encrypt or decrypt key
Input: upper case alphabetic character, 2-D encryption or decryption array
Returns: encrypted or decrypted  version of ch
*/
char transform(char ch, int encDec[SIZE][2])
{
 int index = ch - 'A';

 for(int i = 0; i < SIZE; i++)
 {
  if(encDec[i][0] == index)
  {
   ch = encDec[i][1];
   break;
  }
 }
 ch += 'A';

 return ch;
}

/*
Description: outer, control loop for selection sort  
Input: array of integers to be sorted along with its length
Output: array is sorted at the end of function
*/
void selection_sort(int arr[][2], int length)
{
 int pass = 0;
 int start = 0;
 int idx_small; 
 
 while(pass < length - 1) 
 {
  idx_small = find_small(start, arr, length);
  swap(start,idx_small,arr);
  start++;
  pass++; 
 }
}

/*
Description: linear search through an array looking for smallest element
Input: position to start search, array, length of array
Output: returns smallest element in the array
*/
int find_small(int start, int arr[][2], int length)
{
 int idx_small = start;  
 int next = start + 1;
 while(next < length)         
 {
  if (arr[next][0] < arr[idx_small][0])
     idx_small = next;
  next++;                       
 }
 return idx_small;
}


/*
Description: swaps the contents of two posiitons in an array 
Input: position whose contents is swapped with smallest,  position of smallest, array 
Output: returns smallest element in the array
*/
void swap(int pos, int idx_small, int arr[][2])
{
 int temp = arr[pos][0];
 arr[pos][0] = arr[idx_small][0];
 arr[idx_small][0] = temp;
 
 int temp2 = arr[pos][1];
 arr[pos][1] = arr[idx_small][1];
 arr[idx_small][1] = temp2;
}


