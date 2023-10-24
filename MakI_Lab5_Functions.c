#include "MakI_Lab5.h"

//-----------------------------------------------------------------------------
// Function Name: PrintHeader
// Description:
//   Prints the Header to the screen
//
//-----------------------------------------------------------------------------
void PrintHeader(FILE* outputFile, char school[], char lab[], char programmer[]) 
{
  PrintDivider(outputFile, STAR, DIVIDER_LENGTH);

  CenterString(outputFile, school, DIVIDER_LENGTH);
  CenterString(outputFile, lab, DIVIDER_LENGTH);
  CenterString(outputFile, programmer, DIVIDER_LENGTH);

  PrintDivider(outputFile, STAR, DIVIDER_LENGTH);
} 


//-----------------------------------------------------------------------------
// Function Name: PrintDivider
// Description:
//   Symbols will be printed to the screen. 
//
//-----------------------------------------------------------------------------
void PrintDivider(FILE* outputFile, char symbol, int numberOf)
{
  // Print a bunch of symbols across the screen
  for (int counter = 0; counter < numberOf; counter++)
  {
    // Print one character to the screen
    fprintf(outputFile, "%c", symbol);
  }

  // Move the cursor down to the next line
  fprintf(outputFile, "\n");

}

//-----------------------------------------------------------------------------
// Function Name: CenterString
// Description:
//   The array of characters passed into the function will be centered
//  across the screen using the following formula:
//  
//    (lengthToCenterAcross + the string length) / 2
//
//-----------------------------------------------------------------------------
void CenterString(FILE* outputFile, char string[], int lengthToCenterAcross)
{
  // Capture how long the string is
  // Cast to an integer because strlen technically returns size_t
  int stringLength = (int)strlen(string);

  // Calculate the width to print the string in
  int width = (lengthToCenterAcross + stringLength) / 2;

  // Calculate how many blank spaces are needed before printing the string
  int numberOfBlankSpaces = width - stringLength;

  // Print the spaces needed to center the string
  for(int counter = 0; counter < numberOfBlankSpaces; counter++)
  {
    // Print one space
    fprintf(outputFile, " ");	
  }

  // Print the string
  fprintf(outputFile, "%s", string);

}

void PrintTableHeader(FILE* outputFile)
{
  fprintf(outputFile, "%22s%22s%22s\n", MONSTER, COLOR, STRENGTH);
}

int GetColorCode(int number)
{
  int startBit = 1; // Start at bit 10 (0-based index)
  int bitCount = 2; // Extract 4 bits
  int mask = ((1 << bitCount) - 1) << startBit; // Create a mask to extract the specified bits

  int colorCode = (number & mask) >> startBit; // Extract the bits
  return colorCode;
}

int GetMonsterCode(int number)
{
  int startBit = 4; // Start at bit 10 (0-based index)
  int bitCount = 2; // Extract 4 bits
  int mask = ((1 << bitCount) - 1) << startBit; // Create a mask to extract the specified bits

  int monsterCode = (number & mask) >> startBit; // Extract the bits
  return monsterCode;
}

int GetStrength(int number)
{
  int startBit = 6; // Start at bit 10 (0-based index)
  int bitCount = 8; // Extract 4 bits
  int mask = ((1 << bitCount) - 1) << startBit; // Create a mask to extract the specified bits

  int monsterStrength = (number & mask) >> startBit; // Extract the bits
  return monsterStrength;
}

void GetColor(int colorCode, char color[])
{
  switch(colorCode)
  {
    case 0: 
      strcpy(color, "Brown");
      break;
    case 1:
      strcpy(color, "Red");
      break;
    case 2:
      strcpy(color, "Green");
      break;
    case 3:
      strcpy(color, "White");
      break;
  }
}

void GetMonster(int monsterCode, char monster[])
{
  switch(monsterCode)
  {
    case 0: 
      strcpy(monster, "Dragon");
      break;
    case 1:
      strcpy(monster, "Goblin");
      break;
    case 2:
      strcpy(monster, "Troll");
      break;
    case 3:
      strcpy(monster, "Ghost");
      break;
  }
}

void PrintLineOfData(FILE* outputFile, char monster[], char color[], int strength)
{
  fprintf(outputFile, "%22s%22s%22d\n", monster, color, strength);
}