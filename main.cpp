#include <string>
#include <iostream>
#include "World.h"

int main()
{
  World world;
  int row, column;
  string game_name = "blizzard";
  worldLoadAll (world, game_name);
  worldFindValue (world,row,column, START_NODE);
  worldPrintStartMessage (world);
  cout << endl;
  worldPrintDescription (world, row, column);

  while(worldIsValid(world, row, column)) 
  {
    cout << "Next? ";
    char direction[1000];
    cin.getline(direction,1000);
    char a;
    switch(direction[0])
    {
      case ' ':
      break;
    
      case 'q':
      {
        cout << "Are you sure, you want to quit? ";
        cin.getline(direction,10);
        if(direction[0] == 'y')
        {
          row = -1;
          column = -1;
        }
        else
          continue;
      }
      break;

      case 'n':
      {
        if( worldCanGoNorth (world, row, column))
        {
          row--;
          worldPrintDescription(world, row, column);
        }
        else
        {
          cout << "There is no way to go in that direction" << endl;
        }
      }
      break;

      default:
        cout << "INVALID COMMAND" << endl;

    }     


    if(worldIsDeath(world, row, column))
    {
      row = -1;
      column = -1;
    }
    else if(worldIsVictory(world, row, column))
    {
      row = -1;
      column = -1;
    }
  }
  return 0;
}
