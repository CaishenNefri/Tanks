#pragma once
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable
{
public:
	Map();

	void load(const int *tiles, sf::Vector2u mapSize, unsigned int tileSize, sf::Vector2i beginTile);

		
	~Map();


private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
};

