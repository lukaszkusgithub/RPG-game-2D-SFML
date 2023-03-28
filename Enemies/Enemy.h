//
// Created by Łukasz Kus on 05/06/2021.
//

#ifndef GAME_ENEMY_H
#define GAME_ENEMY_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//CLASSES
#include "../States/SettingsData.h"
#include "../headers/Animate.h"
#include "../headers/Path.h"

class Enemy
{
protected:
	float health_;
	float maximumHealth_;
	float atackDPS_;
	float dodgeChance_;
	float criticChance_;
	sf::Vector2f enemyPosition_;
	int width = 20;
	int height = 20;

	bool isAlive_ = true;

	float currentScale = 0 ;

	SettingsData *windowSettings_;
	Path pathManager;
	Animate *animate;
	sf::Sprite enemySprite_;
	sf::Texture texture;
	EntityTypes::Enemies enemyClass;

	//CONSTRUCTOR //DESTRUCTOR

	Enemy(sf::Vector2f position, SettingsData *windowSettings);

public:
	//CONSTRUCTOR //DESTRUCTOR
	virtual ~Enemy();

	//FUNCTIONS

	void animateEnemy(const float &seconds);

	void renderEnemy(sf::RenderTexture &renderGameTexture);

	virtual void initStatistics() = 0;


	//GETTERS && SETTERS

	void setPosition(sf::Vector2f position);


	bool isAlive();

	sf::FloatRect getBounds();

	sf::Vector2f getPosition();

	void removeHealt(int dps);

	float attack();

	void setEnemyScale(float scale);

	float getPercentOfHealth();

};


#endif //GAME_ENEMY_H
