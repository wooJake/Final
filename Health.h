#pragma once
#include <SFML/Graphics.hpp>//Jake
#include <SFML/System.hpp>//Jake

#include "Maths.h"

class Health {

private:

	Maths maths;//Jake

	sf::RectangleShape healthForeground;//rylee
	sf::RectangleShape healthBackground;//rylee

	float health;//rylee

	void InitHealth();//Jake
	void CheckHealth();//Jake

public:

	Health();//Jake
	~Health();//Jake

	float& GetHealth();//Jake
	void ChangeHealth(float health_change);//Jake

	void Update();//Jake

	sf::RectangleShape GetHealthForeground();//Jake
	sf::RectangleShape GetHealthBackground();//Jake
};
