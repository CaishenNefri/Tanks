#pragma once
#include "SFML/Graphics.hpp"
#include "Map.h"


//To can iniclaize Player pointer
class Player;
//class Map;

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

private:
	bool processEvents();
	void update(float deltaTime);
	void render();

	sf::RenderWindow* _window = nullptr;
	//Test Resource Manager
	sf::RectangleShape m_Rect;

	Player* m_pPlayer = nullptr;
	Map map;
};

