//
// Created by Łukasz Kus on 06/06/2021.
//

#ifndef GAME_FIGHTSTATE_H
#define GAME_FIGHTSTATE_H

//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//LIBS
#include <iostream>

//CLASSES
#include "State.h"
#include "../headers/Player.h"
#include "../Characters/AttackTypes.h"
#include "../headers/Animate.h"
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

class FightState : public State
{
private:
	//VARIABLES
	Path pathManager;
	sf::RenderTexture renderGameTexture;
	sf::Sprite renderSprite;

	sf::Vector2f localSizeOfView = {800, 800};
	float scale = 4;

	float attackTime = 0;
	float attackMaxTime = 1;

	sf::Vector2f playerPositionBefore;
	sf::Vector2f enemyPositionBefore;

	std::shared_ptr<Enemy> enemy;
	Player *player;
	sf::View gameView;

	//FUNCTIONS
	void initializeSprite();

	void initializaGameView();

	void initializePlayer();

	void initializeEnemy();

	void initializeBackground();

	void initializeButtons();

	void initializeHPIndicators();

	void initializaPlayerToBeforeState();

	void updateHPIndicator(const std::string &name);

public:
	//CONSTRUCTOR //DESTRUCTOR
//	template <class Class>
	explicit FightState(StateData *stateData, Player *player,
	                    std::shared_ptr<Enemy> enemy);

	~FightState() override;

	void killState() override;

	void updateKeyBinds(const float &elapsed) override;

	void updateState(const float &elapsed) override;

	void renderState(sf::RenderTarget *renderTarget) override;

	void checkIsEndOfAnimation(const float &elapsed);

	void checkChoseButton(const float &elapsed);

	void attack(float dps, float critRate, const float &elapsed);

	float getAttackDamage(float dps, float critRate);

};


#endif //GAME_FIGHTSTATE_H
