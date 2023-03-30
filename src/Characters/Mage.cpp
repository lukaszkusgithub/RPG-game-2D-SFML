//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../../include/Characters/Mage.h"

//CONSTRUCTOR //DESTRUCTOR

Mage::Mage(sf::Vector2f position, SettingsData *windowSettings) :
		Character(position, windowSettings)
{
	this->attacks = AttackTypes::mageAttacks();
	this->attacksDPS = AttackTypes::MageAttacksDPS();
	this->attacksCritRate = AttackTypes::MageAttacksCritRate();
}

Mage::~Mage() {
}

//FUNCTIONS

void Mage::initializeCharacterClassType()
{
	this->characterClass = EntityTypes::CharacterClass::Mage;
	this->animate = new Animate(this->characterClass);
	this->animate->idleAnimation(this->characterSprite_);
}

void Mage::initializeStatistics() {
	this->fieldOfView_ = sf::Vector2f(200,200);
	this->characterHealth_ = 3000;
	this->maximumCharacterHealth_ = 3000;
	this->characterSpeed_ = 100;
	this->attackDPS_ = 250;
	this->dodgeChance_ = 0;
	this->criticChance_ = 10;
}

float Mage::getAttackDPS(int attackID)
{
	return this->attacksDPS[this->attacks[attackID]];
}

float Mage::getAttackCritRate(int attackID)
{
	return this->attacksCritRate[this->attacks[attackID]];
}

std::string Mage::getAttackName(int attackID)
{
	return this->attacks[attackID];
}
