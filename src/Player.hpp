#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f velocity = { 0.0f, 0.0f };
	sf::Vector2f collisionNormal = { 0.0f, 0.0f };
	float speed = 500.0f; // Speed in pixels per second
	float gravity = 800.0f; // Gravity in pixels per second squared
	float jumpForce = 600.0f; // Jump force in pixels per second
	float maxFallSpeed = 500.0f; // Maximum fall speed in pixels per second
	float minCos = cosf(sf::degrees(45.0f).asDegrees());
	bool grounded = false; // Whether the player is on the ground

	Player(const char* texturePath = "../resources/dog_character.png", const sf::Vector2f& position = { 0.0f, 0.0f }, const sf::Vector2f& scale = { 1.0f, 1.0f });
	~Player();

	void Update(const sf::Vector2f& movement, float deltaTime);
};
