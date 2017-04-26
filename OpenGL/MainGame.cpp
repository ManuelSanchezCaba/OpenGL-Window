#include "MainGame.h"

namespace Game
{
	MainGame::MainGame()
		: m_ScreenWidth(1024)
		, m_ScreenHeight(568)
	{
		m_windows = nullptr;
		m_gameState = GameState::PLAY;
	}


	MainGame::~MainGame()
	{
	}

	void MainGame::run()
	{
		initSystems();
		gameLoop();
	}

	void MainGame::initSystems()
	{
		//initialize SDL
		SDL_Init(SDL_INIT_EVERYTHING);

		m_windows = SDL_CreateWindow("Game engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_OPENGL);

		if (m_windows == nullptr)
		{
			fatalError("SDL Window could not be created! ");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(m_windows);
		if (glContext == nullptr)
		{
			fatalError("SDL GL context could not be created! ");
		}

		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			fatalError("could not initialize glew! ");
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	}

	void MainGame::fatalError(std::string errorString)
	{
		std::cout << errorString << std::endl;
		std::cout << "Enter any key to quit..." << std::endl;
		int tmp;
		std::cin >> tmp;

		exit(1);
		SDL_Quit();
	}

	void MainGame::gameLoop()
	{
		while (m_gameState != GameState::EXIT)
		{
			processInput();
			Render();
		}
	}

	void MainGame::processInput()
	{
		SDL_Event evnt;

		while (SDL_PollEvent(&evnt))
		{
			switch (evnt.type)
			{
			case SDL_QUIT:
				m_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
			default:
				break;
			}
		}
		
	}

	void MainGame::Render()
	{
		glClearDepth(1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnableClientState(GL_COLOR_ARRAY);

		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(-3.0f, 5.0f);
		glVertex2f(3.0f, 5.0f);
		glEnd();

		SDL_GL_SwapWindow(m_windows);
	}
}