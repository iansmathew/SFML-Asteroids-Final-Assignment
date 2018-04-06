#include <iostream>
#include <SFML/Graphics.hpp>
#include "Application.h"


int main()
{
	try
	{
		Application app;
		app.run();
	}

	catch (std::exception e)
	{
		std::cout << "\n EXCEPTION: " << e.what() << std::endl;
	}
}