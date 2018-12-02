#include "pch.h"
#include "TileMap.h"


TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

bool TileMap::load(const std::string & tileset, sf::Vector2f tileSize, const int * tiles, unsigned int width, unsigned int height)
{
	// load the tileset texture
	if(!m_tileset.loadFromFile(tileset))
		return false;

	sf::Vector2f begin(16, 0.f);
	sf::VertexArray pocz(sf::Points, 2);
	pocz[0].position = sf::Vector2f(begin.x * 6, begin.y);
	pocz[1].position = sf::Vector2f(begin.x, begin.y);



	sf::FloatRect BEGIN(begin, tileSize);
	
	
	m_sprite.setTexture(m_tileset);
	m_sprite.setTextureRect();
	m_sprite.setPosition(0, 0);
	m_sprite.getPosition();
	sf::Vector2f scale = m_sprite.getScale();
	m_sprite.scale(scale.x * 2, scale.y * 2);

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);


	// populate the vertex array, with one quad per title
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current title number
			int tileNumber = tiles[i + j * width];
			if (tileNumber != 1)
				tileNumber = 0;

			m_sprite.setTextureRect(pocz[tileNumber].position, tileSize);
			m_sprite.setPosition(width*tileSize.x, height * tileSize.y);
			m_sprite.draw()
			
		}



	//// resize the vertex array to fit the level size
	//m_vertices.setPrimitiveType(sf::Quads);
	//m_vertices.resize(width * height * 4);





	//// populate the vertex array, with one quad per title
	//for (unsigned int i = 0; i < width; ++i)
	//	for (unsigned int j = 0; j < height; ++j)
	//	{
	//		// get the current title number
	//		int tileNumber = tiles[i + j * width];
	//	

	//		// find its position in the tileset texture
	//		int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
	//		int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

	//		// get a pointer to the current tile's quad
	//		sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

	//		// define its 4 corners
	//		quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
	//		quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
	//		quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
	//		quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

	//		// define its 4 texture coordinates
	//		quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
	//		quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
	//		quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
	//		quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
	//	}

	return true;
}

void TileMap::draw(sf::RenderTarget & target, sf::RenderStates states) const
{




	target.draw(m_sprite, states);
	//// apply the transform
	//states.transform *= getTransform();

	//// apply the tileset texture
	//states.texture = &m_tileset;

	//// draw the vertex array
	//target.draw(m_vertices, states);
}
