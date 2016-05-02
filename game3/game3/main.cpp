#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>


int main()
{
	// Game settings
	const int lettersCount = 20;


	// Logics variables
	char letters[ lettersCount ];
	int step = 0;
	int errors = 0;
	char inputChar = 0;


	// System setup
	time_t currentTime;
	time( &currentTime );

	srand( currentTime );


	// Main loop
	do
	{
		// Initialization
		step = 0;
		errors = 0;
		

		for( int i = 0; i < lettersCount; i++ )
		{
			letters[i] = 'a' + rand() % ( ('z' - 'a') + 1 );
		}


		// Part I - "Prologue"
		system("cls");

		printf("\n\tReady?\n");

		// Input (just for pause)
		_getch();


		// Print 5 points for simple animation
		printf("\t");
		for( int i = 0; i < 5; ++i )
		{
			printf(".");
			Sleep(175);
		}


		printf("\n\tGo!");
		Sleep(350);


		// Record start time 
		time_t startTime = time(0);


		// Part II - "Main loop"
		do
		{
			// Render
			system("cls"); 

			printf("\n\t");
			for( int i = 0; i < lettersCount; i++ )
			{
				if( i < step )
				{
					printf("%c ", 176);
				}
				else
				{
					printf("%c ", toupper( letters[i] ) );
				}
			}

			// Input
			inputChar = _getch();


			// Main logics
			if( tolower( inputChar ) == letters[step] )
			{
				step++;
			}
			else
			{
				errors++;
			}

		}
		while( step < lettersCount );


		// Record end time 
		time_t endTime = time(0);
		time_t timePassed = endTime - startTime;
		float symbolsPerMinute = 60.0f * ( float(lettersCount) / float(timePassed) );


		// Part III - "Epilogue"
		system("cls");
	
		printf("\n\tYour result:\n");
		printf("\t%d symbols for %d seconds\n", lettersCount, timePassed);
		printf("\tSymbols per minute: %.1f\n", symbolsPerMinute);
		printf("\tErrors: %i\n", errors);


		// Ask about continue
		printf("\n\tAgain? (y/n): ");

		// Input answer char
		inputChar = _getch();

	}
	while( tolower( inputChar ) != 'n' );
	

	// No errors
	return 0;
}