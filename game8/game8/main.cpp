/////////////////////////////////////
// Include
#include "game.h"
#include <stdio.h>


/////////////////////////////////////
// Main
int main()
{
	Game game;

	game.setupSystem();
	game.initialize();

	while( game.loop() );

	game.shutdown();

	return 0;
}