#include <Windows.h>
#include "MainGame.h"

int main(int argc, char** argv)
{
	Game::MainGame mainGame;
	mainGame.run();

	SDL_Init(SDL_INIT_EVERYTHING);
	return 0;
}
