//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_WARRIOR_H
#define GAME_WARRIOR_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "Character.h"

class Warrior : public Character
{
private:
	//FUNCTIONS
	void initializeStatistics() override;
	void initializeCharacterClassType() override;

public:
	//CONSTRUCTOR //DESTRUCTOR
	Warrior(sf::Vector2f position, SettingsData *windowSettings);
	~Warrior();

	float getAttackDPS(int attackID) override;
	float getAttackCritRate(int attackID) override;
	std::string  getAttackName(int attackID) override;

};


#endif //GAME_WARRIOR_H
