//
// Created by Łukasz Kus on 07/06/2021.
//

#include "../../include/NPC/Beast.h"

//CONSTRUCTOR //DESTRUCTOR


Beast::Beast(sf::Vector2f position, SettingsData *windowSettings) :
		NPC(position, windowSettings)
{
	this->npcClass = EntityTypes::NPCs::Beast;
	this->animate = new Animate(this->npcClass);
	this->animate->idleAnimation(this->npcSprite_);
}

Beast::~Beast()
{
}

