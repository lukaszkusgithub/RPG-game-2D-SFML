//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

//SFML LIBS
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//LIBS
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>
#include <string>
#include <stack>

//CLASSES
#include "Path.h"
#include "../include/States/State.h"
#include "../include/States/SettingsData.h"
#include "../include/States/IntroState.h"

class Game
{
private:
		//VARIABLES

		sf::RenderWindow *window{};
		sf::Event event{};
		sf::Clock clock;
		sf::Time elapsed;

		Path pathManager;
		StateData stateData;
		SettingsData windowSettings;

		std::stack<State *> states;


		//FUNCTIONS

		void loadSettings(std::map<std::string, int> &settingsData);

		void initializeGameWindow();

		void initializeGameStates();

		void initializeGameStateData();


public:
		//CONSTRUCTOR //DESTRUCTOR

		Game();

		~Game();

		//FUNCTIONS

		void runGame();

		void closeGame();

		void updateGame();

		void updateEvents();

		void updateTime();

		void renderGame();


};


#endif //GAME_GAME_H
