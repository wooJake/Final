#pragma once
#include <SFML/Graphics.hpp>//Jake
#include <SFML/System.hpp>//Jake

#include "Maths.h"

class EndScreen {

private:

	Maths maths;

	sf::Font font;//Jake

	sf::Text endText;//Jake

	void InitFont();
	void InitEndText();

public:

	EndScreen();
	~EndScreen();

	sf::Text GetEndText();
};
