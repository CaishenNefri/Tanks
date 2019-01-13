#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <map>

// Enumartion for AddAction
enum Input : unsigned int
{
	Up,
	Down,
	Left,
	Right,
	Shoot
};


//Singleton
class InputManager
{
public:
	static InputManager* GetInstance()
	{
		static InputManager instance;
		return &instance;
	}
	~InputManager();

	void AddAction(int id, sf::Keyboard::Key key);
	bool IsActionTriggered(int id);

private:
	InputManager();
	std::map<int, sf::Keyboard::Key> m_Actions;
};

