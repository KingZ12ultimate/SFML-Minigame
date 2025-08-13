#include "Platform.hpp"

Platform::Platform(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color)
{
	shape.setPosition(position);
	shape.setSize(size);
	shape.setFillColor(color);
	shape.setOrigin(size / 2.0f); // Set origin to center of the platform
}