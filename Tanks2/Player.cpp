#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "ResourceManager.h"


Player::Player()
{
	m_Body.setSize({ 64.0f, 64.0f });
	m_Body.setPosition(0, 0);
	m_Body.setTexture(ResourceManager::GetInstance()->RequestTexture("tank"));
}


Player::~Player()
{
}

void Player::Update(float elapsedSec)
{
	// Inicialized loccaly for not typing a lot
	auto input = InputManager::GetInstance();
	auto pos = m_Body.getPosition();

	sf::Vector2<float> velocity;
	float speed = 200.0f;

	// Sprawdza czy nacisniete klawicze i odpowiednio nadaje kierunek poruszania siê	
	if (input->IsActionTriggered(Input::Up))
	{
		velocity.y = -speed;
	}
	if (input->IsActionTriggered(Input::Down))
	{
		velocity.y = speed;
	}
	if (input->IsActionTriggered(Input::Left))
	{
		velocity.x = -speed;
	}
	if (input->IsActionTriggered(Input::Right))
	{
		velocity.x = speed;
	}

	pos += velocity * elapsedSec;

	m_Body.setPosition(pos);
}

void Player::Draw(sf::RenderWindow* pWindow)
{
	pWindow->draw(m_Body);
}
