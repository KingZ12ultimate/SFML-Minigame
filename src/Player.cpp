#include "Player.hpp"

Player::Player(const char* texturePath, const sf::Vector2f& position, const sf::Vector2f& scale) : texture(texturePath), sprite(texture)
{
	sprite.setPosition(position);
	sprite.setScale(scale);
	sprite.setOrigin({ texture.getSize().x / 2.0f, texture.getSize().y / 2.0f }); // Set origin to center of the sprite
}

Player::~Player()
{
}

void Player::Update(const sf::Vector2f& movement, float deltaTime)
{
	velocity.x = speed * movement.x;
	velocity.y += gravity * deltaTime; // Apply gravity to the vertical velocity
	grounded = minCos <= -collisionNormal.y; // Check if the player is grounded based on the collision normal
	if (grounded && sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Space))
	{
		velocity.y = -jumpForce; // Apply jump force if grounded and space is pressed
		grounded = false; // Reset grounded state after jumping
	}
	velocity.y = std::min(velocity.y, maxFallSpeed); // Cap the fall speed
	sprite.move(velocity * deltaTime);
}
