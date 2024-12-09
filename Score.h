#pragma once
#include <sstream>//Jake

#include <SFML/Graphics.hpp>//Jake
#include <SFML/System.hpp>//Jake

#include "Maths.h"

class Score {

private:

	Maths maths;//Jake

	unsigned int score;//Jake

	sf::Font font;//Jake

	sf::Text scoreText;//Jake

	void InitFont();//Jake
	void InitText();//Jake
	void StreamText();//Jake

public:

	Score();//Jake
	~Score();//Jake

	void Update();//Jake
	sf::Text GetScoreText();//Jake
	unsigned int& GetScore();//Jake
};
