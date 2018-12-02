#include "pch.h"
#include "Game.h"


Game::Game() : _window(sf::VideoMode(WIDTH, HEIGHT), "Battle Game");
{
	//TODO Set timer, not framelock
	_window.setFramerateLimit(60);
}


Game::~Game()
{
}


//Does everything below, runs one frame to the next.
void Game::run()
{
	while (_window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}
