//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_STRONGKNIGHT_H
#define GAME_STRONGKNIGHT_H


//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "NPC.h"

class StrongKnight : public NPC
{
private:
//	void initStrongKnight();

public:
		//CONSTRUCTOR //DESTRUCTOR

		StrongKnight(sf::Vector2f position, SettingsData *windowSettings);

		~StrongKnight();
};


#endif //GAME_STRONGKNIGHT_H
