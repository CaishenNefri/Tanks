#pragma once
#include "Components.h"
#include "SFML/Graphics.hpp"

// Size of window
// TODO Move to setting.cfg
#define WIDTH 832
#define HEIGHT 832

class Game
{
public:
	Game();
	~Game();
	void run();
	void render(const sf::Drawable& mDrawable) { _window->draw(mDrawable); }

	enum BattleGameGroup : std::size_t
	{
		GTank,
		GEnemy,
		GBonus,
		GTile,
		GBullet
	};

private:
	bool processEvents();
	void update(float deltaTime);
	void render();

	sf::RenderWindow* _window = nullptr;

	// Factories
	/*Entity& createTank(sf::Vector2f& mPosition);*/
	Entity& createBonus(sf::Vector2f& mPosition);

	Entity& createTank2(Entity& entity, sf::Vector2f& mPosition, std::size_t mTag);
	void createBonus2(Entity& entity, sf::Vector2f& mPosition, std::string mTag);
};