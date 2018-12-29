//#include "pch.h"
#include "Game.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Player.h"
#include "Map.h"

Manager manager;
enum BattleGameGroup : std::size_t
{
	GTank
};


//Test Resource Manager
sf::RectangleShape m_Rect;

Player* m_pPlayer = nullptr;
Map map;



const int tiles[169] = {
	55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
	55, 55, 55, 55, 55, 55, 55, 55, 21, 55, 55, 55, 55,
	55, 55, 55, 55, 55, 55, 55, 55, 21, 55, 55, 55, 55,
	55, 55, 55, 10, 10, 10, 10, 55, 55, 55, 55, 55, 55,
	55, 55, 55, 10, 30, 30, 10, 55, 55, 55, 55, 55, 55,
	55, 55, 55, 10, 30, 30, 10, 55, 55, 55, 55, 55, 55,
	55, 55, 55, 10, 10, 10, 10, 55, 22, 55, 55, 55, 55,
	55, 55, 55, 10, 55, 55, 55, 55, 22, 55, 55, 55, 55,
	55, 55, 55, 10, 55, 55, 55, 55, 55, 55, 55, 55, 55,
	55, 55, 55, 10, 55, 55, 55, 55, 00, 55, 55, 55, 55,
	55, 55, 55, 10, 55, 55, 55, 55, 00, 55, 55, 55, 55,
	55, 55, 55, 10, 55, 55, 55, 55, 55, 55, 55, 55, 55,
	55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55
};
	
Game::Game() : _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Battle Game"))
{
	//TODO Set timer, not framelock
	//_window->setFramerateLimit(60);


	//Inicjalizacja obiektu
	m_Rect.setSize({ 64.0f,64.0f });
	m_Rect.setPosition({ 64.0f, 64.0f });

	sf::Vector2f position{ 50.f, 50.f };

	createTank(position);

	InputManager::GetInstance()->AddAction(Input::Up, sf::Keyboard::Key::Up);
	InputManager::GetInstance()->AddAction(Input::Down, sf::Keyboard::Key::Down);
	InputManager::GetInstance()->AddAction(Input::Left, sf::Keyboard::Key::Left);
	InputManager::GetInstance()->AddAction(Input::Right, sf::Keyboard::Key::Right);

	m_pPlayer = new Player();
	
	map.load(tiles, { 13, 13 }, 16, { 0,0 });
}


Game::~Game()
{
	// delete instance, remove memory leak
	delete _window;
	_window = nullptr;
	ResourceManager::GetInstance()->CleanUp();
	delete m_pPlayer;
	m_pPlayer = nullptr;
	//TODO Add other pointers
}


//Does everything below, runs one frame to the next.
void Game::run()
{
	sf::Clock clock;
	float deltaTime{  }; //TODO what the fuck?

	bool isRunning = true;
	while (isRunning)
	{
		//calculate time between frames
		deltaTime = clock.restart().asSeconds();

		//check events
		isRunning = processEvents();
		if (!isRunning) return;

		//update
		update(deltaTime);

		//draw
		render();
	}
}


// Event processing
bool Game::processEvents()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		// Request for closing the window
		switch(event.type)
		{
			case sf::Event::Closed:
				_window->close();
				return false;
				break;
		}
	}

	return true;
}

void Game::update(float deltaTime)
{
	m_pPlayer->Update(deltaTime);

	manager.refresh();
}

void Game::render()
{
	// Clear the whole window before rendering a new frame
	_window->clear();

	_window->draw(map);

	// Draw tht tank
	_window->draw(m_Rect);

	// Draw the player
	m_pPlayer->Draw(_window);	

	// NEW
	manager.draw();

	// End the current frame and display its contents on screen
	_window->display();
}

Entity& Game::createTank(sf::Vector2f& mPosition)
{
	sf::Vector2f size{ 64.f, 64.f };
	auto& entity(manager.addEntity());

	entity.addComponent<CPosition>(mPosition);
	entity.addComponent<CPhysics>();
	entity.addComponent<CRectangle>(this, size);

	entity.getComponent<CRectangle>().shape.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
	entity.getComponent<CRectangle>().shape.setTextureRect({ 0,32,16,16 });

	entity.addGroup(BattleGameGroup::GTank);

	return entity;
}

void CRectangle::draw() { game->render(shape); }

/*
// Deckare and create a new render-window
	sf::RenderWindow _window(sf::VideoMode(800, 600), "SFML window");

	// Limit the framerate to 60 frames per second.
	//TODO It will change to response on time
	_window.setFramerateLimit(60);

	// Create tank
	// Load texture for tank
	sf::Texture tankTexture;
	if (!tankTexture.loadFromFile("sprite.png"))
		return -1;

	// Assign textureTank to Sprite
	sf::Sprite tankSprite(tankTexture);

	// set tank position and size
	sf::Vector2i tank1Position(0, 0);
	sf::Vector2i tankSize(16, 16);
	sf::IntRect tank1(tank1Position, tankSize);

	// choose first tank, change rectangle of texture in sprite
	tankSprite.setTextureRect(tank1);

	// change scale of displayed tank
	sf::Vector2f tankScale(2, 2);
	tankSprite.scale(tankScale);






	// The main loop - end as suun as the window is closed
	while (_window.isOpen())
	{
		// Event processing
		sf::Event event;
		while (_window.pollEvent(event))
		{
			// Request for closing the window
			if (event.type == sf::Event::Closed)
				_window.close();
		}

		// Clear the whole window before rendering a new frame
		_window.clear();

		// Draw tht tank
		_window.draw(tankSprite);

		// End the current frame and display its contents on screen
		_window.display();
	}


*/