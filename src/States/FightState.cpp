//
// Created by Łukasz Kus on 06/06/2021.
//

#include "../../include/States/FightState.h"

#include <utility>

//CONSTRUCTOR //DESTRUCTOR

//template <class Class>
FightState::FightState(StateData *stateData, Player *player,
                       std::shared_ptr<Enemy> enemy) :
		State
				(stateData)
{
	this->player = player;
	this->enemy = std::move(enemy);
	this->gui_ = new GUI(this->windowSettings->getWindowSize());
	this->initializeSprite();
	this->initializeBackground();
	this->initializaGameView();
	this->initializePlayer();
	this->initializeEnemy();
	this->initializeButtons();
	this->initializeHPIndicators();

}

FightState::~FightState()
{

}

//FUNCTIONS

void FightState::initializePlayer()
{
	this->player->displayPlayer();
	this->playerPositionBefore = this->player->getPosition();
	this->player->setScale(scale);
	this->player->setFightPosition({0,
	                                this->windowSettings->getHeight()});
	this->player->setIdleAnimation();
}

void FightState::initializeEnemy()
{
	this->enemyPositionBefore = this->enemy->getPosition();
	this->enemy->setEnemyScale(scale);
	this->enemy->setPosition({this->windowSettings->getWidth(),
	                          this->windowSettings->getHeight()});
}

void FightState::initializeSprite()
{
	this->renderGameTexture.create(
			this->windowSettings->getWidth(),
			this->windowSettings->getHeight()
	);

	this->renderSprite.setTexture(this->renderGameTexture.getTexture());
	this->renderSprite.setTextureRect(
			sf::IntRect(
					0,
					0,
					this->windowSettings->getWidth(),
					this->windowSettings->getHeight()
			)
	);
}

void FightState::initializeBackground()
{
	this->gui_->createBackground("GRAY");
	this->gui_->createBackgroundImage("FIGHT");
	this->gui_->scaleBackgroundImage("FIGHT", this->localSizeOfView.x,
	                                 this->localSizeOfView.y);
}

void FightState::killState()
{
	this->endLife = true;
}

void FightState::updateKeyBinds(const float &elapsed)
{
	this->checkEndStateLife();
}

void FightState::updateState(const float &elapsed)
{
	this->updateKeyBinds(elapsed);
	this->updateMousePostion();
	this->checkIsEndOfAnimation(elapsed);
	this->player->updateAnimation(elapsed);
	this->player->setScale(scale);
	this->enemy->animateEnemy(elapsed);
	this->enemy->setEnemyScale(scale);
	this->checkChoseButton(elapsed);
	if (this->attackTime != 0)
	{
		this->attackTime += elapsed;
	}
	if (this->attackMaxTime <= this->attackTime)
	{
		this->attackTime = 0;
	}

}

void FightState::renderState(sf::RenderTarget *renderTarget)
{
	if (this->endLife) return;
	if (!renderTarget)
	{
		renderTarget = this->renderWindow;
	}
	this->renderGameTexture.clear(sf::Color::Black);

	this->renderGameTexture.setView(this->gameView);

	this->gui_->renderBackground(this->renderGameTexture);
	this->gui_->renderBackgroundImage(this->renderGameTexture);

	this->gui_->renderButtons(this->renderGameTexture);

	this->gui_->renderHPIndicators(this->renderGameTexture);

	this->player->renderPlayer(this->renderGameTexture);

	this->enemy->renderEnemy(this->renderGameTexture);

	this->renderGameTexture.display();
	renderTarget->draw(this->renderSprite);
}

void FightState::checkIsEndOfAnimation(const float &elapsed)
{
//	this->seconds += elapsed;
//	if (this->seconds >= this->introTime)
//	{
//		this->seconds = 0;
//		this->killState();
//	}
}

void FightState::initializaGameView()
{
	this->gameView.reset(sf::FloatRect(0,
	                                   0, this->localSizeOfView.x,
	                                   this->localSizeOfView.y));
}

void FightState::initializeButtons()
{
	float positionY = 150;
	for (int i = 0; i < AttackTypes::numberOfSpecialAttacks; i++)
	{
		this->gui_->createButton("GRAY", {10, positionY}, "200", "75", "0",
		                         EntityTypes::CharacterClass::None,
		                         this->player->getAttackName(i),
		                         "SMALL",
		                         "WHITE", "", "", "", "",
		                         this->player->getAttackDPS(i),
		                         this->player->getAttackCritRate(i));
		positionY += 120;
	}
}

void FightState::checkChoseButton(const float &elapsed)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->gui_->checkButtonClick(this->mouseRect))
		{
			this->attack(this->gui_->getClickedButtonDPS(),
			             this->gui_->getClickedButtonCriticRate(), elapsed);
		}
	}
}

void FightState::attack(float dps, float critRate, const float &elapsed)
{
	if (this->attackTime == 0)
	{
		this->enemy->removeHealt(this->getAttackDamage(dps, critRate));
		this->updateHPIndicator("Enemy");
		if (!this->enemy->isAlive())
		{
			this->initializaPlayerToBeforeState();
			this->killState();
		}
		else
		{
			this->player->removeHealth(this->enemy->attack());
			this->updateHPIndicator("Player");
			if (!this->player->isAlive())
			{
				this->initializaPlayerToBeforeState();
				this->killState();
			}
		}
	}
	this->attackTime += elapsed;
}

void FightState::initializeHPIndicators()
{
	this->gui_->createHPIndicator({0, 0}, "300", "50", "0", "Player");
	this->gui_->createHPIndicator({500, 0}, "300", "50", "0", "Enemy");
	this->updateHPIndicator("Player");
}

void FightState::updateHPIndicator(const std::string &name)
{
	float percent = 0;
	if (name == "Player")
	{
		percent = this->player->getPercentOfHealth();
	}
	else if (name == "Enemy")
	{
		percent = this->enemy->getPercentOfHealth();
	}
	this->gui_->updateIndicator(percent, name);
}

void FightState::initializaPlayerToBeforeState()
{
	this->player->levelUp();
	this->player->loadPlayerState();
	this->player->removeFightState();
}

float FightState::getAttackDamage(float dps, float critRate)
{
	float attackDamage = 0;
	attackDamage += dps;
	attackDamage += this->player->getPlayerDPS();
	srand(time(NULL));
	int chance = rand() % 100 + 1;
	if (critRate <= chance)
	{
		attackDamage *= 2;
	}
	return attackDamage;
}

