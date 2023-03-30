//
// Created by Łukasz Kus on 27/05/2021.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//LIBS
#include <vector>
#include <map>
#include <stack>
#include <iostream>

//CLASSES
#include "../GUI/GUI.h"
#include "SettingsData.h"

class State;

class StateData
{
public:
		StateData()
		{
		};

		//Variables
		sf::RenderWindow *renderWindow;
		std::stack<State *> *states;
		SettingsData *windowSettings;
};

class State
{
private:
		//VARIABLES

		std::vector<sf::Texture> textures;

protected:
		//VARIABLES
		bool endLife = false;

		std::stack<State *> *states;
		sf::RenderWindow *renderWindow;
		SettingsData *windowSettings;

		StateData *stateData_;

		GUI *gui_;


		sf::Vector2i mousePositionPixel;
		sf::Vector2i mousePositionWindow;
		sf::FloatRect mouseRect;
		sf::FloatRect mouseRectPixel;
public:
		//CONSTRUCTOR //DESTRUCTOR

		State(StateData *stateData);

		virtual ~State();

		//FUNCTIONS

		[[nodiscard]] bool getEndLife() const;

		virtual void checkEndStateLife();

		virtual void killState() = 0;

		virtual void updateKeyBinds(const float &elapsed) = 0;

		virtual void updateState(const float &elapsed) = 0;

		virtual void renderState(sf::RenderTarget *renderTarget) = 0;

		virtual void updateMousePostion();

};


#endif //GAME_STATE_H
