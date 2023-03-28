//
// Created by Łukasz Kus on 05/06/2021.
//

#include "Eye.h"

//CONSTRUCTOR //DESTRUCTOR

Eye::Eye(sf::Vector2f position, SettingsData *windowSettings) :
		Enemy(position, windowSettings)
{
//	initEye();
	this->enemyClass = EntityTypes::Enemies::Eye;
//	std::string path = this->pathManager.getEnemyEyePath()
//	                   + "idle.png";
	this->animate = new Animate(this->enemyClass);
//	this->setCharacterTexture(path);
	this->animate->idleAnimation(this->enemySprite_);
}

Eye::~Eye()
{
}

void Eye::initStatistics()
{
	this->maximumHealth_ = 3000;
	this->health_ = 3000;
	this->atackDPS_ = 150;
	this->dodgeChance_ = 10;
	this->criticChance_ = 0;
}