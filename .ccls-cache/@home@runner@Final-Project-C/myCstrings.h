#include <iostream>
using namespace std;

#ifndef MYCSTRINGS_H
#define MYCSTRINGS_H





// Lower-Level Cstring Functions:
int StrLen(char str[]);
// Returns the length of the C string str. (null character, ‘\0’, is not counted in the length.)
void StrCpy(char destination[], char source[]);
// Copies the C string source into array destination, including the terminating null char.
void StrNCpy(char destination[], char source[], int num);
// Copies the first num characters of the source to destination.
void StrCat(char destination[], char source[]);
// Appends a copy of the source string to the destination string.
void StrNCat(char destination[], char source[], int num);
// Appends the first num characters of source to destination, plus a terminating null char.
int StrCmp(char str1[], char str2[]);
// This function starts comparing the first character of each string.
// If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
// If the str1 is larger, return 1. If the str2 is larger, return -1. If the two strings are the same, return 0.
int StrChr(char str[], char target, int pos=0);
// Returns a position to the first occurrence of the character in the C string str starting at a particular position. If the character is not found, the function returns -1.
int StrRChr(char str[], char target, int pos=0);
// Returns a position to the last occurrence of the character in the C string str starting at a particular position. If the character is not found, the function returns -1.
int StrStr(char str1[], char str2[], int pos=0);
// Returns position to the first occurrence of str2 if str2 is part of str1 starting at a particular position, or -1 if str2 is not part of str1.
void SubStr(char source[], char str[], int start, int length);
// Starting from the “start” index of source, characters will be copied into the str length specifying how many characters will be copied over.
void Reverse(char str[]);
// reverse the source string
int FindFirstOf(char source[], char charSet[], int pos=0);
// Finds the first character in the source that is found in charSet starting at a particular position and returns its position. If the character is not found, the function returns -1.
// You only have one loop because you call StrChr function
int FindFirstNotOf(char source[], char charSet[], int pos=0);
// Finds the first character in the source that is NOT found in charSet starting at a particular position and returns its position. If the character is found, returns -1.
// You only have one loop because you call StrChr function
 
// Additional functions to include:
int ToInt(char str[], int pos=0);
// Returns first int in str starting from a particular position
int AtoI(char str[]);
// Converts array of characters to an integer
int CharToInt(char ch);
// Converts a single character to an integer
void ToUpper(char str[]);
// Converts the C string to uppercase.
void ToLower(char str[]);
// Converts the C string to lowercase.
bool Eq(char str1[], char str2[]);
// Returns true if str1=str2
bool GT(char str1[], char str2[]);
// Returns true if str1>str2
bool LT(char str1[], char str2[]);
// Returns true if str1<str2
 
void Show(char str[], int pos);
// Prints the string and a marker on the next line corresponding to position
// Show("abcdef", 4) will print:
// abcdef
// ...^
// This will be very useful when you debug and want to know where your position is pointing to.
bool isDigit(char c);

int CharToInt(char c);

#endif // MYCSTRINGS_H