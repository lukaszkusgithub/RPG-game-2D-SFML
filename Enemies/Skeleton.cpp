//
// Created by Łukasz Kus on 06/06/2021.
//

#include "Skeleton.h"

//CONSTRUCTOR //DESTRUCTOR

Skeleton::Skeleton(sf::Vector2f position, SettingsData *windowSettings) :
		Enemy(position, windowSettings)
{
	this->enemyClass = EntityTypes::Enemies::Skeleton;
	this->animate = new Animate(this->enemyClass);
	this->animate->idleAnimation(this->enemySprite_);
}

Skeleton::~Skeleton()
{
}

void Skeleton::initStatistics()
{
	this->maximumHealth_ = 15000;
	this->health_ = 15000;
	this->atackDPS_ = 500;
	this->dodgeChance_ = 0;
	this->criticChance_ = 50;
}

