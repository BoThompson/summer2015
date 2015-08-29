#include <SDL.h>
#include <stdio.h>
#include "game.h"

int GameData::Setup()
{
	if(SDL_Init( SDL_INIT_EVERYTHING ) < 0)
	{
		printf("SDL Error: %s\n", SDL_GetError() );
		return -1;
	}

	if((mWindow = SDL_CreateWindow("My Summer Project Window", 100, 100, 1000, 1200, 0)) == NULL)
	{
		printf("SDL Error: %s\n", SDL_GetError() );
		return -1;
	}

	if((mScreenSurface = SDL_GetWindowSurface(mWindow)) == NULL)
	{
		printf("SDL Error: %s\n", SDL_GetError() );
		return -1;
	}

	if((mSupSurface = SDL_LoadBMP("images/sup.bmp")) == NULL)
	{
		printf("SDL Error: %s\n", SDL_GetError() );
		return -1;
	}
	return 0;
}

int GameData::Draw()
{
	SDL_BlitSurface(mSupSurface, NULL, mScreenSurface, NULL);
	SDL_UpdateWindowSurface(mWindow);
	return 0;
}

int GameData::Input()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	if(e.type == SDL_QUIT)
		mDone = true;
	return 0;
}

int GameData::Update()
{
	return 0;
}

int GameData::Run()
{
	do
	{
		Input();
		Update();
		Draw();
		SDL_Delay(10);
	}while(!mDone);
	return 0;
}


int GameData::Shutdown()
{
	SDL_FreeSurface(mSupSurface);
	SDL_DestroyWindow( mWindow );
	SDL_Quit();
	return 0;
}
