#pragma once
#include <chrono>//Jake
#include <random>//Jake

#include <SFML/Graphics.hpp>//Jake
#include <SFML/System.hpp>//Jake

#include "Maths.h"

struct Rock {//rylee

	sf::CircleShape asteroidShape;//rylee
	sf::Vector2f asteroidVel;//rylee
};
class Enemies {

private:

	Maths maths;//Jake

	std::vector<Rock*> asteroids;//Jake

	unsigned int maxAsteroids;//rylee
	float astTimer;//rylee
	float astTimerMax;//rylee

	void InitAsteroids();//Jake
	void SpawnEnemies(float dt, std::default_random_engine rand_eng);//Jake
	void MoveEnemies();//Jake
	void WrapWorld();//Jake
	void HitShip(sf::CircleShape ship, float& health);//Jake

public:

	Enemies();//Jake
	~Enemies();//Jake

	void Update(float dt, std::default_random_engine rand_eng, sf::CircleShape ship, float& health);//Jake

	std::vector<Rock*>& GetEnemies();//Jake
};
