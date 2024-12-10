#include "Ship.h"

void Ship::InitShip(){

	ship.setRadius(shipRadius);//rylee
	ship.setOrigin(sf::Vector2f(ship.getRadius(), ship.getRadius()));//rylee
	ship.setFillColor(sf::Color(0x22FF00FF));//rylee
	ship.setPosition(maths.width / 2.0f, maths.height / 2.0f);//rylee
	ship.setPointCount(3);//rylee

	leftThruster.setSize(sf::Vector2f(6.0f, 12.0f));//rylee
	leftThruster.setOrigin(leftThruster.getSize() * 0.5f);//rylee
	leftThruster.setFillColor(sf::Color::Magenta);//rylee
	float theta = ship.getRotation() * maths.degree - (maths.pi * 1.15f);//rylee
	sf::Vector2f enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee

	leftFlame.setSize(sf::Vector2f(3.0f, 6.0f));//Jake
	leftFlame.setOrigin(leftFlame.getSize() * 0.5f);//Jake
	leftFlame.setFillColor(sf::Color(0xFF8800FF));//Jake

	rightThruster.setSize(sf::Vector2f(6.0f, 12.0f));//rylee
	rightThruster.setOrigin(rightThruster.getSize() * 0.5f);//rylee
	rightThruster.setFillColor(sf::Color::Magenta);//rylee
	theta = ship.getRotation() * maths.degree - (maths.pi * 1.85f);//rylee
	enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee

	rightFlame.setSize(sf::Vector2f(3.0f, 6.0f));//Jake
	rightFlame.setOrigin(rightFlame.getSize() * 0.5f);//Jake
	rightFlame.setFillColor(sf::Color(0xFF8800FF));//Jake
}
void Ship::MoveShip(float friction){

	leftFiring = false;//Jake
	rightFiring = false;//Jake

	sf::Vector2f origin = ship.getOrigin();//Jake
	float theta = ship.getRotation() * maths.degree - (maths.pi / 2);//Jake
	float radius = ship.getRadius();//Jake
	sf::Vector2f facingDir = sf::Vector2f(cos(theta), sin(theta));//Jake

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {//rylee

		shipVel = shipVel + (facingDir * shipAccel);//rylee
		leftFiring = true;//Jake
		rightFiring = true;//Jake
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {//Jake

		ship.rotate(-shipRotAccel);//Jake
		rightFiring = true;//Jake
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {//Jake

		ship.rotate(shipRotAccel);//Jake
		leftFiring = true;//Jake
	}
	shipVel = shipVel * friction;//rylee
	ship.move(shipVel);//rylee//Jake
}
void Ship::MoveThrusters(){

	float theta = ship.getRotation() * maths.degree - (maths.pi * 1.15f);//rylee
	sf::Vector2f enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee
	leftThruster.setPosition(ship.getPosition() + enginePosition * ship.getRadius());//rylee
	leftThruster.setRotation(ship.getRotation());//rylee

	theta = ship.getRotation() * maths.degree + (maths.pi * 2.5f);//Jake
	sf::Vector2f flamePos = sf::Vector2f(cos(theta), sin(theta));//Jake
	leftFlame.setPosition(leftThruster.getPosition() + 8.0f * flamePos);//Jake
	leftFlame.setRotation(leftThruster.getRotation());//Jake

	theta = ship.getRotation() * maths.degree - (maths.pi * 1.85f);//rylee
	enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee
	rightThruster.setPosition(ship.getPosition() + enginePosition * ship.getRadius());//rylee
	rightThruster.setRotation(ship.getRotation());//rylee

	rightFlame.setPosition(rightThruster.getPosition() + 8.0f * flamePos);//Jake
	rightFlame.setRotation(rightThruster.getRotation());//Jake

	rightFlame.setFillColor(sf::Color(255.0f, rightFlame.getFillColor().g + 23, 0, 255));//Jake
	leftFlame.setFillColor(sf::Color(255.0f, rightFlame.getFillColor().g + 23, 0, 255));//Jake
}
void Ship::WrapWorld(){

	if (ship.getPosition().y < 0.0f) {//rylee

		ship.setPosition(ship.getPosition().x, float(maths.height));//Jake
	}
	else if (ship.getPosition().y > float(maths.height)) {//rylee

		ship.setPosition(ship.getPosition().x, 0.0f);//Jake
	}
	if (ship.getPosition().x < 0.0f) {//rylee

		ship.setPosition(float(maths.width), ship.getPosition().y);//Jake
	}
	else if (ship.getPosition().x > maths.width) {//rylee

		ship.setPosition(0.0f, ship.getPosition().y);//Jake
	}
}
Ship::Ship(){

	InitShip();//Jake
}
Ship::~Ship(){


}
void Ship::Update(float friction){

	if (health.GetHealth() > 0) {//Jake

		MoveShip(friction);//Jake
		MoveThrusters();//Jake
		WrapWorld();//Jake
	}
}
sf::CircleShape Ship::GetShip(){

	return ship;//Jake
}
sf::RectangleShape Ship::GetLeftThruster(){

	return leftThruster;//Jake
}
sf::RectangleShape Ship::GetRightThruster(){

	return rightThruster;//Jake
}
sf::RectangleShape Ship::GetLeftFlame(){

	return leftFlame;
}
sf::RectangleShape Ship::GetRightFlame(){

	return rightFlame;
}
bool Ship::GetLeftFiring(){

	return leftFiring;
}
bool Ship::GetRightFiring(){

	return rightFiring;
}
