//
// Created by Łukasz Kus on 06/06/2021.
//

#ifndef GAME_INTROSTATE_H
#define GAME_INTROSTATE_H

//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "State.h"
#include "ClassMenuState.h"

class IntroState : public State
{
private:
	//VARIABLES
	Path pathManager;
	sf::RenderTexture renderGameTexture;
	sf::Sprite renderSprite;
	float introTime = 3;
	float seconds = 0;

	//FUNCTIONS
	void initializeSprite();

	void initializeBackground();

public:
	//CONSTRUCTOR //DESTRUCTOR
	explicit IntroState(StateData *stateData);

	~IntroState() override;

	void killState() override;

	void updateKeyBinds(const float &elapsed) override;

	void updateState(const float &elapsed) override;

	void renderState(sf::RenderTarget *renderTarget) override;

	void checkIsEndOfAnimation(const float &elapsed);

};


#endif //GAME_INTROSTATE_H
