#include "Torpedo.h"

void Torpedo::FireTorpedo(float dt, sf::CircleShape ship){

	torpedoTimer = torpedoTimer + dt;//Jake

	if (torpedoTimer > torpedoTimerMax && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {//rylee

		sf::Vector2f origin = ship.getOrigin();//Jake
		float theta = ship.getRotation() * maths.degree - (maths.pi / 2);//Jake
		float radius = ship.getRadius();//Jake
		sf::Vector2f facingDir = sf::Vector2f(cos(theta), sin(theta));//Jake

		torpedo.push_back(new Missile);//rylee//Jake
		unsigned int size = unsigned int(torpedo.size() - 1);
		torpedo.at(size)->torpedoVel = facingDir * torpedoSpeed;//Jake
		torpedo.at(size)->torpedoShape.setFillColor(sf::Color::Red);//rylee//Jake
		torpedo.at(size)->torpedoShape.setRadius(torpRadius);//rylee//Jake
		torpedo.at(size)->torpedoShape.setOrigin(torpedo.at(size)->torpedoShape.getRadius(), torpedo.at(size)->torpedoShape.getRadius());//rylee//Jake
		torpedo.at(size)->torpedoShape.setPosition(ship.getPosition().x + facingDir.x * ship.getRadius(), ship.getPosition().y + facingDir.y * ship.getRadius());//rylee//Jake

		torpedoTimer = 0.0f;//rylee
	}
}
void Torpedo::Accelerate(){

	for (int i = 0; i < torpedo.size(); ++i) {//rylee

		torpedo.at(i)->torpedoVel = torpedo.at(i)->torpedoVel * torpedoAccel;//Jake
		torpedo.at(i)->torpedoShape.move(torpedo.at(i)->torpedoVel);//rylee//Jake
	}
}
void Torpedo::OutOfBounds(){

	for (int i = 0; i < torpedo.size(); ++i) {

		if (torpedo.at(i)->torpedoShape.getPosition().x < 0.0f ||
			torpedo.at(i)->torpedoShape.getPosition().y < 0.0f ||
			torpedo.at(i)->torpedoShape.getPosition().x > maths.width ||
			torpedo.at(i)->torpedoShape.getPosition().y > maths.height) {//rylee//Jake

			delete torpedo.at(i);//rylee
			torpedo.erase(torpedo.begin() + i);//Jake
			return;
		}
	}
}
void Torpedo::HitAsteroid(std::vector<Rock*>& asteroids, unsigned int& score, std::default_random_engine rand_eng){

	for (int i = 0; i < torpedo.size(); ++i) {//rylee

		sf::Vector2f torpedoPos = torpedo.at(i)->torpedoShape.getPosition();//Jake

		for (int j = 0; j < asteroids.size(); ++j) {//Jake

			sf::Vector2f asteroidPos = asteroids.at(j)->asteroidShape.getPosition();//Jake
			float dx = asteroidPos.x - torpedoPos.x;//Jake
			float dy = asteroidPos.y - torpedoPos.y;//Jake
			float dist = dx * dx + dy * dy;//Jake
			float rad = torpedo.at(i)->torpedoShape.getRadius() + asteroids.at(j)->asteroidShape.getRadius();//Jake

			if (dist <= rad * rad) {//Jake

				score = score + 1;//Jake

				delete torpedo.at(i);//rylee
				torpedo.erase(torpedo.begin() + i);//Jake

				if (asteroids.at(j)->asteroidShape.getRadius() <= 10.0f) {//Jake

					delete asteroids.at(j);//Jake
					asteroids.erase(asteroids.begin() + j);//Jake
				}
				else {//Jake

					asteroids.at(j)->asteroidShape.setRadius(asteroids.at(j)->asteroidShape.getRadius() * 0.5f);//Jake

					asteroids.push_back(new Rock);//Jake
					unsigned int size = asteroids.size() - 1;//Jake
					asteroids.at(size)->asteroidShape = asteroids.at(j)->asteroidShape;//Jake
					asteroids.at(size)->asteroidShape.setPosition(asteroids.at(j)->asteroidShape.getPosition());//Jake

					std::uniform_real_distribution<float> randAngle(0.0f, maths.tau);//Jake
					asteroids.at(size)->asteroidVel = sf::Vector2f(cos(randAngle(rand_eng)), sin(randAngle(rand_eng)));//Jake
				}

				return;
			}
		}
	}
}
Torpedo::Torpedo(){

}
Torpedo::~Torpedo(){

	for (int i = 0; i < torpedo.size(); ++i) {//Jake

		delete torpedo.at(i);//Jake
	}
	torpedo.erase(torpedo.begin(), torpedo.end());//Jake
}
void Torpedo::Update(float dt, sf::CircleShape ship, std::vector<Rock*>& asteroids, unsigned int& score, std::default_random_engine rand_eng){

	FireTorpedo(dt, ship);//Jake
	Accelerate();//Jake
	OutOfBounds();//Jake
	HitAsteroid(asteroids, score, rand_eng);//Jake
}
void Torpedo::Render(sf::RenderWindow& target){

	for (int i = 0; i < torpedo.size(); ++i) {//rylee

		target.draw(torpedo.at(i)->torpedoShape);//rylee
	}
}
std::vector<Missile*> Torpedo::GetTorpedo(){

	return torpedo;//Jake
}
