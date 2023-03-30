//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_GAMESTATE_H
#define GAME_GAMESTATE_H

//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//LIBS
#include <iostream>
#include "sstream"

//CLASSES
#include "State.h"
#include "OutroState.h"
#include "FightState.h"
#include "../GameMap.h"
#include "../Player.h"
#include "../Enemies/Enemy.h"
#include "../Enemies/Eye.h"
#include "../Enemies/Goblin.h"
#include "../Enemies/Mushroom.h"
#include "../Enemies/Skeleton.h"
#include "../Enemies/BOSS.h"
#include "../NPC/NPC.h"
#include "../NPC/Hero.h"
#include "../NPC/StrongKnight.h"
#include "../NPC/Beast.h"

class GameState : public State
{
private:
		//VARIABLES

		GameMap GameMap;
		Player *player;
		sf::RenderTexture renderGameTexture;
		sf::View gameView;
		sf::Sprite renderSprite;
		std::vector<std::shared_ptr<Enemy>> enemies;
		std::vector<std::unique_ptr<NPC>> NPCs;
		std::shared_ptr<Enemy> boss;

		//DISPLAYING HUD
		std::string currentAlert;
		float alertDisplayTime = 2;
		float alertElapsedDisplayTime = 0;
		bool canBeAlertDisplay = true;
		sf::Vector2f gameViewPosition;

		bool endGame = false;


		//FUNCTIONS

		void initializePlayer();

		void initializeView();

		void initializeSprite();

		void initializeEnemies();

		void initializeHUD();

		void initializeNPCs();

		void initializeBOSS();

		void initializeHPIndicator();

		void initializeAlertText();

		void checkIsBOSSAlive();

		void checkIsPlayerAlive();

		void movePlayer(const float &elapsed, sf::Keyboard::Key key);

		void updateView();

		void updatePlayer(const float &elapsed);

		void updateEnemies(const float &elapsed);

		void updateNPCs(const float &elapsed);

		void updateBOSS(const float &elapsed);

		void displayAlert();

		void updateAlertText(const std::string &text);

		void updateAlert(const float &elapsed);

		void resetAlertDisplayTime();

		void updateGameViewPosition();

		void updateHPIndicatorPosition();

		void initializePlayerLevelText();

		void updatePlayerLevelText();

		void checkEnemyCollision();

		void checkNPCCollision();

		void checkBuffType(BuffTypes::Buffs buff);

		void updateViewSize();

		void checkDebuffType(BuffTypes::DeBuffs debuff);

		void initializeBossText();

		void checkBossCollision();

public:
		//CONSTRUCTOR //DESTRUCTOR

		explicit GameState(StateData *stateData);

		~GameState() override;

		//FUNCTIONS

		void killState() override;

		void updateKeyBinds(const float &elapsed) override;

		void updateState(const float &elapsed) override;

		void renderState(sf::RenderTarget *renderTarget) override;

		//STATIC

		template <class T>
		static std::string numberToString(T number);

		static bool getChance(int threshold);
};


#endif //GAME_GAMESTATE_H
