// Tanks2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TileMap.h"
#include "Game.h"

	
int main()
{
	// create the window
	//https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php#example-particle-system
	sf::RenderWindow window(sf::VideoMode(512, 256), "OwnTilemap");

	// define the level with an array of tile indices
	const int level[] =
	{
		0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 1, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 1, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	// create the tilemap from the level definition
	TileMap map;
	if (!map.load("sprite.png", sf::Vector2i(16, 16), level, 16, 8))
		return -1;


	// run the main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// draw the map
		window.clear();
		window.draw(map);
		window.display();
	}

	return 0;
}

//int main()
//{
//
//	Game game;
//	game.run();
//
//	return 0;
//}
