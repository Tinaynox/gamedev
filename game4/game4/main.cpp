/////////////////////////////////////
// Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>


/////////////////////////////////////
// Game settings
const int rowsCount = 10;
const int columnsCount = 15;

const unsigned char symbolHero = 2;
const unsigned char symbolWall = 177;
const unsigned char symbolBox = 254;
const unsigned char symbolExit = 176;

const int levelsCount = 3;
const unsigned char levelsData[levelsCount][rowsCount][columnsCount + 1] =	{
																				{
																					"#####2#########",
																					"#  X   #   X ##",
																					"# X ### X  #  #",
																					"#X X  X  ## X #",
																					"# X    ##  #  #",
																					"#######    # X#",
																					"#   X   XX #X #",
																					"#XXX # # X   ##",
																					"#1 X #   X X  #",
																					"###############",
																				},
																				{
																					"#####2#########",
																					"#             #",
																					"#  XXXX       #",
																					"#     X       #",
																					"#    X        #",
																					"#   X         #",
																					"#  XXXX       #",
																					"#         1   #",
																					"#             #",
																					"###############",
																				},
																				{
																					"#####2#########",
																					"#             #",
																					"#  XXXX       #",
																					"#     X       #",
																					"#    X        #",
																					"#     X       #",
																					"#  XXXX       #",
																					"#         1   #",
																					"#             #",
																					"###############",
																				}
																			};


/////////////////////////////////////
// Logics variables
HANDLE consoleHandle = 0;
bool isGameActive = true;
unsigned char levelData[rowsCount][columnsCount];
int heroRow = 0;
int heroColumn = 0;


/////////////////////////////////////
// Functions
void SetupSystem()
{
	srand( time( 0 ) );

	consoleHandle = GetStdHandle( STD_OUTPUT_HANDLE );
}

void Initialise()
{
	int level = 2;

	// Load level
	for( int r = 0; r < rowsCount; r++ )
	{
		for( int c = 0; c < columnsCount; c++ )
		{
			unsigned char symbol = levelsData[level][r][c];
			switch( symbol )
			{
				// Wall
				case '#':
				{
					levelData[r][c] = symbolWall;
					break;
				}

				// Hero
				case '1':
				{
					levelData[r][c] = symbolHero;

					// Catch hero position
					heroRow = r;
					heroColumn = c;
					break;
				}

				// Exit
				case '2':
				{
					levelData[r][c] = symbolExit;
					break;
				}

				// Box
				case 'X':
				{
					levelData[r][c] = symbolBox;
					break;
				}

				// Other symbols (like spaces)
				default:
				{
					levelData[r][c] = symbol;
					break;
				}
			}
		}
	}
}

void Render()
{
	// Move console cursor to (0,0)
	COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 0;
    SetConsoleCursorPosition( consoleHandle, cursorCoord );


	printf("\n\n\t");
	for( int r = 0; r < rowsCount; r++ )
	{
		for( int c = 0; c < columnsCount; c++ )
		{
			unsigned char symbol = levelData[r][c];

			switch( symbol )
			{
				// Walls - white
				case symbolWall:
				{
					SetConsoleTextAttribute( consoleHandle, 15 ); 
					break;
				}
				// Hero - green
				case symbolHero:
				{
					SetConsoleTextAttribute( consoleHandle, 10 ); 
					break;
				}
				// Boxes - yellow
				case symbolBox:
				{
					SetConsoleTextAttribute( consoleHandle, 14 ); 
					break;
				}
				// Exit - red
				case symbolExit:
				{
					SetConsoleTextAttribute( consoleHandle, 12 ); 
					break;
				}
			}

			printf("%c", symbol );
		}
		printf("\n\t");
	}


	SetConsoleTextAttribute( consoleHandle, 7 ); 
	printf("\n\n\tUse AWSD to move ");
	SetConsoleTextAttribute( consoleHandle, 10 ); 
	printf("Hero");
	SetConsoleTextAttribute( consoleHandle, 7 ); 
	printf(". R - Restart level.");
}

void MoveHeroTo( int row, int column )
{
	unsigned char destinationCell = levelData[row][column];
	bool canMoveToCell = false;


	switch( destinationCell )
	{
		// Empty cell
		case ' ':
		{
			canMoveToCell = true;
			break;
		}

		// Exit cell
		case symbolExit:
		{
			isGameActive = false;
			break;
		}

		// Box
		case symbolBox:
		{
			// Calculate hero move direction
			int heroDirectionR = row - heroRow;
			int heroDirectionC = column - heroColumn;

			// Check for empty space behind the box
			if( levelData[row + heroDirectionR][column + heroDirectionC] == ' ' )
			{
				canMoveToCell = true;

				// Remove box symbol from previous position
				levelData[row][column] = ' ';

				// Set box symbol to new position
				levelData[row + heroDirectionR][column + heroDirectionC] = symbolBox;
			}

			break;
		}
	}


	if( canMoveToCell )
	{
		// Remove hero symbol from previous position
		levelData[heroRow][heroColumn] = ' ';

		// Set new hero position
		heroRow = row;
		heroColumn = column;

		// Set hero symbol to new position
		levelData[heroRow][heroColumn] = symbolHero;
	}
}

void Update()
{
	unsigned char inputChar = _getch();
	inputChar = tolower( inputChar );

	switch( inputChar )
	{
		// Up
		case 'w':
		{
			MoveHeroTo( heroRow - 1, heroColumn );
			break;
		}

		// Down
		case 's':
		{
			MoveHeroTo( heroRow + 1, heroColumn );
			break;
		}

		// Left
		case 'a':
		{
			MoveHeroTo( heroRow, heroColumn - 1 );
			break;
		}

		// Right
		case 'd':
		{
			MoveHeroTo( heroRow, heroColumn + 1 );
			break;
		}

		// Restart level
		case 'r':
		{
			Initialise();
			break;
		}
	}
}

void Shutdown()
{
	system("cls");
	printf("\n\tPress any key to continue...");
	_getch();
}



int main()
{
	SetupSystem();
	Initialise();

	do
	{
		Render();
		Update();
	}
	while( isGameActive );

	Shutdown();

	return 0;
}