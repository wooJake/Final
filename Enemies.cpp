#include "Enemies.h"

void Enemies::InitAsteroids() {

	maxAsteroids = 15;//rylee
	astTimer = 0.0f;//rylee
	astTimerMax = 0.5f;//rylee
}
void Enemies::SpawnEnemies(float dt, std::default_random_engine rand_eng) {

	astTimer = astTimer + dt;
	if (astTimer > astTimerMax && asteroids.size() < maxAsteroids) {//Jake

		asteroids.push_back(new Rock);//Jake
		unsigned int size = unsigned int(asteroids.size() - 1);//Jake
		std::uniform_int_distribution<unsigned int> randSide(0, 3);//Jake
		std::uniform_real_distribution<float> randX(0.0f, float(maths.width));//Jake
		std::uniform_real_distribution<float> randY(0.0f, float(maths.height));//Jake
		std::uniform_int_distribution<sf::Uint32> randColor(0, 0xFF);//Jake
		std::uniform_real_distribution<float> randRadi(7.5f, 32.0f);//Jake
		std::uniform_int_distribution<unsigned int> randShape(4, 12);//Jake

		std::uniform_int_distribution<unsigned int> randHealth(0, 5);//rylee

		asteroids.at(size)->asteroidVel = sf::Vector2f(0.0f, 0.0f);//Jake
		asteroids.at(size)->asteroidShape.setPointCount(randShape(rand_eng));
		asteroids.at(size)->asteroidShape.setFillColor(sf::Color(randColor(rand_eng), randColor(rand_eng), randColor(rand_eng)));//Jake
		if (randHealth(rand_eng) == 0) {

			asteroids.at(size)->asteroidShape.setOutlineThickness(2.5f);
			asteroids.at(size)->asteroidShape.setOutlineColor(sf::Color::Green);
		}
		asteroids.at(size)->asteroidShape.setRadius(randRadi(rand_eng));//Jake
		asteroids.at(size)->asteroidShape.setOrigin(asteroids.at(size)->asteroidShape.getRadius(), asteroids.at(size)->asteroidShape.getRadius());//Jake

		switch (randSide(rand_eng)) {//Jake

		case 0:
			asteroids.at(size)->asteroidShape.setPosition(randX(rand_eng), 0.0f);//Jake
			randX = std::uniform_real_distribution<float>(0.0f, maths.pi);//Jake
			asteroids.at(size)->asteroidVel = sf::Vector2f(cos(randX(rand_eng)), sin(randX(rand_eng)));//Jake

			break;
		case 1:
			asteroids.at(size)->asteroidShape.setPosition(float(maths.width), randY(rand_eng));//Jake
			randX = std::uniform_real_distribution<float>(maths.pi / 2.0f, maths.pi * 1.5f);//Jake
			asteroids.at(size)->asteroidVel = sf::Vector2f(cos(randX(rand_eng)), sin(randX(rand_eng)));//Jake
			break;
		case 2:
			asteroids.at(size)->asteroidShape.setPosition(randX(rand_eng), float(maths.height));//Jake
			randX = std::uniform_real_distribution<float>(maths.pi, maths.tau);//Jake
			asteroids.at(size)->asteroidVel = sf::Vector2f(cos(randX(rand_eng)), sin(randX(rand_eng)));//Jake
			break;
		case 3:
			asteroids.at(size)->asteroidShape.setPosition(0.0f, randY(rand_eng));//Jake
			randX = std::uniform_real_distribution<float>(-(maths.pi / 2), maths.pi / 2);//Jake
			asteroids.at(size)->asteroidVel = sf::Vector2f(cos(randX(rand_eng)), sin(randX(rand_eng)));//Jake
			break;
		default:
			break;
		}
		astTimer = 0.0f;//Jake
	}
}
void Enemies::MoveEnemies(){

	for (int i = 0; i < asteroids.size(); ++i) {//Jake

		asteroids.at(i)->asteroidShape.move(asteroids.at(i)->asteroidVel);//Jake
	}
}
void Enemies::WrapWorld(){

	for (int i = 0; i < asteroids.size(); ++i) {//Jake

		if (asteroids.at(i)->asteroidShape.getPosition().y < 0.0f) {//rylee

			asteroids.at(i)->asteroidShape.setPosition(asteroids.at(i)->asteroidShape.getPosition().x, float(maths.height));//Jake
		}
		else if (asteroids.at(i)->asteroidShape.getPosition().y > float(maths.height)) {//rylee

			asteroids.at(i)->asteroidShape.setPosition(asteroids.at(i)->asteroidShape.getPosition().x, 0.0f);//Jake
		}
		if (asteroids.at(i)->asteroidShape.getPosition().x < 0.0f) {//rylee

			asteroids.at(i)->asteroidShape.setPosition(float(maths.width), asteroids.at(i)->asteroidShape.getPosition().y);//Jake
		}
		else if (asteroids.at(i)->asteroidShape.getPosition().x > float(maths.width)) {//rylee

			asteroids.at(i)->asteroidShape.setPosition(0.0f, asteroids.at(i)->asteroidShape.getPosition().y);//Jake
		}
	}
}
void Enemies::HitShip(sf::CircleShape ship, float& health){

	for (int i = 0; i < asteroids.size(); ++i) {

		sf::Vector2f shipPos = ship.getPosition();//Jake
		sf::Vector2f asteroidPos = asteroids.at(i)->asteroidShape.getPosition();//Jake
		float dx = asteroidPos.x - shipPos.x;//Jake
		float dy = asteroidPos.y - shipPos.y;//Jake
		float dist = sqrt(dx * dx + dy * dy);//Jake

		if (dist <= ship.getRadius() + asteroids.at(i)->asteroidShape.getRadius()) {//Jake

			if (asteroids.at(i)->asteroidShape.getOutlineThickness() > 0.0f) {//rylee

				if (health < 100) {//Jake

					health = health + int(asteroids.at(i)->asteroidShape.getRadius() * 2.0f);//rylee
				}
			}
			else {

				health = health - int(asteroids.at(i)->asteroidShape.getRadius() * 2.0f);//Jake
			}

			delete asteroids.at(i);//Jake
			asteroids.erase(asteroids.begin() + i);//Jake
		}
	}
}
Enemies::Enemies(){

	InitAsteroids();//Jake
}
Enemies::~Enemies(){

	for (int i = 0; i < asteroids.size(); ++i) {//Jake

		delete asteroids.at(i);//Jake
	}
	asteroids.erase(asteroids.begin(), asteroids.end());//Jake
}
void Enemies::Update(float dt, std::default_random_engine rand_eng, sf::CircleShape ship, float& health){

	SpawnEnemies(dt, rand_eng);//Jake
	MoveEnemies();//Jake
	WrapWorld();//Jake
	HitShip(ship, health);//Jake
}
void Enemies::Render(sf::RenderWindow& target){

	for (int i = 0; i < asteroids.size(); ++i) {//Jake

		target.draw(asteroids.at(i)->asteroidShape);//Jake
	}
}
std::vector<Rock*>& Enemies::GetEnemies(){

	return asteroids;//Jake
}
