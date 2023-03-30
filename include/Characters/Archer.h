//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_ARCHER_H
#define GAME_ARCHER_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Character.h"

class Archer : public Character
{
private:
		//FUNCTIONS
		void initializeStatistics() override;

		void initializeCharacterClassType() override;

public:
		//CONSTRUCTOR //DESTRUCTOR
		Archer(sf::Vector2f position, SettingsData *windowSettings);

		~Archer();

		float getAttackDPS(int attackID) override;

		float getAttackCritRate(int attackID) override;

		std::string getAttackName(int attackID) override;
};


#endif //GAME_ARCHER_H
