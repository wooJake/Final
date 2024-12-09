#include "Score.h"

void Score::InitFont() {

	if (!font.loadFromFile("Fonts/arial.ttf")) {//Jake

		std::cout << "!ERROR::GAME::COULD NOT LOAD arial.ttf" << "\n";//Jake
	}
}
void Score::InitText(){

	score = 0;//Jake
	scoreText.setFont(font);//Jake
	scoreText.setString("Score: ");//Jake
	scoreText.setFillColor(sf::Color::Black);//Jake
	scoreText.setOutlineColor(sf::Color::White);//Jake
	scoreText.setOutlineThickness(1.0f);//Jake
	scoreText.setPosition(maths.width * 0.01f, maths.height * 0.01f);//Jake
}
void Score::StreamText(){

	std::stringstream sStream;//Jake

	sStream << "Score: " << score;//Jake
	scoreText.setString(sStream.str());//Jake
	sStream.str("");//Jake
}
Score::Score(){

	InitFont();//Jake
	InitText();//Jake
}
Score::~Score(){


}
void Score::Update(){

	StreamText();//Jake
}
sf::Text Score::GetScoreText(){

	return scoreText;//Jake
}
unsigned int& Score::GetScore(){

	return score;//Jake
}
