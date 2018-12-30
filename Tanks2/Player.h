#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "ResourceManager.h"
#include "Animator.h"


class Player
{
public:
	Player();
	~Player();
	void Update(float elapsedSec);
	void Draw(sf::RenderWindow* pWindow); //TODO change to virtual method

private:
	sf::RectangleShape m_Body;


	Animator m_Anim;


	void HandleAnimation(float elapsedSec);
};

