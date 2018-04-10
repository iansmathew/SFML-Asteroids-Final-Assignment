#pragma once
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	~Game();

public:
	void run();

private:
	void update(sf::Time deltaTime);
	void render();

	void processEvents();
	void handlePlayerInput(sf::Keyboard::Key, bool);

	void updateStatistics(sf::Time deltaTime);


private:
	//Time
	static const sf::Time TimePerFrame;
	static const float PlayerSpeed;

	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	sf::Texture mTexture;
	sf::Font mFont;
	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;

	std::size_t mStatisticsNumFrames;

	//Player movement
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};

