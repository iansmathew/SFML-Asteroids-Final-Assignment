#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

class Application
{
public:
	Application();
	~Application();

public:

private:
	static const sf::Time TIME_PER_FRAME;
	unsigned int statisticsNumFrames;
	sf::Text statisticsText;
	sf::Time statisticsUpdateTime;

	sf::RenderWindow window;
	TextureHolder textures;
	FontHolder fonts;

	StateStack stateStack;

	Player player;


public:
	void run();

private:
	void processInput();
	void update(sf::Time dt);
	void render();

	void updateStatistics(sf::Time dt);
	void registerStates();






};

