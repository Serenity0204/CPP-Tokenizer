#include <iostream>
#include "myCstrings.h"
using namespace std;

#ifndef GETTOKEN_H
#define GETTOKEN_H


const int MAX_TOKEN_SIZE = 50;
const int CAPACITY = 10000;
// ---------------------------------------------------------------------- // 
// Grabs blocks of text from the inFile, copies them to the block[] array and copies the (next) token into the token[] array.
// On future calls to this function, the next tokens will be copied into the token array[]...
// Once the end of the block[] string has been reached, another block is retrieved from the file and copied into block[] and this process continues.
// Once the end of the file has been reached, false will be returned, otherwise (in case of a successful token retrieval), true is returned.
bool GetToken(char block[], char token[], char& tokenType, int& pos);
// ---------------------------------------------------------------------- // 




// ---------------------------------------------------------------------- // 
// Creates a substring of characters from MyString that can be found inside a character set, starting from a particular position.
int Tokenizer(char block[], char charSet[], char subString[], int pos);
// ---------------------------------------------------------------------- // 


void Process(char token[], char tokenType);
void WordTable(char token[]);
void generateReport();
bool isIn(char token[], int &idx);
void sort();




#endif // GETTOKEN_H