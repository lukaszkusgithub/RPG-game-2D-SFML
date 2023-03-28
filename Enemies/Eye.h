//
// Created by Łukasz Kus on 05/06/2021.
//

#ifndef GAME_EYE_H
#define GAME_EYE_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Enemy.h"

class Eye : public Enemy
{
private:
	void initEye();
//	void initStatistics() override;

public:
	//CONSTRUCTOR //DESTRUCTOR

	Eye(sf::Vector2f position, SettingsData *windowSettings);

	~Eye();

	void initStatistics() override;

};


#endif //GAME_EYE_H
