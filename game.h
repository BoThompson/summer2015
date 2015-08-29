#ifndef __GAME_H
#define __GAME_H

/**
 * The game's driver class
 */
class GameData
{
	int mGameState;		/**< The state of the game */
	bool mChanged;		/**< Has the screen changed */
	bool mDone;			/**< Has the game ended */
	SDL_Window * mWindow; /**< The window for drawing the game */
	SDL_Surface *mScreenSurface; /**< The surface of the game's window */
	SDL_Surface *mSupSurface; /**< The surface for the art */
	//Private methods
	int Input();
	int Update();
	int Draw();
public:
	
	//Public methods
    int Setup();
	int Run();
	int Shutdown();
};

extern GameData game;

#endif //__GAME_H