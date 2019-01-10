#pragma once

#include <cstddef>
#include <SFML/Graphics.hpp>

class Manager;
class Entity;
class Game;

class MapManager
{
public:
	MapManager();
	~MapManager();

	void load(Game * game, const int *tiles, Manager & manager, const std::size_t group);
private:
	sf::Vector2i m_MapSize;
	sf::Vector2i m_BeginTile;
	int m_TileSize;
	int m_Scale;
	//sf::Vector2i m_BeginTile;

	Entity& createTile(Game * game, Manager & manager, sf::Vector2f & position, sf::RectangleShape tile, const std::size_t group);
};

