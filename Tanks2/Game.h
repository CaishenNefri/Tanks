#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"

// Size of window
// TODO Move to setting.cfg
#define WIDTH 832
#define HEIGHT 664

class Game
{
public:
	Game();
	~Game();
	void run();
	void render(const sf::Drawable& mDrawable) { _window->draw(mDrawable); }

private:
	bool processEvents();
	void update(float deltaTime);
	void render();

	sf::RenderWindow* _window = nullptr;

	// Factories
	Entity& createTank(sf::Vector2f& mPosition);
};