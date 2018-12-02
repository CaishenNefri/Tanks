#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
class ResourceManager
{
public:
	//https://pl.wikipedia.org/wiki/Singleton_(wzorzec_projektowy)
	//Singleton
	static ResourceManager* GetInstance()
	{
		static ResourceManager instance;
		return &instance;
	}
	void CleanUp();
	~ResourceManager();
	sf::Texture* RequestTexture(std::string name);
private:
	ResourceManager();
	void LoadTexture(std::string path, std::string name);

	
	std::map<std::string, sf::Texture*> m_Textures;
};

