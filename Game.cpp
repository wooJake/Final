#include "Game.h"

void Game::InitWindow(){

	title = "Final Project";//rylee
	vm = sf::VideoMode(maths.width, maths.height);//rylee
	window = new sf::RenderWindow(vm, title, sf::Style::Default);//rylee
	window->setFramerateLimit(60);//rylee
}
void Game::InitVariables(){

	clock.restart();//Jake
	dt = clock.restart().asSeconds();//Jake
	randEng.seed(clock.restart().asMilliseconds());//Jake

	friction = 0.90f;//rylee
}
void Game::InitBackground(){

	if (!image.loadFromFile("Sprites/FinalBackground.png")) {//Jake

		std::cout << "!ERROR::GAME::COULD NOT LOAD FinalBackground.png" << "\n";//Jake
	}

	texture.loadFromImage(image);//Jake
	background.setTexture(texture);//Jake
}
void Game::PollEvents() {

	sf::Event e;//rylee

	while (window->pollEvent(e)) {//rylee

		if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {//rylee

			window->close();//rylee
		}
	}
}
void Game::TimeAndSeed(){

	randEng.seed(unsigned int(std::chrono::steady_clock::now().time_since_epoch().count()));//Jake
	dt = clock.restart().asSeconds();//Jake
}
Game::Game(){

	InitWindow();//Jake
	InitVariables();//Jake
	InitBackground();//Jake
}
Game::~Game(){

	delete window;//Jake
}
void Game::Update(){

	PollEvents();//Jake
	TimeAndSeed();//Jake
	if (health.GetHealth() > 0) {//Jake

		ship.Update(friction);//Jake
		torpedo.Update(dt, ship.GetShip(), enemies.GetEnemies(), score.GetScore(), randEng);//Jake
		enemies.Update(dt, randEng, ship.GetShip(), health.GetHealth());//Jake
		health.Update();//Jake
		score.Update();//Jake
	}
}
void Game::Render(){

	window->clear(sf::Color(0x440088FF));//rylee

	window->draw(background);//Jake
	
	window->draw(ship.GetShip());
	if (ship.GetLeftFiring()) {
	
		window->draw(ship.GetLeftFlame());
	}
	if (ship.GetRightFiring()) {
	
		window->draw(ship.GetRightFlame());
	}
	window->draw(ship.GetLeftThruster());
	window->draw(ship.GetRightThruster());

	for (int i = 0; i < enemies.GetEnemies().size(); ++i) {//Jake

		window->draw(enemies.GetEnemies().at(i)->asteroidShape);//Jake
	}
	for (int i = 0; i < torpedo.GetTorpedo().size(); ++i) {//Jake

		window->draw(torpedo.GetTorpedo().at(i)->torpedoShape);//Jake
	}

	window->draw(score.GetScoreText());//Jake
	
	window->draw(health.GetHealthBackground());
	window->draw(health.GetHealthForeground());

	if (health.GetHealth() <= 0) {//Jake

		window->draw(endscreen.GetEndText());
	}
	window->display();//rylee
}
void Game::Run(){

	while (window->isOpen()) {//rylee

		Update();//Jake
		Render();//Jake
	}
}
