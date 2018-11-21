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
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
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
		if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
		{
			window.close();
		}

		sf::Vector2f position = mushroom.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sf::Vector2f move(1, 0);
			mushroom.setPosition(position + move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sf::Vector2f move(0, 1);
			mushroom.setPosition(position - move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sf::Vector2f move(0, 1);
			mushroom.setPosition(position + move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sf::Vector2f move(1, 0);
			mushroom.setPosition(position - move);
			std::cout << "Przycisk Prawa strzalka nacisniety!" << std::endl;
		}

	}
}

void Game::update()
{
}

void Game::render()
{
	
	texture.loadFromFile("tank.png");
	sf::IntRect rectSourceSprite(0, 0, 16, 16);
	mushroom.setTexture(texture);
	mushroom.setTextureRect(rectSourceSprite);
	sf::Vector2f scale = mushroom.getScale();
	mushroom.setScale(scale.x * 20, scale.y * 20);
	sf::Vector2u size = texture.getSize();
	//mushroom.setOrigin(size.x / 10, size.y / 10);


	window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
	window.draw(mushroom); // Drawing our sprite.
	window.display();


	/*window.clear();
	window.draw();
	window.display();*/
}
