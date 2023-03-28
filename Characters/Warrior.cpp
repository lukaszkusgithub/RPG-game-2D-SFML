//
// Created by Łukasz Kus on 12/05/2021.
//

#include "Warrior.h"

//CONSTRUCTOR //DESTRUCTOR

Warrior::Warrior(sf::Vector2f position, SettingsData *windowSettings) :
Character(position, windowSettings)
{
	this->attacks = AttackTypes::warriorAttacks();
	this->attacksDPS = AttackTypes::warriorAttacksDPS();
	this->attacksCritRate = AttackTypes::warriorAttacksCritRate();
}

Warrior::~Warrior() {
}

//FUNCTIONS

void Warrior::initializeCharacterClassType()
{
	this->characterClass = EntityTypes::CharacterClass::Warrior;
	this->animate = new Animate(this->characterClass);
	this->animate->idleAnimation(this->characterSprite_);
}

void Warrior::initializeStatistics() {
	this->fieldOfView_ = sf::Vector2f(170,170);
	this->characterHealth_ = 5000;
	this->maximumCharacterHealth_ = 5000;
	this->characterSpeed_ = 150;
	this->attackDPS_ = 50;
	this->dodgeChance_ = 5;
	this->criticChance_ = 80;

}

float Warrior::getAttackDPS(int attackID)
{
	return this->attacksDPS[this->attacks[attackID]];
}

float Warrior::getAttackCritRate(int attackID)
{
	return this->attacksCritRate[this->attacks[attackID]];
}

std::string Warrior::getAttackName(int attackID)
{
	return this->attacks[attackID];
}




