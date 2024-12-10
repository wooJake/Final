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
	leftThruster.setPosition(ship.getPosition() + enginePosition * ship.getRadius());//rylee
	leftThruster.setRotation(ship.getRotation());//rylee

	rightThruster.setSize(sf::Vector2f(6.0f, 12.0f));//rylee
	rightThruster.setOrigin(rightThruster.getSize() * 0.5f);//rylee
	rightThruster.setFillColor(sf::Color::Magenta);//rylee
	theta = ship.getRotation() * maths.degree - (maths.pi * 1.85f);//rylee
	enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee
	rightThruster.setPosition(ship.getPosition() + enginePosition * ship.getRadius());//rylee
	rightThruster.setRotation(ship.getRotation());//rylee
}
void Ship::MoveShip(float friction){

	sf::Vector2f origin = ship.getOrigin();//Jake
	float theta = ship.getRotation() * maths.degree - (maths.pi / 2);//Jake
	float radius = ship.getRadius();//Jake
	sf::Vector2f facingDir = sf::Vector2f(cos(theta), sin(theta));//Jake

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {//rylee

		shipVel = shipVel + (facingDir * shipAccel);//rylee
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {//Jake

		ship.rotate(-shipRotAccel);//Jake
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {//Jake

		ship.rotate(shipRotAccel);//Jake
	}
	shipVel = shipVel * friction;//rylee
	ship.move(shipVel);//rylee//Jake

	theta = ship.getRotation() * maths.degree - (maths.pi * 1.15f);//rylee
	sf::Vector2f enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee
	leftThruster.setPosition(ship.getPosition() + enginePosition * ship.getRadius());//rylee
	leftThruster.setRotation(ship.getRotation());//rylee
	
	theta = ship.getRotation() * maths.degree - (maths.pi * 1.85f);//rylee
	enginePosition = sf::Vector2f(cos(theta), sin(theta));//rylee
	rightThruster.setPosition(ship.getPosition() + enginePosition * ship.getRadius());//rylee
	rightThruster.setRotation(ship.getRotation());//rylee
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
