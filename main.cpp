#include <SDL.h>
#include "game.h"

GameData game;

/**
 * Main function of the program
 * Param argv The number of arguments it has been started with.
 * Param args An array of the arguments it has been started with.
 * Returns 0 if successful, -1 if failed to setup
 */
int main(int argv, char *args[])
{	
	if(game.Setup() < 0)
		return -1;
	game.Run();
	game.Shutdown();
	return 0;
}