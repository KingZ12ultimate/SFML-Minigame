#include "Tileset.hpp"

Tileset::Tileset(const char* path, const sf::Vector2u& tileSize) : tileSize(tileSize)
{
	sf::Image tilesetImage(path);
	sf::Vector2u imageSize = tilesetImage.getSize();
	for (int i = 0; i < imageSize.y; i += tileSize.y)
	{
		for (int j = 0; j < imageSize.x; j += tileSize.x)
		{
			tiles.emplace_back(tilesetImage, false, sf::IntRect({ j, i }, { static_cast<int>(tileSize.x), static_cast<int>(tileSize.y) }));
		}
	}
}
