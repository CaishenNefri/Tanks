#pragma once
#include <ctime>

class CBulet;
class Manager;
class Entity;
class Game;

class ShootingManager
{
public:
	ShootingManager();
	~ShootingManager();


	static bool shooting(CBulet& cBulet);
	static bool isShooting(CBulet& cBulet);


	static Entity& createBulet(Game * game, Manager & manager, Entity & tank, std::size_t group);
private:
	static const std::clock_t delayTime = 500;

	
};

