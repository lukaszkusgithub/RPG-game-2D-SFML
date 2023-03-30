//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <string>
#include <memory>


//CLASSES
#include "../include/Characters/Character.h"
#include "../include/Characters/Warrior.h"
#include "../include/Characters/Mage.h"
#include "../include/Characters/Archer.h"
#include "EntityTypes.h"
#include "../include/Enemies/Enemy.h"

class Player
{
private:
		//VARIABLES

		std::unique_ptr<Character> characterClass;

		bool isInFight_ = false;

		int playerLevel = 1;

		sf::Vector2f beforePosition;
		sf::Vector2f beforeScale;

		//FUNCTIONS

public:
		//CONSTRUCTOR //DESTRUCTOR

		Player(sf::Vector2f position, SettingsData *windowSettings);

		~Player();

		//FUNCTIONS

		void updatePosition(sf::Keyboard::Key, const float &elapsed);

		void updateAnimation(const float &elapsed);

		void chooseCharacterClass(const sf::Vector2f &position, SettingsData
		*windowSettings);

		void renderPlayer(sf::RenderTexture &renderGameTexture);

		bool checkCollision(sf::FloatRect bounds, bool isAlive);

		void stopMove();

		void setNextPosition(sf::Keyboard::Key, const float &elapsed);

		//GETTERS && SETTERS

		void setFightPosition(sf::Vector2f position);

		void setIdleAnimation();

		sf::Vector2f getPosition();

		sf::Vector2f getNextPosition();

		sf::FloatRect getNextBounds();

		sf::Vector2f getFieldOfView();

		std::string getCurrentAnmations();

		float getPlayerDPS();

		void removeHealth(float dps);

		void levelUp();

		float getAttackDPS(const int &attackID);

		float getAttackCritRate(const int &attackID);

		std::string getAttackName(const int &attackID);

		bool isAlive();

		bool isInFight();

		void setFightState();

		void removeFightState();

		void setScale(float scale);

		float getPercentOfHealth();

		void savePlayerState();

		void loadPlayerState();

		int getPlayerLevel();

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

		void displayPlayer();
};


#endif //GAME_PLAYER_H
