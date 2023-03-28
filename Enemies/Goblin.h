//
// Created by Łukasz Kus on 06/06/2021.
//

#ifndef GAME_GOBLIN_H
#define GAME_GOBLIN_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Enemy.h"

class Goblin : public Enemy
{
public:

	//CONSTRUCTOR //DESTRUCTOR

	Goblin(sf::Vector2f position, SettingsData *windowSettings);

	~Goblin();

	void initStatistics() override;
};


#endif //GAME_GOBLIN_H
