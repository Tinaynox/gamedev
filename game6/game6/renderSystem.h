#pragma once


/////////////////////////////////////
// Include
#include "consoleColor.h"


/////////////////////////////////////
// Constants
const int screenRows = 25;
const int screenColumns = 80;


/////////////////////////////////////
// Struct
struct ConsoleSymbolData
{
	char symbol;
	ConsoleColor symbolColor;
	ConsoleColor backgroundColor;
};


/////////////////////////////////////
// Functions
void RenderSystemInitialize();
void RenderSystemClear();
void RenderSystemDrawChar( int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor );
void RenderSystemDrawText( int r, int c, const char* text, ConsoleColor symbolColor, ConsoleColor backgroundColor );
void RenderSystemFlush();

