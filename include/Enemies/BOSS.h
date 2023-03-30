//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_BOSS_H
#define GAME_BOSS_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Enemy.h"

class BOSS : public Enemy
{
private:
		void initBOSS();
		bool isAlive_ = true;

public:
		//CONSTRUCTOR //DESTRUCTOR

		BOSS(sf::Vector2f position, SettingsData *windowSettings);

		~BOSS();

		void initStatistics() override;

		sf::Vector2f getPosition();

		bool isAlive();
};


#endif //GAME_BOSS_H
