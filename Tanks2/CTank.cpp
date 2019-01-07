#include "CTank.h"

void CTank::upgrade(void)
{
	sf::IntRect rect = cRectangle->shape.getTextureRect();
	rect.top += 16;
	cRectangle->shape.setTextureRect(rect);
}