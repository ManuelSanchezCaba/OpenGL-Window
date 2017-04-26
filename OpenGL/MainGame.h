#pragma once

#ifndef _MainGame_
#define _MainGame_

//C++ libraries
#include <iostream>
#include <string>

//OpenGl libraries
#include <SDL/SDL.h>
#include <GL/glew.h>

namespace Game
{
	enum class GameState {PLAY, EXIT};

	class MainGame
	{
	public:
		MainGame();
		~MainGame();
		void run();
		void Render();

	private:
		void initSystems();
		void fatalError(std::string);
		void gameLoop();
		void processInput();
		SDL_Window* m_windows;
		int m_ScreenWidth;
		int m_ScreenHeight;
		GameState m_gameState;
	};
}

#endif // !_MainGame_
