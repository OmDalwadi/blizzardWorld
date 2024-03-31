#pragma once
#include <string>
using namespace std;

const int ROW_COUNT = 6, COLUMN_COUNT = 9;
typedef unsigned int NodeValue;

NodeValue const INACCESSIBLE = 0;
NodeValue const START_MESSAGE = 1;
NodeValue const END_MESSAGE = 2;
NodeValue const DEATH_NODE = 3;
NodeValue const START_NODE = 4;
NodeValue const VICTORY_NODE = 5;
NodeValue const DESCRIPTION_COUNT = 26;

typedef NodeValue World[ROW_COUNT][COLUMN_COUNT];

void worldClear (World world);
void worldLoadAll (World world, string game_name);
void worldLoadNodes (World world, string filename);
void worldLoadDescriptions (World world, string filename);
void worldDebugPrint (const World world);
bool worldIsValid (const World world, int row, int column);
bool worldCanGoNorth (const World world, int row, int column);
bool worldCanGoSouth (const World world, int row, int column);
bool worldCanGoEast  (const World world, int row, int column);
bool worldCanGoWest  (const World world, int row, int column);
bool worldIsDeath   (const World world, int row, int column);
bool worldIsVictory (const World world, int row, int column);
void worldFindValue (const World world, int& row, int& column, NodeValue value_to_find);
void worldPrintDescription (const World world, int row, int column);
void worldPrintStartMessage (const World world);
void worldPrintEndMessage (const World world);