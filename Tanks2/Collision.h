#pragma once
#include "SFML/Graphics.hpp"

class Entity;

class CRectangle;

class Collision
{
public:
	static void colissionPlayer(Entity& a, Entity& b);
	static bool AABB(const CRectangle& colA, const CRectangle& colB);
	
	static sf::FloatRect windowRect;
};