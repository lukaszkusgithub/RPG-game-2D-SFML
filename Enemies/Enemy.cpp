//
// Created by Łukasz Kus on 05/06/2021.
//

#include "Enemy.h"

//CONSTRUCTOR //DESTRUCTOR

Enemy::Enemy(sf::Vector2f position, SettingsData *windowSettings)
{
	this->enemySprite_.setPosition(position);
	this->windowSettings_ = windowSettings;

}

Enemy::~Enemy()
{
//    delete this->animate;
//    delete this->windowSettings_;
}

//FUNCTIONS

void Enemy::animateEnemy(const float &seconds)
{
	this->animate->runAnimation(this->enemySprite_, seconds);
	if (this->currentScale) {
			this->setEnemyScale(this->currentScale);
	}
}

void Enemy::renderEnemy(sf::RenderTexture &renderGameTexture)
{
	renderGameTexture.draw(this->enemySprite_);
}

//GETTERS && SETTERS

bool Enemy::isAlive()
{
	return this->isAlive_;
}

sf::FloatRect Enemy::getBounds()
{
	return this->enemySprite_.getGlobalBounds();
}

sf::Vector2f Enemy::getPosition()
{
	return this->enemySprite_.getPosition();
}

void Enemy::setPosition(sf::Vector2f position)
{
	position.x = position.x - this->enemySprite_.getGlobalBounds().height
	             - 50;
	position.y = position.y - this->enemySprite_.getGlobalBounds().height - 50;
	this->enemySprite_.setPosition(position);
}

void Enemy::removeHealt(int dps)
{
	srand(time(NULL));
	int chance = rand() % 100 + 1;

	if (this->dodgeChance_ <= chance)
	{
		this->health_ -= dps;
	}

	if (this->health_ <= 0)
	{
		this->isAlive_ = false;
	}
}

float Enemy::attack()
{
	srand(time(NULL));
	int chance = rand() % 100 + 1;
	if (this->criticChance_ <= chance)
	{
		return this->atackDPS_ * 2;
	}
	else
	{
		return this->atackDPS_;
	}
}

float Enemy::setEnemyScale(float scale)
{
	this->currentScale = scale;
	this->enemySprite_.setScale(scale, scale);
}

float Enemy::getPercentOfHealth()
{
	return this->health_ / this->maximumHealth_;
}
