//
// Created by Łukasz Kus on 06/06/2021.
//

#ifndef GAME_SKELETON_H
#define GAME_SKELETON_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Enemy.h"

class Skeleton : public Enemy
{
public:

		//CONSTRUCTOR //DESTRUCTOR

		Skeleton(sf::Vector2f position, SettingsData *windowSettings);

		~Skeleton();

		void initStatistics() override;

};


#endif //GAME_SKELETON_H
