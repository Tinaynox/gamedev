/////////////////////////////////////
// Include
#include "renderSystem.h"

#include <stdio.h>
#include <Windows.h>


/////////////////////////////////////
// Logics variables
HANDLE consoleHandle = 0;

ConsoleSymbolData backBuffer[screenRows][screenColumns];
ConsoleSymbolData screenBuffer[screenRows][screenColumns];


/////////////////////////////////////
// Functions
void RenderSystemInitialize()
{
	// Get console handle
	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );

	// Hide console cursor
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	// Initialize buffers
	for( int r = 0; r < screenRows; r++ )
	{
		for( int c = 0; c < screenColumns; c++ )
		{
			backBuffer[r][c].symbol = 0;
			backBuffer[r][c].symbolColor = ConsoleColor_Gray;
			backBuffer[r][c].backgroundColor = ConsoleColor_Black;

			screenBuffer[r][c] = backBuffer[r][c];
		}
	}
}

void RenderSystemClear()
{
	for( int r = 0; r < screenRows; r++ )
	{
		for( int c = 0; c < screenColumns; c++ )
		{
			backBuffer[r][c].symbol = 0;
			backBuffer[r][c].backgroundColor = ConsoleColor_Black;
		}
	}
}

void RenderSystemDrawChar( int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor )
{
	backBuffer[r][c].symbol = symbol;
	backBuffer[r][c].symbolColor = symbolColor;
	backBuffer[r][c].backgroundColor = backgroundColor;
}

void RenderSystemDrawText( int r, int c, const char* text, ConsoleColor symbolColor, ConsoleColor backgroundColor )
{
	int column = c;
	char symbol = *text;

	while( symbol != 0 )
	{
		RenderSystemDrawChar(r, column, symbol, symbolColor, backgroundColor);

		text++;
		column++;
		symbol = *text;
	}
}

void SetConsoleCursor( int r, int c )
{
	COORD cursorCoord;
	cursorCoord.X = c;
	cursorCoord.Y = r;
    SetConsoleCursorPosition( consoleHandle, cursorCoord );
}

void SetConsoleColor( ConsoleColor symbolColor, ConsoleColor backgroundColor )
{
	unsigned char consoleColor = symbolColor | (backgroundColor << 4);
	SetConsoleTextAttribute( consoleHandle, consoleColor );
}

void RenderSystemFlush()
{
	bool screenBufferModified = false;

	for( int r = 0; r < screenRows; r++ )
	{
		for( int c = 0; c < screenColumns; c++ )
		{
			if(    ( backBuffer[r][c].symbol			!= screenBuffer[r][c].symbol )
				|| ( backBuffer[r][c].symbolColor		!= screenBuffer[r][c].symbolColor )
				|| ( backBuffer[r][c].backgroundColor	!= screenBuffer[r][c].backgroundColor ) )
			{
				// Copy symbol data from back to screen buffer
				screenBuffer[r][c] = backBuffer[r][c];

				// Draw symbol in (r,c) position
				SetConsoleCursor( r, c );
				SetConsoleColor( screenBuffer[r][c].symbolColor, screenBuffer[r][c].backgroundColor );				
				printf("%c", screenBuffer[r][c]);

				screenBufferModified = true;
			}
		}
	}

	// Return console cursor to (0,0)
	if( screenBufferModified )
		SetConsoleCursor( 0, 0 );
}
