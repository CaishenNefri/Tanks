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
	bool processEvents();
	void update(float deltaTime);
	void render();

	sf::RenderWindow* _window = nullptr;
	//sf::Texture* tankTexture = nullptr;
	//sf::Sprite *tanksprite = nullptr;

};

