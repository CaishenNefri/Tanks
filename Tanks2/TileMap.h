#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	TileMap();
	~TileMap();

	bool load(const std::string& tileset, sf::Vector2f tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices;
    sf::Texture m_tileset;
	sf::Sprite m_sprite;
};

