#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

#include "State.hpp"
#include "StateIdentifiers.hpp"
#include "ResourceIdentifiers.hpp"

#include <vector>
#include <utility>
#include <functional>
#include <map>

namespace sf
{
	class Event;
	class RenderWindow;
}

class StateStack : private sf::NonCopyable
{
public:
	StateStack();
	~StateStack();

public:
	enum ACTION
	{
		Push,
		Pop,
		Clear
	};
};

