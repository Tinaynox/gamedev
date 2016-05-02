#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	const int numberRange = 100;
	int computerNumber = 0;
	int playerNumber = 0;
	
	time_t currentTime = time(0);

	srand( currentTime );
	computerNumber = rand();
	computerNumber = computerNumber % ( numberRange + 1 );

	printf( "Computer set some number in range from %i to %i \n", 0, numberRange );

	do
	{

		printf( "Input your number: " );

		if( scanf_s("%i", &playerNumber) == 0 )
		{
			fflush(stdin);
			printf("Error!\n");
			continue;
		}

		if( playerNumber < computerNumber )
		{
			printf("Larger!\n");
		}
		else
		{
			if( playerNumber > computerNumber )
			{
				printf("Less!\n");
			}
			else
			{
				printf("Yeaah!!!\n");
			}
		}

	}
	while( playerNumber != computerNumber );


	printf("Press anykey to continue...");
	getchar();
	getchar();

}