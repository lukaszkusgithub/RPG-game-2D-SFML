//
// Created by Łukasz Kus on 07/06/2021.
//

#include "../../include/NPC/NPC.h"

//CONSTRUCTOR //DESTRUCTOR


NPC::NPC(sf::Vector2f position, SettingsData *windowSettings)
{
	this->npcSprite_.setPosition(position);
	this->windowSettings_ = windowSettings;
	this->buffType = BuffTypes::getRandomBuff();
	this->deBuffType = BuffTypes::getRandomDeBuff();
}

NPC::~NPC()
{

}

//FUNCTIONS

void NPC::animateNPC(const float &seconds)
{
	this->animate->runAnimation(this->npcSprite_, seconds);
}

void NPC::renderNPC(sf::RenderTexture &renderGameTexture)
{
	renderGameTexture.draw(this->npcSprite_);
}

bool NPC::isActive()
{
	return this->isActive_;
}

sf::FloatRect NPC::getBounds()
{
	return this->npcSprite_.getGlobalBounds();
}

BuffTypes::Buffs NPC::getBuffs()
{
	return this->buffType;
}

void NPC::deactivateNPC()
{
	this->isActive_ = false;
}

BuffTypes::DeBuffs NPC::getDebuffs()
{
	return this->deBuffType;
}
