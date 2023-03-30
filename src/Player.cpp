//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../include/Player.h"

//CONSTRUCTOR //DESTRUCTOR

Player::Player(sf::Vector2f position, SettingsData *windowSettings){
	chooseCharacterClass(position,
			windowSettings);
	this->characterClass->initializeCharacterClassType();
	this->characterClass->initializeStatistics();
};


Player::~Player() {

}
//= default;

//FUNCTIONS

void Player::updatePosition(sf::Keyboard::Key key, const float &elapsed)
{
	if (key == sf::Keyboard::A)
	{
		this->characterClass->moveLeft(elapsed);
	}
	else if (key == sf::Keyboard::D)
	{
		this->characterClass->moveRight(elapsed);

	}
	else if (key == sf::Keyboard::W)
	{
		this->characterClass->moveUp(elapsed);

	}
	else if (key == sf::Keyboard::S)
	{
		this->characterClass->moveDown(elapsed);

	}
	this->characterClass->updatePosition();
}

void Player::chooseCharacterClass(const sf::Vector2f &position, SettingsData
*windowSettings)
{
	if (windowSettings->getCharacterClass() ==
	EntityTypes::CharacterClass::Warrior) {
		this->characterClass = std::make_unique<Warrior>(position,
				windowSettings);
	}
	else if (windowSettings->getCharacterClass() ==
	EntityTypes::CharacterClass::Mage) {
		this->characterClass = std::make_unique<Mage>(position,
		                                                 windowSettings);
	}
	else if (windowSettings->getCharacterClass() ==
	EntityTypes::CharacterClass::Archer) {
		this->characterClass = std::make_unique<Archer>(position,
		                                                 windowSettings);
	}

}

void Player::stopMove()
{
	this->characterClass->stopMove();
}

void Player::renderPlayer(sf::RenderTexture &renderGameTexture)
{
	renderGameTexture.draw(this->characterClass->characterSprite());

}

void Player::updateAnimation(const float &elapsed)
{
	this->characterClass->animateCharacter(elapsed);
}

void Player::setNextPosition(sf::Keyboard::Key key, const float &elapsed) {
	this->characterClass->getNextPosition(elapsed, key);
}

bool Player::checkCollision(sf::FloatRect bounds, bool isAlive)
{
	return isAlive && this->getNextBounds().intersects(bounds) == 1;
}

//GETTERS && SETTERS

sf::Vector2f Player::getPosition()
{
	return this->characterClass->characterPosition();
}

sf::Vector2f Player::getNextPosition()
{
	return this->characterClass->characterNextPosition();
}

sf::FloatRect Player::getNextBounds()
{
	return this->characterClass->characterNextBounds();
}

sf::Vector2f Player::getFieldOfView()
{
	return this->characterClass->fieldOfView();
}

bool Player::isAlive()
{
	return this->characterClass->isAlive();
}

void Player::setFightPosition(sf::Vector2f position)
{
	return this->characterClass->setFightPosition(position);
}

void Player::setIdleAnimation()
{
	this->characterClass->setIdleAnimation();
}

std::string Player::getCurrentAnmations()
{
	return this->characterClass->getCurrentAnimation();
}

float Player::getAttackDPS(const int &attackID)
{
	return this->characterClass->getAttackDPS(attackID);
}

float Player::getAttackCritRate(const int &attackID)
{
	return this->characterClass->getAttackCritRate(attackID);

}

std::string Player::getAttackName(const int &attackID)
{
	return this->characterClass->getAttackName(attackID);
}

float Player::getPlayerDPS()
{
	return this->characterClass->characterDPS();
}

void Player::removeHealth(float dps)
{
	this->characterClass->removeHealth(dps);
}

void Player::levelUp()
{
	this->characterClass->characterLevelUp();
	this->playerLevel += 1;
}

void Player::setScale(float scale)
{
	this->characterClass->setCharacterScale(scale);
}

float Player::getPercentOfHealth()
{
	return  this->characterClass->characterHealth() /
	this->characterClass->characterMaximumHealth();
}

bool Player::isInFight()
{
	return this->isInFight_;
}

void Player::setFightState()
{
	this->isInFight_ = true;
}

void Player::removeFightState()
{
	this->isInFight_ = false;
}

void Player::savePlayerState()
{
	this->beforePosition = this->getPosition();
	this->beforeScale = this->characterClass->getCharacterScale();
}

void Player::loadPlayerState()
{
	this->setScale(this->beforeScale.x);
	this->characterClass->setCharacterPosition(this->beforePosition);
}

int Player::getPlayerLevel()
{
	return this->playerLevel;
}

void Player::addDPS(const int &value)
{
	this->characterClass->addDPS(value);
}

void Player::addHealth(const int &value)
{
	this->characterClass->addHealth(value);
}

void Player::addSpeed(const int &value)
{
	this->characterClass->addSpeed(value);
}

void Player::addVision(const int &value)
{
	this->characterClass->addVision(value);
}

void Player::addDodge(const int &value)
{
	this->characterClass->addDodge(value);
}

void Player::addCritic(const int &value)
{	this->characterClass->addCritic(value);

}

void Player::removeDPS(const int &value)
{
	this->characterClass->removeDPS(value);

}

void Player::removeHealth(const int &value)
{
	this->characterClass->removeHealth(value);

}

void Player::removeVision(const int &value)
{
	this->characterClass->removeVision(value);

}

void Player::removeSpeed(const int &value)
{
	this->characterClass->removeSpeed(value);

}

void Player::removeCritic(const int &value)
{
	this->characterClass->removeCritic(value);

}

void Player::removeDodge(const int &value)
{
	this->characterClass->removeDodge(value);
}

void Player::displayPlayer()
{
	this->characterClass->displayStatistics();
}






