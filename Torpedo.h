#pragma once
#include <SFML/Graphics.hpp>//Jake

#include "Maths.h"
#include "Enemies.h"

struct Missile {//Jake

	sf::CircleShape torpedoShape;//rylee
	sf::Vector2f torpedoVel;//Jake
};
class Torpedo {

private:

	Maths maths;//Jake

	std::vector<Missile*> torpedo;//Jake

	float torpedoSpeed = 8.0f;//Jake
	float torpRadius = 2.25f;//Jake
	float torpedoAccel = 1.03f;//rylee

	float torpedoTimer = 0.0f;//rylee
	float torpedoTimerMax = 0.5f;//rylee

	void FireTorpedo(float dt, sf::CircleShape ship);//Jake
	void Accelerate();//Jake

	void OutOfBounds();//Jake
	void HitAsteroid(std::vector<Rock*>& asteroids, unsigned int& score, std::default_random_engine rand_eng);//Jake

public:

	Torpedo();//Jake
	~Torpedo();//Jake

	void Update(float dt, sf::CircleShape ship, std::vector<Rock*>& asteroids, unsigned int& score, std::default_random_engine rand_eng);//Jake
	void Render(sf::RenderWindow& target);//Jake

	std::vector<Missile*> GetTorpedo();//Jake
};
