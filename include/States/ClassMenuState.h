//
// Created by Łukasz Kus on 27/05/2021.
//

#ifndef GAME_CLASSMENUSTATE_H
#define GAME_CLASSMENUSTATE_H

//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//LIBS
#include <iostream>
#include <utility>

//CLASSES
#include "State.h"
#include "GameState.h"
#include "../EntityTypes.h"
#include "../Path.h"


class ClassMenuState : public State
{
private:
		//VARIABLES
		Path pathManager;
		sf::RenderTexture renderGameTexture;
		sf::Sprite renderSprite;


		//FUNCTIONS

		void checkChoseButton();

		void initializeSprite();

		void initializeBackground();

		void initializeButtons();

		void initializeText();


public:
		//CONSTRUCTOR //DESTRUCTOR

		explicit ClassMenuState(StateData *stateData);

		~ClassMenuState() override;

		//FUNCTIONS
		void killState() override;

		void updateKeyBinds(const float &elapsed) override;

		void updateState(const float &elapsed) override;

		void renderState(sf::RenderTarget *renderTarget) override;


//	void updateView();
//	void updatePlayer(const float &elapsed);
//	void updateEnemies(const float &elapsed);

};


#endif //GAME_CLASSMENUSTATE_H
