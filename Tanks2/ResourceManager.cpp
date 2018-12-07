#include "pch.h"
#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
	// tank to nazwa, ktora bedzie w m_Textures wskazywac na teksture
	LoadTexture("Resources/Sprites/git_tank1R.png", "tank");
	LoadTexture("Resources/Sprites/sprite.png", "sprite");
}

void ResourceManager::LoadTexture(std::string path, std::string name)
{
	sf::Texture* t = new sf::Texture();
	t->loadFromFile(path);

	m_Textures[name] = t;
}


void ResourceManager::CleanUp()
{
	for (auto item : m_Textures)
	{
		delete item.second;
		item.second = nullptr;
	}
}

ResourceManager::~ResourceManager()
{
}

sf::Texture * ResourceManager::RequestTexture(std::string name)
{
	if (m_Textures[name]) return m_Textures[name];

	return nullptr;
}
