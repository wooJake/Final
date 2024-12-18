#include "Maths.h"
#include "Health.h"

#include <SFML/Graphics.hpp>//Jake
#include <SFML/System.hpp>//Jake

class Ship {

private:

	Maths maths;//Jake
	Health health;//Jake

	sf::CircleShape ship;//rylee
	sf::RectangleShape leftThruster;//Jake
	sf::RectangleShape rightThruster;//Jake
	sf::RectangleShape leftFlame;//Jake
	sf::RectangleShape rightFlame;//Jake

	float shipRadius = 27.0f;//Jake
	sf::Vector2f shipVel = sf::Vector2f(0.0f, 0.0f);//rylee
	float shipAccel = 1.03f;//rylee
	float shipRotAccel = 3.00f;//Jake

	bool leftFiring;//Jake
	bool rightFiring;//Jake

	void InitShip();//Jake

	void MoveShip(float friction);//Jake
	void MoveThrusters();//Jake
	void WrapWorld();//Jake

public:

	Ship();//Jake
	~Ship();//Jake

	void Update(float friction);//Jake

	sf::CircleShape GetShip();//Jake
	sf::RectangleShape GetLeftThruster();//Jake
	sf::RectangleShape GetRightThruster();//Jake
	sf::RectangleShape GetLeftFlame();//Jake
	sf::RectangleShape GetRightFlame();//Jake

	bool GetLeftFiring();//Jake
	bool GetRightFiring();//Jake
};
