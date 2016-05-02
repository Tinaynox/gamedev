#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>


int main()
{
	// Game settings
	const int startingMoney = 500;
	const int turnCost = 50;
	const int doubleBonus = 60;
	const int tripleBonus = 100;

	// Logics variables
	int money = startingMoney;
	int bonus = 0;
	char panel0 = 'X';
	char panel1 = 'X';
	char panel2 = 'X';

	// Initialization
	srand( time( 0 ) );


	// Main loop
	do
	{
		// Render
		system("cls");
	
		printf("\n\n");
		printf("\t ######### \n");
		printf("\t# BANDITO #\n");
		printf("\t###########\n");
		printf("\t#         #\n");
		printf("\t#  %c %c %c  #\n", panel0, panel1, panel2);
		printf("\t#         #\n");
		printf("\t###########\n");
		printf("\n");

		if( bonus > 0 )
		{
			printf("\t   +%i$\n", (bonus - turnCost) );
		}
		else
		{
			printf("\n");
		}

	    printf("\n");
		printf("\tMoney: %i$\n", money);


		// Input (just for pause)
		_getch();


		// Main logics
		money = money - turnCost;

		panel0 = 3 + ( rand() % 4 );
		panel1 = 3 + ( rand() % 4 );
		panel2 = 3 + ( rand() % 4 );

		// Three out of three
		if( ( panel0 == panel1 ) && ( panel0 == panel2 ) )
		{
			bonus = tripleBonus;
		}
		else
		{
			// Two out of three
			if( ( panel0 == panel1 ) || ( panel1 == panel2 ) ||  ( panel0 == panel2 ) )
			{
				bonus = doubleBonus;
			}
			else
			{
				bonus = 0;
			}
		}

		// Give bonus to player
		money = money + bonus;
	}
	while( money >= turnCost );


	// No errors
	return 0;
}