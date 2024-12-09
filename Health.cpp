#include "Health.h"

void Health::InitHealth(){

	health = 100;//Jake

	healthForeground.setSize(sf::Vector2f(100, 20));//rylee
	healthForeground.setOrigin(healthForeground.getSize() * 0.5f);//rylee
	healthForeground.setFillColor(sf::Color::Red);//rylee
	healthForeground.setPosition(float(maths.width) * 0.5f, float(maths.height) * 0.025f);//rylee

	healthBackground.setSize(sf::Vector2f(105, 25));//rylee
	healthBackground.setOrigin(healthBackground.getSize() * 0.5f);//rylee
	healthBackground.setFillColor(sf::Color(128, 128, 128, 128));//rylee
	healthBackground.setPosition(healthForeground.getPosition());//rylee
}
void Health::CheckHealth(){

	if (health < 0) {//Jake

		health = 0;//Jake
	}
	if (health > 100) {//Jake

		health = 100;//Jake
	}
	healthForeground.setSize(sf::Vector2f(float(health), healthForeground.getSize().y));//Jake
}
Health::Health(){

	InitHealth();//Jake
}
Health::~Health(){


}
float& Health::GetHealth(){

	return health;//Jake
}
void Health::ChangeHealth(float health_change){

	this->health = this->health + health_change;//Jake
}
void Health::Update(){

	CheckHealth();//Jake
}
void Health::Render(sf::RenderWindow& target){

	target.draw(healthBackground);//rylee
	target.draw(healthForeground);//rylee
}
