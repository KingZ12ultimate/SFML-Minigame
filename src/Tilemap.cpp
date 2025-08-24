#include "Tilemap.hpp"

Tilemap::Tilemap(Tileset& tileset, int rows, int columns, const std::vector<unsigned int>& map)
	: tileset(tileset), mapData(map), rows(rows), columns(columns), tilemapTexture(sf::Vector2u(rows * tileset.tileSize.x, columns * tileset.tileSize.y))
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			tilemapTexture.update(tileset.tiles[map[i * rows + j]], sf::Vector2u(j * tileset.tileSize.x, i * tileset.tileSize.y));
		}
	}
}
