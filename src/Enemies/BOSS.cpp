//
// Created by Łukasz Kus on 07/06/2021.
//

#include "../../include/Enemies/BOSS.h"

//CONSTRUCTOR //DESTRUCTOR

BOSS::BOSS(sf::Vector2f position, SettingsData *windowSettings) :
		Enemy(position, windowSettings)
{
	this->enemyClass = EntityTypes::Enemies::BOSS;
	this->setEnemyScale(0.5);
	this->animate = new Animate(this->enemyClass);
	this->animate->idleAnimation(this->enemySprite_);
}

BOSS::~BOSS()
{
}

void BOSS::initStatistics()
{
	this->maximumHealth_ = 500000;
	this->health_ = 500000;
	this->atackDPS_ = 50000;
	this->dodgeChance_ = 50;
	this->criticChance_ = 50;
}

sf::Vector2f BOSS::getPosition()
{
	return this->enemyPosition_;
}

bool BOSS::isAlive()
{
	return this->isAlive_;
}
