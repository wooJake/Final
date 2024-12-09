#pragma once
#include <string>//rylee
#include <chrono>//Jake
#include <random>//Jake

#include <SFML/Window.hpp>//Jake

#include "Ship.h"
#include "Enemies.h"
#include "Score.h"
#include "EndScreen.h"
#include "Torpedo.h"
#include "Game.h"

class Game {

private:

	Maths maths;//Jake

	Ship ship;//Jake
	Torpedo torpedo;//Jake
	Enemies enemies;//Jake
	Health health;//Jake
	Score score = Score();//Jake
	EndScreen endscreen = EndScreen();//Jake

	std::string title;//rylee
	sf::VideoMode vm;//rylee
	sf::RenderWindow* window;//rylee

	float dt;//rylee

	sf::Clock clock;//Jake
	std::default_random_engine randEng;//Jake

	sf::Sprite background;//Jake
	sf::Image image;//Jake
	sf::Texture texture;//Jake

	float friction;//rylee

	void InitWindow();//Jake
	void InitVariables();//Jake
	void InitBackground();//Jake

	void PollEvents();//Jake
	void TimeAndSeed();//Jake

public:

	Game();//Jake
	~Game();//Jake

	void Update();//Jake
	void Render();//Jake
	void Run();//Jake
};
