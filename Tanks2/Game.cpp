//#include "pch.h"
#include "Game.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Player.h"
#include "Map.h"
#include "MapManager.h"
#include "Collision.h"

#include "ShootingManager.h"

Manager manager;

//Map map;
MapManager map;

auto& player(manager.addEntity());
//auto& ENEMY(manager.addEntity());

const int tiles[169] = {
	55, 55, 10, 55, 55, 55, 55, 10, 55, 55, 55, 55, 55,
	55, 00, 10, 55, 55, 55, 55, 10, 21, 55, 55, 55, 55,
	30, 00, 55, 10, 10, 55, 10, 10, 22, 55, 55, 00, 00,
	30, 55, 00, 55, 55, 55, 55, 10, 21, 55, 55, 55, 55,
	30, 55, 00, 55, 55, 55, 10, 10, 10, 10, 10, 10, 55,
	30, 10, 10, 10, 30, 55, 10, 10, 55, 55, 55, 55, 55,
	30, 55, 10, 10, 30, 55, 10, 55, 55, 10, 10, 10, 55,
	30, 55, 00, 10, 55, 55, 10, 55, 22, 55, 55, 55, 55,
	30, 55, 00, 10, 55, 55, 10, 55, 00, 55, 55, 55, 55,
	30, 55, 00, 10, 55, 55, 10, 55, 55, 55, 55, 55, 55,
	30, 55, 00, 10, 55, 55, 55, 55, 00, 55, 55, 55, 55,
	30, 55, 55, 10, 55, 10, 10, 10, 55, 55, 55, 55, 55,
	30, 55, 00, 55, 55, 10, 23, 10, 55, 55, 55, 55, 55
};

//const int tiles[169] = {
//	55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55,
//	55, 55, 55, 55, 55, 55, 55, 55, 21, 55, 55, 55, 55,
//	55, 55, 55, 55, 55, 55, 55, 55, 21, 55, 55, 55, 55,
//	55, 55, 55, 10, 10, 10, 10, 55, 55, 55, 55, 55, 55,
//	55, 55, 55, 10, 30, 30, 10, 55, 55, 55, 55, 55, 55,
//	55, 55, 55, 10, 30, 30, 10, 55, 55, 55, 55, 55, 55,
//	55, 55, 55, 10, 10, 10, 10, 55, 22, 55, 55, 55, 55,
//	55, 55, 55, 10, 55, 55, 55, 55, 22, 55, 55, 55, 55,
//	55, 55, 55, 10, 55, 55, 55, 55, 55, 55, 55, 55, 55,
//	55, 55, 55, 10, 55, 55, 55, 55, 00, 55, 55, 55, 55,
//	55, 55, 55, 10, 55, 55, 55, 55, 00, 55, 55, 55, 55,
//	55, 55, 55, 10, 55, 55, 55, 55, 55, 55, 55, 55, 55,
//	55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55
//};
	
Game::Game() : _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Battle Game"))
{
	_window->setFramerateLimit(60);

	sf::Vector2f position{ 4*64.f, 12*64.f };
	createTank2(player, position, TTank::Player1);
	position = sf::Vector2f{ 140.f, 240.f };
	createBonus(position);
	position = sf::Vector2f{ 340.f, 340.f };
	createBonus(position);
	position = sf::Vector2f{ 0.f, 0.f };
	createTank2(manager.addEntity(), position, TTank::Enemy);
	position = sf::Vector2f{ 6*64.f, 0.f };
	createTank2(manager.addEntity(), position, TTank::Enemy);
	position = sf::Vector2f{ 12*64.f, 0.f };
	createTank2(manager.addEntity(), position, TTank::Enemy);
	position = sf::Vector2f{ 5 * 64.f, 4*64.f };
	createTank2(manager.addEntity(), position, TTank::Enemy);

	InputManager::GetInstance()->AddAction(Input::Up, sf::Keyboard::Key::Up);
	InputManager::GetInstance()->AddAction(Input::Down, sf::Keyboard::Key::Down);
	InputManager::GetInstance()->AddAction(Input::Left, sf::Keyboard::Key::Left);
	InputManager::GetInstance()->AddAction(Input::Right, sf::Keyboard::Key::Right);
	InputManager::GetInstance()->AddAction(Input::Shoot, sf::Keyboard::Key::X);
	
	//map.load(tiles, { 13, 13 }, 16, { 0,0 });
	map.load(this, tiles, manager, BattleGameGroup::GTile);
}


