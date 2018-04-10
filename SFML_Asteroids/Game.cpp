#include <iostream>
#include "Game.h"
#include "StringHelpers.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
const float Game::PlayerSpeed = 100.f;

Game::Game() 
	: mWindow(sf::VideoMode(640, 480), "SFML Application", sf::Style::Close)
	, mTexture()
	, mPlayer()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
{

	try 
	{
		!mTexture.loadFromFile("../Media/Textures/Eagle.png");
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
	
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.0f, 100.0f);

	mFont.loadFromFile("../Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}


Game::~Game()
{
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement (0.0f, 0.0f);
	if (mIsMovingUp)
		movement.y  -= PlayerSpeed;
	if (mIsMovingDown)
		movement.y += PlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= PlayerSpeed;
	if (mIsMovingRight)
		movement.x += PlayerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::processEvents()
{
	sf::Event e;
	while (mWindow.pollEvent(e))
	{
		switch (e.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(e.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(e.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key _key, bool _isPressed)
{
	if (_key == sf::Keyboard::W)
		mIsMovingUp = _isPressed;
	else if (_key == sf::Keyboard::S)
		mIsMovingDown = _isPressed;
	else if (_key == sf::Keyboard::A)
		mIsMovingLeft = _isPressed;
	else if (_key == sf::Keyboard::D)
		mIsMovingRight = _isPressed;
}

void Game::updateStatistics(sf::Time deltaTime)
{
	mStatisticsUpdateTime += deltaTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}
}


