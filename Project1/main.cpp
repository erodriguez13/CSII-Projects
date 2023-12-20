/* This program requires the student to write 8 functions. Some described
* in Program project 4 (Page 537) and Program Project 6 (Page 538).
* The student also
 *
* Author: Your Name
* Version: The date
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
void print(const string* dynamicArray, int size);

void reverse(char* front, char* rear);
// Precondition: The front and rear are pointing to the front
//               and rear of a C-string, respectively
// Postcondition: The C-string is reversed
void encode(char* word1, char* word2);
// Precondition: The word1 and word2 are pointing to the first char of 2 C-strings.
//               The C-strings are of equal length.
// Postcondition: Each word will switch even numbered letters.
void decode(char* word1, char* word2);
// Precondition: The word1 and word2 are pointing to the first char of 2 C-strings.
//               The C-strings are of equal length.
// Postcondition: Will reverse the encode changes
void encode(char* word1, int addTo);
// Precondition: The word1 is pointing to the first char of a C-string. addTo is the number
//               to be added to the ascii code.
// Postcondition: Word1 will be encoded where the letters will be changed. Example would be the
//                word 'act' and 2 will result in "cev" where 2 was added to the ascii letters 'a'
//                'c' and 't'.
bool findEntry(string* myArray, int& ndx, string wordToFind);
// Precondition: myArray point to a array of strings, ndx is inital value,
//               newEntry is a string
// Postcondition: Function returns true or false if wordToFind is in the string array myArray.
//                ndx will be the index of the wordToFind in the string array myArray.
string* addEntry(string* dynamicArray, int& size, string newEntry);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: A new dynamic array is created, which is one larger than
//                dynamicArray All elements from dynamicArray are copied to
//                new array, the new entry is added to new array, the size
//                is increased, the dynamicArray is deleted, new dynamic
//                array is returned.
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete);
// Precondition: dynamicArray point to a array of strings with give size,
//               newEntry is a string
// Postcondition: The function should search dynamicArray for entryToDelete.
//                If not found, the request should be ignored and the
//                unmodified dynamicArray returned. If found, create a new
//                dynamic array one element smaller than dynamicArray. Copy
//                all element except entryToDelete into the new array, delete
//                dynamicArray, decrement size, and return the new dynamic
// array
void print(const string* dynamicArray, int size);
// Precondition: dynamicArray point to a array of strings with give size,
// Postcondition: The elements in dynamic array will be print out. One
//                element per line forllowed by its index
int main() {
   // write code to test reverse function.
   // make sure that you test it on at least two strings
   // one string has even length, another string has odd length
   // write code to test add entry and delete entry function
   // you may watch video notes to get idea for this part
return 0; }
void reverse(char* front, char* rear)
{
   // you implement this. Please read Programming Project 4 on page 537
}

void encode(char* word1, char* word2) {
   // you implement this.
}

void decode(char* word1, char* word2) {
   // you implement this.
}

void encode(char* word1, int addTo) {
   // you implement this.
}

bool findEntry(string* myArray, int& ndx, string wordToFind)
{
   // you implement this.
}

string* addEntry(string* dynamicArray, int& size, string newEntry)
{
   // you implement this. Please read Programming Project 6 on page 538
   // you may watch video notes to get the idea
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
   // you implement this. Please read Programming Project 6 on page 538
   // you may watch video notes to get the idea
}

void print(const string* dynamicArray, int size)
{
   // you implement this.
   // you may watch video notes to get the idea
}
