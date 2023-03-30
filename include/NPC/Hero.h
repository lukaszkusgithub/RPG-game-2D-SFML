//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_HERO_H
#define GAME_HERO_H


//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "NPC.h"

class Hero : public NPC
{
private:
//	void initHero();

public:
		//CONSTRUCTOR //DESTRUCTOR

		Hero(sf::Vector2f position, SettingsData *windowSettings);

		~Hero();
};


#endif //GAME_HERO_H
