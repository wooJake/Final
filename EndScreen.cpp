#include "EndScreen.h"

void EndScreen::InitFont(){

	if (!font.loadFromFile("Fonts/arial.ttf")) {//Jake

		std::cout << "!ERROR::GAME::COULD NOT LOAD arial.ttf" << "\n";//Jake
	}
}
void EndScreen::InitEndText(){

	endText.setFont(font);//Jake
	endText.setString("You Lost");//Jake
	endText.setFillColor(sf::Color::Black);//Jake
	endText.setOutlineColor(sf::Color::White);//Jake
	endText.setOutlineThickness(1.0f);//Jake
	endText.setOrigin(endText.getScale() * 0.5f);//Jake
	endText.setPosition(maths.width * 0.5f, maths.height * 0.5f);//Jake
}
EndScreen::EndScreen(){

	InitFont();
	InitEndText();
}
EndScreen::~EndScreen(){


}
void EndScreen::Render(sf::RenderWindow& target){

	target.draw(endText);//Jake
}
