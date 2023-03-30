//
// Created by Łukasz Kus on 06/06/2021.
//

#ifndef GAME_MUSHROOM_H
#define GAME_MUSHROOM_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Enemy.h"

class Mushroom : public Enemy
{
public:

	//CONSTRUCTOR //DESTRUCTOR

	Mushroom(sf::Vector2f position, SettingsData *windowSettings);

	~Mushroom();

	void initStatistics() override;

};


#endif //GAME_MUSHROOM_H
