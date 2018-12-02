#pragma once
#include "SFML/Graphics.hpp"

// Size of window
// TODO Move to setting.cfg
#define WIDTH 800
#define HEIGHT 600

class Game
{
public:
	Game();
	~Game();
	
	void run();

private:
	void processEvents();
	void update();
	void render();

	sf::RenderWindow _window;
};

