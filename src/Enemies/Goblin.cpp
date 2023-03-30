//
// Created by Łukasz Kus on 06/06/2021.
//

#include "../../include/Enemies/Goblin.h"

//CONSTRUCTOR //DESTRUCTOR

Goblin::Goblin(sf::Vector2f position, SettingsData *windowSettings) :
		Enemy(position, windowSettings)
{
//	initGoblin();
	this->enemyClass = EntityTypes::Enemies::Goblin;
//	std::string path = this->pathManager.getEnemyGoblinPath()
//	                   + "idle.png";
	this->animate = new Animate(this->enemyClass);
//	this->setCharacterTexture(path);
	this->animate->idleAnimation(this->enemySprite_);
}

Goblin::~Goblin()
{
}

void Goblin::initStatistics()
{
	this->maximumHealth_ = 10000;
	this->health_ = 10000;
	this->atackDPS_ = 200;
	this->dodgeChance_ = 5;
	this->criticChance_ = 20;
}
