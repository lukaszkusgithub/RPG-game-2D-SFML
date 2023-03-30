//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_BEAST_H
#define GAME_BEAST_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "NPC.h"

class Beast : public NPC
{
private:

public:
		//CONSTRUCTOR //DESTRUCTOR

		Beast(sf::Vector2f position, SettingsData *windowSettings);

		~Beast();
};

#endif //GAME_BEAST_H
