//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_MAGE_H
#define GAME_MAGE_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//CLASSES
#include "Character.h"

class Mage : public Character
{
private:
	//FUNCTIONS
	void initializeStatistics() override;

	void initializeCharacterClassType() override;

public:
	//CONSTRUCTOR //DESTRUCTOR
	Mage(sf::Vector2f position, SettingsData *windowSettings);

	~Mage();

	float getAttackDPS(int attackID) override;

	float getAttackCritRate(int attackID) override;

	std::string getAttackName(int attackID) override;

};


#endif //GAME_MAGE_H
