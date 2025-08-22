#pragma once
#include <vector>
#include "Tileset.hpp"

class Tilemap
{
public:
	Tileset& tileset;
	sf::Texture tilemapTexture;

	// Constructor to create a tilemap from a tileset and a map containing tile indices
	Tilemap(Tileset& tileset, int rows, int columns, const std::vector<unsigned int>& map);

private:
	int rows, columns;
	std::vector<unsigned int> mapData;
};
