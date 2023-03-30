//
// Created by Łukasz Kus on 07/06/2021.
//

#include "../../include/NPC/StrongKnight.h"

//CONSTRUCTOR //DESTRUCTOR

StrongKnight::StrongKnight(sf::Vector2f position, SettingsData *windowSettings)
		:
		NPC(position, windowSettings)
{
	this->npcClass = EntityTypes::NPCs::StrongKnight;
	this->animate = new Animate(this->npcClass);
	this->animate->idleAnimation(this->npcSprite_);
}

StrongKnight::~StrongKnight()
{
}