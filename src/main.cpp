#include <SFML/Graphics.hpp>  
#include <iostream>  

#include "Game.hpp"
#include "Player.hpp"
#include "Platform.hpp"


const unsigned int WINDOW_WIDTH = 1080u, WINDOW_HEIGHT = 720u;

sf::Vector2f normalOfCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2, const sf::Vector2f& velocity1);

int main()  
{  
	Game game({ WINDOW_WIDTH, WINDOW_HEIGHT }, "SFML Application");
	game.player.sprite.setPosition({ 540.0f, 0.0f });
    game.player.sprite.setScale({ 4.0f, 4.0f });

    while (game.window.isOpen())  
    {
        game.Update();
    }  
}

sf::Vector2f normalOfCollision(const sf::FloatRect& rect1, const sf::FloatRect& rect2, const sf::Vector2f& velocity1)
{
    sf::Vector2f center1 = rect1.getCenter();
	float x1 = rect2.position.x, x2 = rect2.position.x + rect2.size.x;
    float y1 = rect2.position.y, y2 = rect2.position.y + rect2.size.y;
    float tMin = 0.0f;

	sf::Vector2f invDir = velocity1.length() * sf::Vector2f({ 1.0f / velocity1.x, 1.0f / velocity1.y });
	float t1 = std::abs((x1 - center1.x) * invDir.x);
    float t2 = std::abs((x2 - center1.x) * invDir.x);
    float t3 = std::abs((y1 - center1.y) * invDir.y);
    float t4 = std::abs((y2 - center1.y) * invDir.y);

	tMin = std::min(std::min(t1, t2), std::min(t3, t4));
    if (tMin == t1)
		return sf::Vector2f(-1.0f, 0.0f); // Left
    else if (tMin == t2)
        return sf::Vector2f(1.0f, 0.0f); // Right
    if (tMin == t3)
        return sf::Vector2f(0.0f, -1.0f); // Up
    if (tMin == t4)
        return sf::Vector2f(0.0f, 1.0f); // Down
}