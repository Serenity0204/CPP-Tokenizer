#include "getToken.h"

char ALPHAS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZé";
char NUMBERS[] = "0123456789";
char PUNCTUATIONS[] = ",./;'[]:{}<>?~!@#$%^&*()_+-=*|\"";
char SPACES[] = {"     \n\r"};
int numWords = 0, numNumbers = 0, numPunc = 0, numSpace = 0;
char wordMap[10000000][100];
int frequency[1000000];
int size = 0;

// ---------------------------------------------------------------------- // 
// Grabs blocks of text from the inFile, copies them to the block[] array and copies the (next) token into the token[] array.
// On future calls to this function, the next tokens will be copied into the token array[]...
// Once the end of the block[] string has been reached, another block is retrieved from the file and copied into block[] and this process continues.
// Once the end of the file has been reached, false will be returned, otherwise (in case of a successful token retrieval), true is returned.
bool GetToken(char block[], char token[], char& tokenType, int& pos)
{
  if(pos == -1) return false;
  int length = StrLen(block);
  
  int check1 = StrChr(ALPHAS, block[pos]);
  if(check1 != -1)
  {
    int res = Tokenizer(block, ALPHAS, token, pos);
    pos = res;
    tokenType = 'A';
    return true;
  }

  int check2 = StrChr(NUMBERS, block[pos]);
  if(check2 != -1)
  {
    int res = Tokenizer(block, NUMBERS, token, pos);
    pos = res;
    tokenType = 'N';
    return true;
  }

  int check3 = StrChr(PUNCTUATIONS, block[pos]);
  if(check3 != -1)
  {
    int res = Tokenizer(block, PUNCTUATIONS, token, pos);
    pos = res;
    tokenType = 'P';
    return true;
  }

  int check4 = StrChr(SPACES, block[pos]);
  if(check4 != -1)
  {
    int res = Tokenizer(block, SPACES, token, pos);
    pos = res;
    tokenType = 'S';
    return true;
  }
}



// ---------------------------------------------------------------------- // 




// ---------------------------------------------------------------------- // 
// Creates a substring of characters from MyString that can be found inside a character set, starting from a particular position.
int Tokenizer(char block[], char charSet[], char subString[], int pos)
{
  int idx = FindFirstNotOf(block, charSet, pos);
  int size = StrLen(block);
  int length;
  if(idx == -1) length = size - pos;
  else length = idx - pos;
  
  SubStr(block, subString, pos, length);
  return idx;
}
// ---------------------------------------------------------------------- // 

void Process(char token[], char tokenType)
{
  if(tokenType == 'A')
  {
    WordTable(token);
    numWords++;
  }
  if(tokenType == 'N')
  {
    int l = StrLen(token);
    numNumbers += l;
    return;
  }
  if(tokenType == 'P')
  {
    int l = StrLen(token);
    numPunc += l;
    return;
  }
  if(tokenType == 'S')
  {
    int l = StrLen(token);
    numSpace += l;
    return;
  }
}


bool isIn(char token[], int &idx)
{
  for(int i = 0; i < size; ++i)
  {
    if(Eq(wordMap[i], token))
    {
      idx = i;
      return true;
    }
  }
  idx = -1;
  return false;
}


void WordTable(char token[])
{
  int idx;
  ToLower(token);
  bool checker = isIn(token, idx);
  if(!checker)
  {
    StrCpy(wordMap[size], token);
    frequency[size] = 1;
    size++;
    return;
  }
  frequency[idx]++;
  return;
}

void generateReport()
{
  cout << "Number of Words: " << numWords << endl;
  cout << "Number of Numbers: " << numNumbers << endl;
  cout << "Number of Punctuations: " << numPunc << endl;
  cout << "Number of Spaces: " << numSpace << endl;
  sort();
  cout << endl;
  for(int i = 0; i < 20; ++i)
  {
    cout << i + 1 << "th Word: " << wordMap[i] << " frequency: " << frequency[i] << endl; 
  }
}


void sort()
{
  for (int i = 0; i < size - 1; i++)  
  {
      for (int j = 0; j < size - i -1; j++)
      {       
        if (frequency[j] < frequency[j + 1])
        {
          swap(frequency[j], frequency[j+1]);
          char temp[100];
          StrCpy(temp, wordMap[j]);
          StrCpy(wordMap[j], wordMap[j + 1]);
          StrCpy(wordMap[j + 1], temp);
        }
      }
  }
}
