/*
 CS2 Final Project
 Yu-Heng Lin
 5/2/2022
*/


#include <iostream>
#include <fstream>
#include "myCstrings.h"
#include "getToken.h"
#include <algorithm>
using namespace std;



int main() 
{
  ifstream inFile;
  inFile.open("TaleOfTwoCities.txt");
  char block[CAPACITY];
  char token[MAX_TOKEN_SIZE];
  char tokenType;
  do
  {

    int pos = 0;  
    inFile.read(block, CAPACITY - 1);
    block[inFile.gcount()] = '\0';

    while(GetToken(block, token, tokenType, pos)) 
    {
     Process(token, tokenType);   
    }
    
  }
  while(!inFile.eof());
  generateReport();
  
  return 0;
}


