#pragma once

#include <cstddef>
#include <SFML/Graphics.hpp>

class Manager;
class Entity;
class Game;

enum tileType : std::size_t
{
	TBrick,
	TSteel,
	TWater,
	TForest,
	TRoad,
	TNull
};

class MapManager
{
public:
	MapManager();
	~MapManager();

	int** load(Game * game, const int *tiles, Manager & manager, const std::size_t group);
private:
	sf::Vector2i m_MapSize;
	sf::Vector2i m_BeginTile;
	int m_TileSize;
	int m_Scale;
	//sf::Vector2i m_BeginTile;

	std::size_t selectTagTile(const int type);
	Entity& createTile(Game * game, Manager & manager, sf::Vector2f & position, sf::RectangleShape tile, const std::size_t group, std::size_t tagTile);
};