Game::~Game()
{
	// delete instance, remove memory leak
	delete _window;
	_window = nullptr;
	ResourceManager::GetInstance()->CleanUp();
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
	auto playerPos = player.getComponent<CPosition>().position;
	auto playerVel = player.getComponent<CPhysics>().velocity;

	manager.refresh();
	manager.update(deltaTime);

	

	//Test collision with MAP
	auto& tilesEntity(manager.getEntitiesByGroup(GTile));
	for (auto& t : tilesEntity)
	{
		if (Collision::AABB(player.getComponent <CRectangle>(),
			t->getComponent<CRectangle>()) ||
			Collision::ColWindow(player.getComponent<CRectangle>()))
		{
			player.getComponent<CPosition>().position = playerPos;
		}
	}

	

	auto& bonuses(manager.getEntitiesByGroup(GBonus));
	for (auto& b : bonuses)
	{
		Collision::colissionPlayer(player, *b);
	}

	
	auto& enemies(manager.getEntitiesByGroup(BattleGameGroup::GTank));
	for (auto& e : enemies)
	{
		if ((player.getComponent<CPosition>().mapPos.x == e->getComponent<CPosition>().mapPos.x ||
			player.getComponent<CPosition>().mapPos.y == e->getComponent<CPosition>().mapPos.y) &&
			e->hasGroup(BattleGameGroup::GEnemy))
		{
			e->getComponent<CControl>().task = Task::Shoot;
		}
		if (ShootingManager::shooting((*e).getComponent<CBulet>()))
			ShootingManager::createBulet(this, manager, *e, GBullet);
	}

	auto& bullets(manager.getEntitiesByGroup(GBullet));
	for (auto& b : bullets)
	{
		auto bRect = b->getComponent<CRectangle>();
		for (auto& t : tilesEntity)
		{
			auto tRect = t->getComponent<CRectangle>();
			auto tileTag = t->getComponent<CRectangle>().TAG;
			if (!(tileTag == TWater || tileTag == TForest || tileTag == TRoad))
				if (Collision::AABB(bRect, tRect))
				{
					b->destroy();
					if (!(Collision::ColWindow(bRect)))
						t->destroy();
					break;
				}
			if ((Collision::ColWindow(bRect)))
				b->destroy();
		}

		for (auto& e : enemies)
		{
			if ((e != b->getComponent<CBulet>().whois))
			{
				auto eRect = e->getComponent<CRectangle>();
				if (Collision::AABB(bRect, eRect))
				{
					b->destroy();
					if (!(Collision::ColWindow(bRect)))
						if (e != &player)
							e->destroy();
						else
							e->getComponent<CPosition>().position = sf::Vector2f{ 4 * 64.f, 12 * 64.f };
					break;
				}
			}
		}
	}
	
}

void Game::render()
{
	// Clear the whole window before rendering a new frame
	_window->clear();

	//_window->draw(map);
	//map.load(, tiles, manager, BattleGameGroup::GTile);

	manager.draw();

	// End the current frame and display its contents on screen
	_window->display();
}

//Entity& Game::createTank(sf::Vector2f& mPosition)
//{
//	sf::Vector2f size{ 64.f, 64.f };
//	auto& entity(manager.addEntity());
//	float speed = 200.f;
//
//	entity.addComponent<CPosition>(mPosition);
//	entity.addComponent<CPhysics>();
//	entity.addComponent<CRectangle>(this, size);
//	entity.addComponent<CAnimation>(9, 2);
//	entity.addComponent<CPlayerControl>(speed);
//	
//	entity.getComponent<CRectangle>().shape.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
//	entity.getComponent<CRectangle>().shape.setTextureRect({ 0,11*16,16,16});
//	entity.addGroup(BattleGameGroup::GTank);
//
//	return entity;
//}

Entity& Game::createBonus(sf::Vector2f& mPosition)
{
	sf::Vector2f size{ 48.f, 48.f };
	auto& entity(manager.addEntity());

	entity.addComponent<CPosition>(mPosition);
	entity.addComponent<CPhysics>(size);
	entity.addComponent<CRectangle>(this);

	entity.getComponent<CRectangle>().shape.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
	entity.getComponent<CRectangle>().shape.setTextureRect({ (16*16)-1,7 * 16,16,16 });
	entity.addGroup(BattleGameGroup::GBonus);

	return entity;
}

Entity& Game::createTank2(Entity& entity, sf::Vector2f& mPosition, std::size_t mTag)
{
	sf::Vector2f size{ 55.f, 55.f };
	float speed = 200.f;

	entity.addComponent<CPosition>(mPosition);
	entity.addComponent<CPhysics>(size, speed);
	entity.addComponent<CRectangle>(this);
	entity.addComponent<CAnimation>(9, 2);
	entity.addComponent<CBulet>();
	entity.addComponent<CTank>();
	entity.addComponent<CControl>();
	if (mTag == TTank::Player1)
		entity.addComponent<CPlayerControl>();
	else
	{
		entity.addGroup(BattleGameGroup::GEnemy);
		entity.getComponent<CControl>().task = Task::Down;
	}
		
	
	

	entity.getComponent<CRectangle>().shape.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
	entity.getComponent<CRectangle>().shape.setTextureRect({ 0,11 * 16,15,15 });
	entity.addGroup(BattleGameGroup::GTank);

	return entity;
}


void Game::createBonus2(Entity& entity,sf::Vector2f& mPosition, std::string mTag)
{
	sf::Vector2f size{ 48.f, 48.f };

	entity.addComponent<CPosition>(mPosition);
	entity.addComponent<CPhysics>(size);
	entity.addComponent<CRectangle>(this);

	entity.getComponent<CRectangle>().shape.setTexture(ResourceManager::GetInstance()->RequestTexture("sprite"));
	entity.getComponent<CRectangle>().shape.setTextureRect({ (16 * 21) - 1,7 * 16,16,16 });
	entity.addGroup(BattleGameGroup::GBonus);
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






	// The main loop - end as soon as the window is closed
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