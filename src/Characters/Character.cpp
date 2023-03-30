//
// Created by Łukasz Kus on 11/05/2021.
//

#include "../../include/Characters/Character.h"

//CONSTRUCTOR //DESTRUCTOR

Character::Character(const sf::Vector2f position, SettingsData *windowSettings) : characterPosition_
(position), windowSettings_(windowSettings){
	this->characterSprite_.setPosition(position);

}

Character::~Character()
{
  delete this->animate;
}


//FUNCTIONS


void Character::updatePosition()
{
	this->characterPosition_ = this->characterSprite_.getPosition();
}

// CONTROL

void Character::moveUp(const float &seconds) {
	this->characterBounds_ = this->characterSprite_.getGlobalBounds();
	if (this->characterBounds_.top >= this->topEdge) {
		this->characterSprite_.move(0, -this->characterSpeed() * seconds);
	}
	this->animate->runUpAnimation(this->characterSprite_);
}

void Character::moveDown(const float &seconds) {
	this->characterBounds_ = this->characterSprite_.getGlobalBounds();
	if (this->characterBounds_.top <= this->windowSettings_->getHeight() - this->characterBounds_
			.height) {
		this->characterSprite_.move(0, this->characterSpeed() * seconds);
	}
	this->animate->runDownAnimation(this->characterSprite_);

}

void Character::moveRight(const float &seconds) {
	this->characterBounds_ = this->characterSprite_.getGlobalBounds();
	if (this->characterBounds_.left <= this->windowSettings_->getWidth() - this->characterBounds_.width) {
		this->characterSprite_.move(this->characterSpeed() * seconds, 0);
	}
	this->animate->runRightAnimation(this->characterSprite_);
}

void Character::moveLeft(const float &seconds) {
	this->characterBounds_ = this->characterSprite_.getGlobalBounds();
	if (this->characterBounds_.left >= this->rightEdge) {
		this->characterSprite_.move(-this->characterSpeed() * seconds, 0);
	}
	this->animate->runLeftAnimation(this->characterSprite_);
}


void
Character::getNextPosition(const float &seconds, const sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::A)
	{
		this->characterNextPosition_ = sf::Vector2f
				(this->characterPosition_.x + (-this->characterSpeed() *
				                               seconds),
				 this->characterPosition_.y);
	}
	else if (key == sf::Keyboard::D)
	{
		this->characterNextPosition_ = sf::Vector2f
				(this->characterPosition_.x + (this->characterSpeed() *
				                               seconds),
				 this->characterPosition_.y);
	}
	else if (key == sf::Keyboard::W)
	{
		this->characterNextPosition_ = sf::Vector2f
				(this->characterPosition_.x, this->characterPosition_.y + (
						-this->characterSpeed() * seconds));
	}
	else if (key == sf::Keyboard::S)
	{
		this->characterNextPosition_ = sf::Vector2f
				(this->characterPosition_.x, this->characterPosition_.y +
				                             (this->characterSpeed() * seconds));
	}

	this->characterNextBounds_ = sf::FloatRect{
		this->characterNextPosition_.x,
		this->characterNextPosition_.y,
		float(this->width),
		float(this->height)
	};
}

void Character::stopMove()
{
	this->animate->idleAnimation(this->characterSprite_);
}


void Character::animateCharacter(const float &seconds)
{
	this->animate->runAnimation(this->characterSprite_, seconds);
}

//GETTERS && SETTERS

float Character::characterSpeed()
{
	return this->characterSpeed_;
}

float Character::characterHealth()
{
	return  this->characterHealth_;
}

sf::Vector2f Character::characterPosition()
{
	return this->characterPosition_;
}

sf::Vector2f Character::characterSize()
{
	return this->characterSize_;
}

std::pair<std::string, std::string> Character::characterDirection()
{
	return this->characterDirection_;
}

sf::Sprite Character::characterSprite()
{
	return this->characterSprite_;
}

sf::Vector2f Character::characterNextPosition()
{
	return this->characterNextPosition_;
}

sf::FloatRect Character::characterNextBounds()
{
	return this->characterNextBounds_;
}

sf::Vector2f Character::fieldOfView()
{
	return this->fieldOfView_;
}

