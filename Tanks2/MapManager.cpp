#include "MapManager.h"
#include "ResourceManager.h"
#include "Components.h"
#include <iostream>


MapManager::MapManager() :
	m_MapSize{ 13, 13 }, m_TileSize{ 16 }, m_Scale{ 4 }, m_BeginTile{ 17, 0 }
{
}


MapManager::~MapManager()
{
}

void MapManager::load(Game * game, const int *tiles, Manager & manager, const std::size_t group)
{
	/*sf::Texture texture;
	texture.loadFromFile("Resources\Sprites\sprite.png");*/

	sf::RectangleShape tileR;
	tileR.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
	tileR.setSize({ (float)m_TileSize, (float)m_TileSize});
	sf::Vector2f scale = tileR.getScale();
	tileR.scale(scale * (float)m_Scale);

	/*sf::Sprite tile;
	tile.setTexture(texture);
	tile.scale(tile.getScale * m_Scale);*/

	sf::IntRect pos = { m_BeginTile.x * m_TileSize,
		m_BeginTile.y * m_TileSize,
		m_TileSize, m_TileSize };
	
	for (int y = 0; y < m_MapSize.y; y++)
		for (int x = 0; x < m_MapSize.x; x++)
		{
			int act = x + m_MapSize.y * y;
			if (tiles[act] != 55)
			{
				pos.left = tiles[act] % 10;
				pos.left += m_TileSize;
				pos.left *= m_TileSize;
				pos.left--;
				pos.top = tiles[act] / 10;
				pos.top *= m_TileSize;
				tileR.setTextureRect(pos);

				sf::Vector2i positionI{ m_TileSize * m_Scale * x, m_TileSize * m_Scale * y };
				sf::Vector2f position{ (float)positionI.x, (float)positionI.y };
				tileR.setPosition(position);

				createTile(game, manager, position, tileR, group);
			}
		}
}

Entity & MapManager::createTile(Game * game, Manager & manager, sf::Vector2f & position, sf::RectangleShape tile, const std::size_t group)
{
	auto& entity(manager.addEntity());
	
	entity.addComponent<CPosition>(position);
	entity.addComponent<CPhysics>();
	entity.addComponent<CRectangle>(game, tile.getSize());
	
	entity.getComponent<CRectangle>().shape = tile;
	entity.addGroup(group);


	return entity;
}

//Entity & MapManager::createTile(sf::RenderWindow *window, Manager & manager, sf::Vector2f & position, sf::RectangleShape tile, const std::size_t group)
//{
//	auto& entity(manager.addEntity());
//	
//	entity.addComponent<CPosition>(position);
//	entity.addComponent<CPhysics>();
//	entity.addComponent<CRectangle>(window);
//	
//	entity.getComponent<CRectangle>().shape = tile;
//	entity.addGroup(group);
//
//
//	return entity;
//}
