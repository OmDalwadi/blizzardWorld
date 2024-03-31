#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#include "World.h"

string description[DESCRIPTION_COUNT];

void worldClear (World world)
{
  for(int i = 0; i < ROW_COUNT; i++)
  {
    for(int j = 0; j < COLUMN_COUNT; j++)
    {
      world[i][j] = 0;
    } 
  }
 }

void worldLoadAll (World world, string game_name)
{
  string filename = game_name + "_grid.txt";
  worldLoadNodes(world, filename);
  string description = game_name + "_text.txt";
  worldLoadDescriptions(world,description);
}
void worldLoadNodes (World world, string filename)
{
  ifstream inData;
  inData.open(filename.c_str());
  if (inData.fail())
  {
    cout << "Couldn't load the values" << endl;
    exit (1);
  }  

  for(int i = 0; i < ROW_COUNT; i++)
  {
    for(int j = 0; j < COLUMN_COUNT; j++)
    {
    inData >> world[i][j];
    }
  }
  inData.close();
}

void worldLoadDescriptions (World world, string filename)
{
  ifstream inData;
  inData.open(filename.c_str());
  if (inData.fail())
  {
    cout << "Couldn't load the values" << endl;
    exit (1);
  }  

  string line1;
  getline (inData,line1);
  getline(inData,line1);
  for(int i = 0; i < DESCRIPTION_COUNT; i++)
  {
    string line = "";
    getline(inData, line);
    while(line != "")
    {
      string data = description[i];
      description[i] = data + line + "\n";
      getline(inData,line);
    }
  }  
  inData.close();  
}

void worldDebugPrint (const World world)
{
  for(int i = 0; i < ROW_COUNT; i++)
  {
    for(int j = 0; j < COLUMN_COUNT; j++)
    {
      cout << world[i][j] << "\t";
    }
    cout << endl; 
  } 
}

bool worldIsValid (const World world, int row, int column)
{ 
  if (row > ROW_COUNT || row < 0 || column > COLUMN_COUNT || column < 0)
    return false;
  else
    return true;
}

bool worldCanGoNorth (const World world, int row, int column){
  if (world[row-1][column] == 0 || row == 0) 
    return false;
  else
    return true;
}

bool worldCanGoSouth (const World world, int row, int column){
  if (world[row+1][column] == 0 || row+1 == ROW_COUNT) 
    return false;
  else
    return true;
 }

bool worldCanGoEast  (const World world, int row, int column){
  if (world[row][column+1] == 0 || column+1 == COLUMN_COUNT) 
    return false;
  else
    return true;
 }

bool worldCanGoWest  (const World world, int row, int column){
  if (world[row][column-1] == 0 || column == 0) 
    return false;
  else
    return true;
 }

bool worldIsDeath   (const World world, int row, int column){
  if (world[row][column] == 3)
    return true; 
  else
    return false;
}

bool worldIsVictory (const World world, int row, int column){ 
  if (world[row][column] == 5)
    return true; 
  else
    return false;
 }

void worldFindValue (const World world, int& row, int& column, NodeValue value_to_find)
{ 
  row = -1;
  column = -1;
  for(int i = 0; i < ROW_COUNT; i++)
  {
    for(int j = 0; j < COLUMN_COUNT; j++)
    {
      if (world[i][j] == value_to_find)
      {
       row = i;
       column = j;
      }
    }
  }
}

void worldPrintDescription (const World world, int row, int column)
{
  unsigned int j = world[row][column];
  cout << description[j] << endl;
}
void worldPrintStartMessage (const World world)
{
  cout << description[START_MESSAGE];
}
void worldPrintEndMessage (const World world)
{
  cout << description[END_MESSAGE];
}