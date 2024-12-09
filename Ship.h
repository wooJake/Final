#pragma once
#include "Maths.h"
#include "Health.h"

#include <SFML/Graphics.hpp>//Jake
#include <SFML/System.hpp>//Jake

class Ship {

private:

	Maths maths;//Jake
	Health health;//Jake

	sf::CircleShape ship;//rylee

	float shipRadius = 27.0f;//Jake
	sf::Vector2f shipVel = sf::Vector2f(0.0f, 0.0f);//rylee
	float shipAccel = 1.03f;//rylee
	float shipRotAccel = 3.00f;//Jake

	void InitShip();//Jake

	void MoveShip(float friction);//Jake
	void WrapWorld();//Jake

public:

	Ship();//Jake
	~Ship();//Jake

	void Update(float friction);//Jake
	void Render(sf::RenderWindow& target);//Jake

	sf::CircleShape GetShip();//Jake
};
