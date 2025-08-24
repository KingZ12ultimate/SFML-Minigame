#include <iostream>
#include <fstream>

#include "Game.hpp"
#include "Player.hpp"
#include "Tileset.hpp"
#include "Tilemap.hpp"

#include "LdtkJson.hpp"


const unsigned int WINDOW_WIDTH = 1280u, WINDOW_HEIGHT = 720u;

bool Load(const char* tilesetPath, const sf::Vector2u& tileSize);

int main()
{  
	std::ifstream ldtkFile("../resources/world.ldtk");
	quicktype::LdtkJson data = nlohmann::json::parse(ldtkFile);
	ldtkFile.close();

    const auto& layer = data.get_levels()[0].get_layer_instances()->at(0);
	sf::Texture tilesetTexture("../resources/" + layer.get_tileset_rel_path().get());

    /*Game game({ WINDOW_WIDTH, WINDOW_HEIGHT }, "SFML Application");
	game.player.sprite.setPosition({ 540.0f, 0.0f });
    game.player.sprite.setScale({ 4.0f, 4.0f });

	Tileset tileset("../resources/tileset.png", { 8, 8 });
    Tilemap tilemap(tileset, 10, 10, 
        {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
			0, 2, 2, 2, 2, 2, 2, 4, 2, 0,
            0, 3, 2, 0, 0, 0, 0, 2, 2, 0,
            0, 2, 2, 0, 1, 1, 0, 2, 2, 0,
            0, 2, 2, 0, 2, 3, 0, 2, 2, 0,
            0, 2, 2, 0, 0, 0, 0, 2, 2, 0,
            0, 2, 4, 1, 1, 1, 1, 2, 2, 0,
            0, 2, 2, 2, 2, 2, 2, 2, 2, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        });

	game.sprites.emplace_back(tilemap.tilemapTexture);
    sf::View view(sf::FloatRect({ 0.0f, 0.0f }, { 256.0f, 144.0f }));
	game.window.setView(view);

    while (game.window.isOpen())  
    {
        game.Update();
    }  */
}

//sf::Vector2f normalOfCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2, const sf::Vector2f& velocity1)
//{
//    sf::Vector2f center1 = rect1.getCenter();
//	float x1 = rect2.position.x, x2 = rect2.position.x + rect2.size.x;
//    float y1 = rect2.position.y, y2 = rect2.position.y + rect2.size.y;
//    float tMin = 0.0f;
//
//	sf::Vector2f invDir = velocity1.length() * sf::Vector2f({ 1.0f / velocity1.x, 1.0f / velocity1.y });
//	float t1 = std::abs((x1 - center1.x) * invDir.x);
//    float t2 = std::abs((x2 - center1.x) * invDir.x);
//    float t3 = std::abs((y1 - center1.y) * invDir.y);
//    float t4 = std::abs((y2 - center1.y) * invDir.y);
//
//	tMin = std::min(std::min(t1, t2), std::min(t3, t4));
//    if (tMin == t1)
//		return sf::Vector2f(-1.0f, 0.0f); // Left
//    else if (tMin == t2)
//        return sf::Vector2f(1.0f, 0.0f); // Right
//    if (tMin == t3)
//        return sf::Vector2f(0.0f, -1.0f); // Up
//    if (tMin == t4)
//        return sf::Vector2f(0.0f, 1.0f); // Down
//}
