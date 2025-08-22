#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Platform.hpp"

class Game
{
public:
	sf::RenderWindow window;
	sf::Clock clock;
	sf::Vector2f move = { 0.0f, 0.0f }; // Movement vector for player input
	Player player; // Player instance
	std::vector<Platform> platforms; // Vector of platforms in the game
	std::vector<sf::Sprite> sprites; // Vector of sprites for rendering

	// Constructor that initializes the window with a given size, title, and frame rate limit.
	Game(const sf::Vector2u& size, const char* title, unsigned int frameRateLimit = 144u);
	~Game();

	// Updates the game state, including player movement and other game logic.
	void Update();

	static sf::Vector2f NormalOfCollision(const sf::FloatRect& collision, const sf::Vector2f& pos1, const sf::Vector2f& pos2);
private:
	// Polls events from the window and handles them.
	void PollEvents();

	// Processes input from the user, such as keyboard and mouse events.
	void ProcessInput();

	// Handles collisions between game objects, such as the player and platforms.
	void HandleCollisions();

	// Returns the current time since the last frame in seconds.
	float GetDeltaTime();
	__declspec(property(get = GetDeltaTime)) float deltaTime;
};

