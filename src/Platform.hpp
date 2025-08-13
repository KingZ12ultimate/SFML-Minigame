#pragma once
#include <SFML/Graphics.hpp>

class Platform
{
public:
	sf::RectangleShape shape;
	
	Platform(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color = { 0, 128, 0 });
};

