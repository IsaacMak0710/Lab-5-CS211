/*
|--------------------------------------------------------------------------------------------------
| Programmers Name: Enter Name 
| Course:           CS-211: Introduction to Programming for Engineers
| Program  Name:    Lab #4
| Date:             10/10/2023
|
|--------------------------------------------------------------------------------------------------
| Program Description:
|   Scan through a file with numbers to calculate and print data using the data inside the numbers.txt file
|
|
|--------------------------------------------------------------------------------------------------
| Inputs:
|   Inputs that were used are the functions in the Function file, number, oddCounter, evenCounter, oddAccumulator, evenAccumulator, counter, average, and the input and output files
|  
|
|--------------------------------------------------------------------------------------------------
| Processing:
|   The calcuations done in this lab are the functions that update the rows of data in the file and calculating the averages of the even and odd numbers.
|  
|
|--------------------------------------------------------------------------------------------------
| Outputs:
|   Average odd number: 127.67
|   Average even number: 197.12
|   All the data in the table for ODD_COUNTER, EVEN_COUNTER, TOTAL_ODD_NUMBERS, and TOTAL_EVEN_NUMBER
|
|--------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include "MakI_Lab5.h"

int main(void) {

  // Declare two strings of 10 characters each
  char monster[10];
  char color[10];

  int number;
  int monsterCode;
  int colorCode;
  int monsterStrength;

  // Declare two file pointers
  FILE* pInputFile = fopen("Lab5_DataFile.txt", "r");
  FILE* pOutputFile = fopen("Lab5_Output.txt", "w");
  
  // Print Header
  PrintHeader(pOutputFile, SCHOOL, LAB, PROGRAMMER);

  // Print Table Header
  PrintTableHeader(pOutputFile);

  // Print Divider
  PrintDivider(pOutputFile, DASH, DIVIDER_LENGTH);

  // File Processing Loop
  if (pInputFile == NULL) 
  {
    perror("Error opening the file");
    return 1;
  }

  fscanf(pInputFile, "%d", &number);
  while (!feof(pInputFile))
  {
    monsterCode = GetMonsterCode(pInputFile, number);
    colorCode = GetColorCode(pInputFile, number);
    monsterStrength = GetStrength(pInputFile, number);
    GetMonster(monsterCode, monster);
    GetColor(colorCode, color);
    PrintLineOfData(pOutputFile, monster, color, monsterStrength);
    fscanf(pInputFile, "%d", &number);
  }

  
  return 0;
}