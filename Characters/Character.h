//
// Created by Łukasz Kus on 11/05/2021.
//

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

//SFML LIBS
//#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

//LIBS
#include <utility>
#include <string>

//CLASSES
#include "../States/SettingsData.h"
#include "../headers/Animate.h"
#include "AttackTypes.h"
#include "../headers/Path.h"

class Character
{
protected:
	float characterSpeed_ = 200;
	float characterHealth_;
	float maximumCharacterHealth_;
	float attackDPS_;
	float dodgeChance_;
	float criticChance_;
	float characterLevel = 1;
	sf::Vector2f characterPosition_;
	sf::Vector2f characterNextPosition_;
	sf::Vector2f characterSize_;
	sf::Vector2f fieldOfView_;
	std::pair<std::string, std::string> characterDirection_;
	sf::FloatRect characterBounds_;
	sf::FloatRect characterNextBounds_;
	int width = 20;
	int height = 20;

	bool isAlive_ = true;

	std::vector<std::string> attacks;
	std::map<std::string, float> attacksCritRate;
	std::map<std::string, float> attacksDPS;

	SettingsData *windowSettings_;
	Path pathManager;
	Animate *animate;
	sf::Sprite characterSprite_;
	sf::Texture texture;
	EntityTypes::CharacterClass characterClass;

	float rightEdge = 0;
	float topEdge = 0;

	//CONSTRUCTOR //DESTRUCTOR

	Character(sf::Vector2f position, SettingsData *windowSettings);


public:
	//CONSTRUCTOR //DESTRUCTOR

	virtual ~Character();

	//FUNCTIONS

	void updatePosition();

	void getNextPosition(const float &seconds, const sf::Keyboard::Key key);

	void animateCharacter(const float &seconds);

	virtual void initializeStatistics() = 0;

	virtual void initializeCharacterClassType() = 0;

	virtual float getAttackDPS(int attackID) = 0;

	virtual float getAttackCritRate(int attackID) = 0;

	virtual std::string  getAttackName(int attackID) = 0;

	//CONTROL

	void moveUp(const float &seconds);

	void moveDown(const float &seconds);

	void moveRight(const float &seconds);

	void moveLeft(const float &seconds);

	void stopMove();

	void characterLevelUp();

	//GETTERS && SETTERS

	float characterSpeed();

	float characterHealth();

	float characterMaximumHealth();

	float characterDPS();

	sf::Vector2f characterPosition();

	sf::Vector2f characterNextPosition();

	sf::Vector2f characterSize();

	sf::Vector2f fieldOfView();

	std::pair<std::string, std::string> characterDirection();

	sf::Sprite characterSprite();

	sf::FloatRect characterNextBounds();

	bool isAlive();

	std::string getCurrentAnimation();

	void setFightPosition(sf::Vector2f position);

	void setCharacterPosition(sf::Vector2f position);

	void setIdleAnimation();

	void removeHealth(float dps);

	void setCharacterScale(float scale);

	sf::Vector2f getCharacterScale();

	void addDPS(const int &value);

	void addHealth(const int &value);

	void addSpeed(const int &value);

	void addVision(const int &value);

	void addDodge(const int &value);

	void addCritic(const int &value);

	void removeDPS(const int &value);

	void removeHealth(const int &value);

	void removeVision(const int &value);

	void removeSpeed(const int &value);

	void removeCritic(const int &value);

	void removeDodge(const int &value);

	void displayStatistics();
};


#endif //GAME_CHARACTER_H
