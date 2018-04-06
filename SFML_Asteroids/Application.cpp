#include "Application.h"
#include "Utility.hpp"
#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "TitleState.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"
#include "PauseState.hpp"
#include "LoadingState.hpp"


//---------------------------------------------------------------------
// Initializer for application. Sets properties and starts TITLE STATE.
//---------------------------------------------------------------------
Application::Application() :
	window(sf::VideoMode(800, 600), "States", sf::Style::Close),
	textures(),
	fonts(),
	player(),
	stateStack(State::Context(window, textures, fonts, player)),
	statisticsText(),
	statisticsUpdateTime(),
	statisticsNumFrames(0)

{
	window.setKeyRepeatEnabled(false);
	fonts.load(Fonts::Main, "Media/Sansation.tff");
	textures.load(Textures::TitleScreen, "Media/Textures/TitleScreen.png");

	statisticsText.setFont(fonts.get(Fonts::Main));
	statisticsText.setPosition(5, 5);
	statisticsText.setCharacterSize(10u);

	registerStates();
	stateStack.pushState(States::Title);
}


Application::~Application()
{
}

//---------------------------------------------------------------------
// Game entry point and main update loop
//---------------------------------------------------------------------
void Application::run()
{

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	//Core loop
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		//Game loop
		while (timeSinceLastUpdate > TIME_PER_FRAME)
		{
			timeSinceLastUpdate -= TIME_PER_FRAME;
			
			processInput();
			update(TIME_PER_FRAME);

			if (stateStack.isEmpty()) //If stateMachine has no active states
			{
				window.close();
			}
		}

		updateStatistics(dt);
		render();
	}
}
