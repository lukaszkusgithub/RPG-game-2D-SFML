//
// Created by Łukasz Kus on 07/06/2021.
//

#include "Hero.h"

//CONSTRUCTOR //DESTRUCTOR

Hero::Hero(sf::Vector2f position, SettingsData *windowSettings) :
		NPC(position, windowSettings)
{
	this->npcClass = EntityTypes::NPCs::Hero;
	this->animate = new Animate(this->npcClass);
	this->animate->idleAnimation(this->npcSprite_);
}

Hero::~Hero()
{
}