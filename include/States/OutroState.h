//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_OUTROSTATE_H
#define GAME_OUTROSTATE_H


//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//CLASSES
#include "State.h"
#include "../Player.h"

class OutroState : public State
{
private:
	//VARIABLES
	Path pathManager;
	sf::RenderTexture renderGameTexture;
	sf::Sprite renderSprite;

	sf::RectangleShape background;

	sf::Color backgroundColor = {128, 128, 128};
	sf::Color textColor = {255, 255, 255};
	sf::Font font;

	sf::Text MenuText;

	bool isWon = false;


	//FUNCTIONS

	void initializeSprite();

	void loadFont();

	void initializeBackground(sf::Vector2f windowSize);

	void initializeText();


public:
	//CONSTRUCTOR //DESTRUCTOR

	explicit OutroState(StateData *stateData, bool value);

	~OutroState() override;

	//FUNCTIONS
	void killState() override;

	void updateKeyBinds(const float &elapsed) override;

	void updateState(const float &elapsed) override;

	void renderState(sf::RenderTarget *renderTarget) override;

};

#endif //GAME_OUTROSTATE_H
