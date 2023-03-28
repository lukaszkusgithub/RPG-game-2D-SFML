//
// Created by Łukasz Kus on 28/05/2021.
//

#ifndef GAME_SETTINGSDATA_H
#define GAME_SETTINGSDATA_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <string>

//CLASSES
#include "../headers/EntityTypes.h"

class SettingsData
{
private:
		//VARIABLES

		float windowWidth;
		float windowHeight;
		std::string gameTitle;
		float frameRate;
		bool VSYNC;

		EntityTypes::CharacterClass characterClass_;
public:
		//CONSTRUCTOR //DESTRUCTOR

		SettingsData();

		~SettingsData();

		//GETTERS && SETTERS

		float getWidth();

		float getHeight();

		sf::Vector2f getWindowSize();

		float getFrameRate();

		bool getVsyncSettings();

		EntityTypes::CharacterClass getCharacterClass();

		void setCharacterClass(EntityTypes::CharacterClass characterClass);

		void setWidth(float x);

		void setHeight(float y);

		void setTitle(std::string title);

		void setFramerate(int framerate);

		void setVSYNC(bool vsync);


};


#endif //GAME_SETTINGSDATA_H
