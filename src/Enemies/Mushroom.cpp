//
// Created by Łukasz Kus on 06/06/2021.
//

#include "../../include/Enemies/Mushroom.h"

//CONSTRUCTOR //DESTRUCTOR

Mushroom::Mushroom(sf::Vector2f position, SettingsData *windowSettings) :
		Enemy(position, windowSettings)
{
//	initMushroom();
	this->enemyClass = EntityTypes::Enemies::Mushroom;
//	std::string path = this->pathManager.getEnemyMushroomPath()
//	                   + "idle.png";
	this->animate = new Animate(this->enemyClass);
//	this->setCharacterTexture(path);
	this->animate->idleAnimation(this->enemySprite_);
}

Mushroom::~Mushroom()
{
}

void Mushroom::initStatistics()
{
	this->maximumHealth_ = 7500;
	this->health_ = 7500;
	this->atackDPS_ = 150;
	this->dodgeChance_ = 7;
	this->criticChance_ = 0;
}