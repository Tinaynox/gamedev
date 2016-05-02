#pragma once


/////////////////////////////////////
// Include
#include <Windows.h>
#include "consoleColor.h"



/////////////////////////////////////
// Constants
const int kScreenRows = 25;
const int kScreenColumns = 80;


/////////////////////////////////////
// Struct
struct ConsoleSymbolData
{
	char symbol;
	ConsoleColor symbolColor;
	ConsoleColor backgroundColor;
};


/////////////////////////////////////
// Class RenderSystem
class RenderSystem
{
public:
	RenderSystem();

	void initialize();
	void clear();
	void drawChar( int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor );
	void drawText( int r, int c, const char* text, ConsoleColor symbolColor, ConsoleColor backgroundColor );
	void flush();

private:
	void setConsoleCursor( int r, int c );
	void setConsoleColor( ConsoleColor symbolColor, ConsoleColor backgroundColor );

private:
	HANDLE m_consoleHandle;
	ConsoleSymbolData m_backBuffer[kScreenRows][kScreenColumns];
	ConsoleSymbolData m_screenBuffer[kScreenRows][kScreenColumns];
};