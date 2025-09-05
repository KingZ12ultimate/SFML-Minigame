#include "Game.hpp"

Game::Game(const sf::Vector2u& size, const char* title, unsigned int frameRateLimit)
{
	window = sf::RenderWindow(sf::VideoMode(size), title);
	window.setFramerateLimit(frameRateLimit);
	platforms.emplace_back(sf::Vector2f(540.0f, 540.0f), sf::Vector2f(540.0f, 360.0f));
}

Game::~Game() {}

void Game::PollEvents()
{
    while (const std::optional event = window.pollEvent())
    {
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->code == sf::Keyboard::Key::Escape)
            {
                window.close();
			}
        }
        else if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
    }
}

void Game::ProcessInput()
{
	move = { 0.0f, 0.0f }; // Reset movement vector
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
    {
        move.y -= 1.0f; // Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down))
    {
        move.y += 1.0f; // Move down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
    {
        move.x -= 1.0f; // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
    {
        move.x += 1.0f; // Move right
	}
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::R))
    {
        player.sprite.setPosition({ 540.0f, 0.0f }); // Reset player position
        player.velocity = { 0.0f, 0.0f }; // Reset player velocity
		player.collisionNormal = { 0.0f, 0.0f }; // Reset collision normal
    }
}

void Game::HandleCollisions()
{
    sf::FloatRect playerBounds = player.sprite.getGlobalBounds();
    for (const Platform& p : platforms)
    {
        sf::FloatRect platformBounds = p.shape.getGlobalBounds();
        if (const std::optional collision = playerBounds.findIntersection(platformBounds))
        {
            sf::Vector2f collisionNormal = NormalOfCollision(*collision, playerBounds.position, platformBounds.position);
            player.collisionNormal = collisionNormal;

            float delta = 0.0f;
            if (collisionNormal == sf::Vector2f({ -1.0f, 0.0f }))
            {
                delta = collision->size.x;
            }
            else if (collisionNormal == sf::Vector2f({ 1.0f, 0.0f }))
            {
                delta = collision->size.x;
            }
            else if (collisionNormal == sf::Vector2f({ 0.0f, -1.0f }))
            {
                delta = collision->size.y;
            }
            else if (collisionNormal == sf::Vector2f({ 0.0f, 1.0f }))
            {
                delta = collision->size.y;
            }

            player.sprite.move(std::abs(delta) * collisionNormal);
        }
        else
        {
            player.collisionNormal = { 0.0f, 0.0f }; // Reset collision normal if no collision
        }
    }
}

void Game::Update(const sf::Vector3i& clearColor)
{
	PollEvents();
    ProcessInput();

	// player.Update(move, deltaTime);
    // HandleCollisions();

    window.clear({ clearColor.x, clearColor.y, clearColor.z });
    for (const sf::Sprite& sprite : sprites)
    {
        window.draw(sprite);
	}
    // window.draw(player.sprite);
	window.display();
}

float Game::GetDeltaTime()
{
    return clock.restart().asSeconds();
}

sf::Vector2f Game::NormalOfCollision(const sf::FloatRect& collision, const sf::Vector2f& pos1, const sf::Vector2f& pos2)
{
    if (collision.size.x < collision.size.y)
    {
        if (pos1.x < pos2.x)
            return sf::Vector2f(-1.0f, 0.0f); // Left
        else
            return sf::Vector2f(1.0f, 0.0f); // Right
    }
    else
    {
        if (pos1.y < pos2.y)
            return sf::Vector2f(0.0f, -1.0f); // Up
        else
            return sf::Vector2f(0.0f, 1.0f); // Down
    }
}
