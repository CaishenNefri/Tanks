#include "pch.h"
#include "Map.h"
#include "ResourceManager.h"
#include <iostream>


Map::Map()
{
}

void Map::load(const int *tiles, sf::Vector2u mapSize, unsigned int tileSize, sf::Vector2i beginTile)
{
	//m_tileset.swap(ResourceManager::GetInstance()->RequestTexture("sprite"));
	m_tileset.loadFromFile("Resources/Sprites/sprite.png");

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(mapSize.x * mapSize.y * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int y = 0; y < mapSize.y; y++)
	{
		for (unsigned int x = 0; x < mapSize.x; x++)
		{
			int act = x + y * mapSize.y;
			// get the current tile number
			int tileNumber = tiles[act];

			// find its postion in the tileset texture
			//TODO: explain
			sf::Vector2u pos;
			pos.x = tileNumber % 10;
			pos.x += tileSize;
			pos.x *= tileSize;
			pos.y = tileNumber / 10;
			pos.y *= tileSize;

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[act * 4];

			// defines its 4 corners
			quad[0].position = sf::Vector2f(x * 4 * tileSize, y * 4 * tileSize);
			quad[1].position = sf::Vector2f(x * 1 * 4 * tileSize + tileSize * 4, y * 4 * tileSize);
			quad[2].position = sf::Vector2f(x * 1 * 4 * tileSize + tileSize * 4, y * 1 * 4 * tileSize + tileSize * 4);
			quad[3].position = sf::Vector2f(x * 1 * 4 * tileSize, y * 1 * 4 * tileSize + tileSize * 4);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(pos.x, pos.y);
			quad[1].texCoords = sf::Vector2f(pos.x + tileSize, pos.y);
			quad[2].texCoords = sf::Vector2f(pos.x + tileSize, pos.y + tileSize);
			quad[3].texCoords = sf::Vector2f(pos.x, pos.y + tileSize);
		}
	}
}

//void Map::load(const int *tiles, sf::Vector2i mapSize, unsigned int tileSize, sf::Vector2i beginTile)
//{
//	unsigned int scale = 2;
//	sf::RectangleShape tile;
//	tile.setSize({ scale, 64.0f });
//	tile.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
//	sf::IntRect pos = { 17 * 16, 0, 16,16 };
//
//	
//	for (int y = 0; y < size.y; y++) 
//	{
//		for (int x = 0; x < size.x; x++)
//		{
//			int act = 13 * y + x;
//			pos.left = tiles[act] % 10;
//			pos.left += 16;
//			pos.left *= 16;
//			pos.top = tiles[act] / 10;
//			pos.top *= 16;
//			tile.setTextureRect(pos);
//			tile.setPosition({ 64.f * x, 64.f * y });
//			window->draw(tile);
//			std::cout << tiles[act];
//		}
//		std::cout << std::endl;
//	}	
//}


Map::~Map()
{
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}
