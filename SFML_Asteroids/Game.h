#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

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
	TextureHolder mTextureHolder;
	FontHolder mfontHolder;
	sf::Sprite mPlayer;

	sf::Text mStatisticsText;
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames;

	//Player movement
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
};

