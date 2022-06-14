#include "myCstrings.h"



// Returns the length of the C string str. (null character, ‘\0’, is not counted in the length.)
int StrLen(char str[])
{
  int i = 0;
  while(str[i] != '\0')
  {
    i++;
  }
  return i;
}



// Copies the C string source into array destination, including the terminating null char.
void StrCpy(char destination[], char source[])
{
  int l = StrLen(source);
  StrNCpy(destination, source, l);
}


// Copies the first num characters of the source to destination.
void StrNCpy(char destination[], char source[], int num)
{
  int i = 0;
  while(source[i] != '\0' && i < num)
  {
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
}


// Appends a copy of the source string to the destination string.
void StrCat(char destination[], char source[])
{
  int l = StrLen(source);
  StrNCat(destination, source, l);

}



// Appends the first num characters of source to destination, plus a terminating null char.
void StrNCat(char destination[], char source[], int num)
{
  int i = StrLen(destination);
  int j = 0;
  while(source[j] != '\0' && j < num)
  {
    destination[i] = source[j];
    i++;
    j++;
  }
  destination[i] = '\0';
}




// This function starts comparing the first character of each string.
// If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.
// If the str1 is larger, return 1. If the str2 is larger, return -1. If the two strings are the same, return 0.
int StrCmp(char str1[], char str2[])
{
  int i = 0;
  while(str1[i] != '\0' && str2[i] != '\0')
  {
    if(str1[i] > str2[i]) return 1;
    if(str1[i] < str2[i]) return -1;
    i++;
  }
  if(str1[i] != '\0') return 1;
  if(str2[i] != '\0') return -1;
  return 0;
}





// Returns a position to the first occurrence of the character in the C string str starting at a particular position. If the character is not found, the function returns -1.
int StrChr(char str[], char target, int pos)
{
  int i = pos;
  while(str[i] != '\0')
  {
    if(str[i] == target)
    {
      return i;
    }
    i++;
  }
  return -1;
}



// Returns a position to the last occurrence of the character in the C string str starting at a particular position. If the character is not found, the function returns -1.
int StrRChr(char str[], char target, int pos)
{
  int i = pos;
  int idx = -1;
  while(str[i] != '\0')
  {
    if(str[i] == target) idx = i;
    i++;
  }
  return idx;
}







// Returns position to the first occurrence of str2 if str2 is part of str1 starting at a particular position, or -1 if str2 is not part of str1.
int StrStr(char str1[], char str2[], int pos)
{
  int str1Length = StrLen(str1);
  int str2Length = StrLen(str2);
  
  for(int i = pos; i <= str1Length - str2Length; ++i)
  {   
    int j;
    for(j = 0; j < str2Length; ++j)
    {
      if(str1[i + j] != str2[j]) break;
            
    }
    if(j == str2Length) 
    {
      return i;
    }
  }
  return -1;
}






// Starting from the “start” index of source, characters will be copied into the str length specifying how many characters will be copied over.
void SubStr(char source[], char str[], int start, int length)
{
  int i = start;
  int j = 0;
  while(source[i] != '\0' && i < length + start)
  {
    str[j] = source[i];
    i++;
    j++;
  }
  str[j] = '\0';
}



// reverse the source string
void Reverse(char str[])
{
  int i = 0;
  int j = StrLen(str) - 1;
  while(i < j)
  {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}



// Finds the first character in the source that is found in charSet starting at a particular position and returns its position. If the character is not found, the function returns -1.
// You only have one loop because you call StrChr function
int FindFirstOf(char source[], char charSet[], int pos)
{
  int l = StrLen(source);
  for(int i = pos; i < l; ++i)
  {
    char target = source[i];
    int res = StrChr(charSet, target, 0);
    if(res != -1) return i;
  }
  return -1;
}



// Finds the first character in the source that is NOT found in charSet starting at a particular position and returns its position. If the character is found, returns -1.
// You only have one loop because you call StrChr function
int FindFirstNotOf(char source[], char charSet[], int pos)
{
  int l = StrLen(source);
  for(int i = pos; i < l; ++i)
  {
    char target = source[i];
    int res = StrChr(charSet, target, 0);
    if(res == -1) return i;
  }
  return -1;
  
}



// Returns first int in str starting from a particular position
int ToInt(char str[], int pos)
{
  int i = pos;
  while(str[i] != '\0')
  {
    if(str[i] >= 48 && str[i] <= 57) return i;
    i++;
  }
  return -1;
}





// Converts array of characters to an integer
int AtoI(char str[])
{
  int i;
  if(str[0] == '-')
  {
    i = 1;
  }
  else
  {
    i = 0;
  }
  int integer = 0;
  while(str[i] != '\0')
  {
    integer = integer * 10  + (str[i] - 48);
    i++;
  }
  if(str[0] == '-') return -1 * integer;
  return integer;
}



bool isDigit(char c)
{
  char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for(int i = 0; i < 10; ++i)
  {
    if(arr[i] == c)
    {
      return true;
    }
  }
  return false;
}


int CharToInt(char c)
{
  if(isDigit(c)) return c - 48;
  if(c >= 65 && c <= 90) return c - 'A' + 10;
  if(c >= 97 && c <= 122) return c - 'a' + 10;
  return -1;
}


// Converts the C string to uppercase.
void ToUpper(char str[])
{
  int i = 0;
  while(str[i] != '\0')
  {
    if(str[i] >= 97 && str[i] <= 122)
    {
      str[i] -= 32;
    }
    i++;
  }
}



// Converts the C string to lowercase.
void ToLower(char str[])
{
  int i = 0;
  while(str[i] != '\0')
  {
    if(str[i] <= 90 && str[i] >= 65)
    {
      str[i] += 32;
    }
    i++;
  }
  
}


// Returns true if str1=str2
bool Eq(char str1[], char str2[])
{
  int res = StrCmp(str1, str2);
  if(res == 0) return true;
  return false;
}


// Returns true if str1>str2
bool GT(char str1[], char str2[])
{
  int res = StrCmp(str1, str2);
  if(res == 1) return true;
  return false;
}

// Returns true if str1<str2
bool LT(char str1[], char str2[])
{
  int res = StrCmp(str1, str2);
  if(res == -1) return true;
  return false;
}





// Prints the string and a marker on the next line corresponding to position
// Show("abcdef", 4) will print:
// abcdef
// ...^
// This will be very useful when you debug and want to know where your position is pointing to.
void Show(char str[], int pos)
{
  int i = 0;
  while(str[i] != '\0')
  {
    cout << str[i];
    i++;
  }
  cout << endl;
  int j = 0;
  while(j < pos)
  {
    if(j == pos - 1)
    {
      cout << '^';
    }
    else
    {
      cout << '.';
    }
    j++;
  }
}



