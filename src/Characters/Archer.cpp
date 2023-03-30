//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../../include/Characters/Archer.h"

//CONSTRUCTOR //DESTRUCTOR

Archer::Archer(sf::Vector2f position, SettingsData *windowSettings) :
		Character(position, windowSettings)
{
	this->attacks = AttackTypes::archerAttacks();
	this->attacksDPS = AttackTypes::archerAttacksDPS();
	this->attacksCritRate = AttackTypes::archerAttacksCritRate();
}

Archer::~Archer() {
}

//FUNCTIONS

void Archer::initializeCharacterClassType()
{
	this->characterClass = EntityTypes::CharacterClass::Archer;
	this->animate = new Animate(this->characterClass);
	this->animate->idleAnimation(this->characterSprite_);
}

void Archer::initializeStatistics() {
	this->fieldOfView_ = sf::Vector2f(230,230);
	this->characterHealth_ = 4000;
	this->maximumCharacterHealth_ = 4000;
	this->characterSpeed_ = 200;
	this->attackDPS_ = 100;
	this->dodgeChance_ = 15;
	this->criticChance_ = 40;
}

float Archer::getAttackDPS(int attackID)
{
	return this->attacksDPS[this->attacks[attackID]];
}

float Archer::getAttackCritRate(int attackID)
{
	return this->attacksCritRate[this->attacks[attackID]];
}

std::string Archer::getAttackName(int attackID)
{
	return this->attacks[attackID];
}
