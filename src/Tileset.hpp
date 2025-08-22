#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Tileset
{
public:
	sf::Vector2u tileSize;
	std::vector<sf::Texture> tiles;

	Tileset(const char* path, const sf::Vector2u& tileSize);
};