void Character::setFightPosition(sf::Vector2f position)
{
	position.y = position.y - this->characterSprite_.getGlobalBounds().height
			- 50;
	this->characterSprite_.setPosition(position);
}

void Character::setIdleAnimation()
{
	this->animate->idleAnimation(this->characterSprite_);
}

std::string Character::getCurrentAnimation()
{
	return this->animate->currentAnimation;
}

float Character::characterDPS()
{
	return this->attackDPS_;
}

void Character::removeHealth(float dps)
{
	srand (time(NULL));
	int chance = rand() % 100 + 1;

	if (this->dodgeChance_ <= chance) {
		this->characterHealth_ -= dps;
	}
	if (this->characterHealth_ <= 0) {
		this->isAlive_ = false;
	}

}

bool Character::isAlive()
{
	return this->isAlive_;
}

void Character::characterLevelUp()
{
	if ( this->characterLevel < 2)
	{
		this->characterLevel += 0.1;

		if (this->characterHealth_ < 350000)
		{
			float addHealth = (this->maximumCharacterHealth_ *
			                   this->characterLevel) -
			                  this->maximumCharacterHealth_;

			this->characterHealth_ += addHealth;
			this->maximumCharacterHealth_ += addHealth;
		}

		this->attackDPS_ *= this->characterLevel;

		if (this->dodgeChance_ < 100)
		{
			this->dodgeChance_ +=
					this->dodgeChance_ * this->characterLevel / 10;
		}
		else
		{
			this->dodgeChance_ = 100;
		}

		if (this->criticChance_ < 100)
		{
			this->criticChance_ +=
					this->criticChance_ * this->characterLevel / 10;
		}
		else
		{
			this->criticChance_ = 100;
		}
	}
}

void Character::setCharacterScale(float scale)
{
	this->characterSprite_.setScale(scale, scale);
}

float Character::characterMaximumHealth()
{
	return this->maximumCharacterHealth_;
}

sf::Vector2f Character::getCharacterScale()
{
	return this->characterSprite_.getScale();
}

void Character::setCharacterPosition(sf::Vector2f position)
{
	this->characterSprite_.setPosition(position);
}

void Character::addDPS(const int &value)
{
	this->attackDPS_ += value;
}

void Character::addHealth(const int &value)
{
	this->maximumCharacterHealth_ *= value;
	this->characterHealth_ *= value;
}

void Character::addSpeed(const int &value)
{
	this->characterSpeed_ += value;
}

void Character::addVision(const int &value)
{
	this->fieldOfView_.x += value;
	this->fieldOfView_.y += value;
}

void Character::addDodge(const int &value)
{
	if (this->dodgeChance_ < 100 + + value) {
		this->dodgeChance_ += value;
	} else {
		this->dodgeChance_ = 100;
	}
}

void Character::addCritic(const int &value)
{
	if (this->criticChance_ < 100 + value) {
		this->criticChance_ += value;
	} else {
		this->criticChance_ = 100;
	}
}

void Character::removeDPS(const int &value)
{
	if (this->attackDPS_ > 100 + value)
	{
		this->attackDPS_ -= value;
	}
}

void Character::removeHealth(const int &value)
{
	this->characterHealth_ /= value;
	this->maximumCharacterHealth_ /= value;
}

void Character::removeVision(const int &value)
{
	if (this->fieldOfView_.x > 100 + value)
	{
		this->fieldOfView_.x -= value;
		this->fieldOfView_.y -= value;
	}
}

void Character::removeSpeed(const int &value)
{
	if ((this->characterSpeed_) > 50 + value)
	{
		this->characterSpeed_ -= value;
	}
}

void Character::removeCritic(const int &value)
{
	if ((this->criticChance_) > value)
	{
		this->criticChance_ -= value;
	}
}

void Character::removeDodge(const int &value)
{
	if ((this->dodgeChance_) > value)
	{
		this->dodgeChance_ -= value;
	}
}

void Character::displayStatistics()
{
	std::cout <<
	"\nHP: " << this->characterHealth() <<
  "\nDPS: " << this->characterDPS() <<
  "\nDODGE: " << this->dodgeChance_  <<
  "\nCRITC: " <<  this->criticChance_ <<
  "\nmaxHP: " << this->maximumCharacterHealth_  << std::endl;
}




