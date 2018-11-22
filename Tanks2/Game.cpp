#include "pch.h"
#include "Game.h"


Game::Game() 
{
	window.create(sf::VideoMode(windowHeight, windowWidth), "Battle Game");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
}


Game::~Game()
{

}

void Game::run()
{
	texture.loadFromFile("sprite.png");
	sf::IntRect rectSourceSprite(16 * 4, 16 * 3, 16, 16);
	mushroom.setTexture(texture);
	mushroom.setTextureRect(rectSourceSprite);
	sf::Vector2f scale = mushroom.getScale();
	mushroom.setScale(scale.x * 2, scale.y * 2);
	sf::Vector2u size = texture.getSize();
	mushroom.setOrigin(0, 0);


	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::buildMap()
{
	sf::Texture text;
	sf::Vector2f scale;
	text.loadFromFile("sprite.png");
	sf::IntRect rect(16 * 16, 16 * 0, 16, 16);
	sf::Sprite wall(text, rect);
	scale = wall.getScale();
	wall.setScale(scale.x * 2, scale.y * 2);
}

void Game::processEvents()
{
	////sf::Texture texture;
	//texture.loadFromFile("tank.png");

	////int d = 16;
	//sf::IntRect rectSourceSprite(0,0,16,16);
	//mushroom(texture, rectSourceSprite);

	////sf::Texture mushroomTexture;
	////mushroomTexture.loadFromFile("tank.png");
	////sf::Sprite mushroom(mushroomTexture);
	////sf::Sprite mushroom = sprite;
	//sf::Vector2f scale = mushroom.getScale();
	//mushroom.setScale(scale.x * 10, scale.y * 10);

	////sf::Vector2u size = mushroomTexture.getSize();
	//mushroom.setOrigin(size.x / 10, size.y / 10);
	//sf::Vector2f increment(0.4f, 0.4f);


	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update()
{
	sf::Vector2f position = mushroom.getPosition();
	int distance = 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sf::Vector2f move(distance, 0);
		mushroom.setPosition(position + move);
		std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		sf::Vector2f move(0, distance);
		mushroom.setPosition(position - move);
		std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		sf::Vector2f move(0, distance);
		mushroom.setPosition(position + move);
		std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sf::Vector2f move(distance, 0);
		mushroom.setPosition(position - move);
		std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
	}


}

void Game::render()
{
	window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
	window.draw(mushroom); // Drawing our sprite.
	window.display();


	/*window.clear();
	window.draw();
	window.display();*/
}
