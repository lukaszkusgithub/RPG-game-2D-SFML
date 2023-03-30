//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../../include/States/GameState.h"


//CONSTRUCTOR //DESTRUCTOR

GameState::GameState(StateData *stateData) : State(stateData)
{
	this->initializeSprite();
	this->GameMap.initializeState();
	this->initializePlayer();
	this->initializeBOSS();
	this->initializeEnemies();
	this->initializeNPCs();
	this->initializeView();
	this->initializeHUD();
}

GameState::~GameState()
{
	delete this->player;
}

//FUNCTIONS

//STATE

void GameState::updateKeyBinds(const float &elapsed)
{
	this->checkEndStateLife();
}

void GameState::renderState(sf::RenderTarget *renderTarget)
{

	if (this->endLife) return;
	if (!renderTarget)
	{
		renderTarget = this->renderWindow;
	}

	this->renderGameTexture.clear(sf::Color::Black);

	this->renderGameTexture.setView(this->gameView);

	this->GameMap.renderMap(renderGameTexture);

	this->player->renderPlayer(renderGameTexture);

	this->boss->renderEnemy(renderGameTexture);

	for (const auto &enemy : this->enemies)
	{
		if (enemy->isAlive())
		{
			enemy->renderEnemy(renderGameTexture);
		}
	}

	for (const auto &NPC : this->NPCs) {
		NPC->renderNPC(renderGameTexture);
	}

	if (this->canBeAlertDisplay) {
		this->gui_->renderText(renderGameTexture, "ALERT");
	}

	this->gui_->renderHPIndicators(renderGameTexture);

	this->gui_->renderText(renderGameTexture, "LEVEL");

	this->gui_->renderText(renderGameTexture, "BOSS");

	this->renderGameTexture.display();

	renderTarget->draw(this->renderSprite);
}

void GameState::updateState(const float &elapsed)
{
	if (!this->player->isInFight())
	{
		this->checkIsPlayerAlive();
		this->checkIsBOSSAlive();
		this->updateKeyBinds(elapsed);
		this->updateView();
		this->updateHPIndicatorPosition();
		this->updatePlayerLevelText();
		this->updateAlert(elapsed);
		this->updatePlayer(elapsed);
		this->updateEnemies(elapsed);
		this->updateBOSS(elapsed);
		this->updateNPCs(elapsed);
	}
}

void GameState::killState()
{
	this->endLife = true;
}

//ELEMENTS

void GameState::initializeView()
{
	sf::Vector2f playerPosition = this->player->getPosition();
	this->gameView.reset(sf::FloatRect(playerPosition.x, playerPosition.y,
	                                   this->player->getFieldOfView().x,
	                                   this->player->getFieldOfView()
			                                   .y));

}

void GameState::initializePlayer()
{
	this->player = new Player(this->GameMap.getPlayerPosition(),
	                          this->windowSettings);
}

void GameState::initializeHUD()
{
	this->initializeAlertText();
	this->initializeHPIndicator();
	this->initializePlayerLevelText();
	this->initializeBossText();
}

void GameState::initializeBOSS()
{
	this->boss = std::make_unique<BOSS>(this->GameMap.getBOSSPosition(),
	                      this->windowSettings);
	this->boss->initStatistics();
}

void GameState::initializeSprite()
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

void GameState::initializeEnemies()
{
	for (auto position : this->GameMap.getEnemiesPosition())
	{
		int roll = GameMap.getRandomNumber(1, 4);
		switch (roll)
		{
			case 1:
				this->enemies.emplace_back(std::make_unique<Eye>(position,
				                                                 this->windowSettings));
				break;
			case 2:
				this->enemies.emplace_back(std::make_unique<Goblin>(position,
				                                                    this->windowSettings));
				break;
			case 3:
				this->enemies.emplace_back(std::make_unique<Mushroom>(position,
				                                                      this->windowSettings));
				break;
			case 4:
				this->enemies.emplace_back(std::make_unique<Skeleton>(position,
				                                                      this->windowSettings));
				break;
			default:
				break;
		}
	}
	for (const auto &enemy : this->enemies)
	{
		enemy->initStatistics();
	}
}

void GameState::initializeNPCs()
{
	for (auto position : this->GameMap.getNPCPosition()) {
		int roll = GameMap.getRandomNumber(1,3);
		switch (roll) {
			case 1:
				this->NPCs.emplace_back(std::make_unique<Hero>(position,
				                                               this->windowSettings));
				break;
			case 2:
				this->NPCs.emplace_back(std::make_unique<StrongKnight>(position,
				                                                       this->windowSettings));
				break;
			case 3:
				this->NPCs.emplace_back(std::make_unique<Beast>(position,
				                                                this->windowSettings));
				break;
			default:
				break;
		}
	}
}

void GameState::updateView()
{
	this->gameView.setCenter(this->player->getPosition());
}

void GameState::updatePlayer(const float &elapsed)
{

	this->player->updateAnimation(elapsed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::D)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::W)
	    || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->movePlayer(elapsed, sf::Keyboard::W);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->movePlayer(elapsed, sf::Keyboard::S);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->movePlayer(elapsed, sf::Keyboard::A);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->movePlayer(elapsed, sf::Keyboard::D);
		}
	}
	else
	{
		this->player->stopMove();
	}

}

void GameState::updateEnemies(const float &elapsed)
{
	for (const auto &enemy : this->enemies)
	{
		enemy->animateEnemy(elapsed);
	}
}

void GameState::updateNPCs(const float &elapsed)
{
	for (const auto &NPC : this->NPCs) {
		NPC->animateNPC(elapsed);
	}
}

void GameState::movePlayer(const float &elapsed, sf::Keyboard::Key key)
{
	this->player->setNextPosition(key, elapsed);
	if (!this->player->isInFight())
	{
		if (this->GameMap.checkPositionIsPassable
					(this->player->getNextBounds()))
		{
			this->player->updatePosition(key, elapsed);
		}
		else
		{
			this->player->stopMove();
		}
	}
	this->checkEnemyCollision();
	this->checkBossCollision();
	this->checkNPCCollision();
}

void GameState::checkEnemyCollision()
{
	for (const auto &enemy : this->enemies)
	{
		if (
				this->player->checkCollision(enemy->getBounds(),
				                             enemy->isAlive
						                             ())
				)
		{
			this->player->setFightState();
			this->player->savePlayerState();
			this->states->push(new FightState(this->stateData_, this->player,
			                                  enemy));
			this->resetAlertDisplayTime();
			this->updateAlertText("LEVEL UP");
		};
	}
}

void GameState::checkNPCCollision()
{
	for (const auto &NPC : this->NPCs)
	{
		if (
				this->player->checkCollision(NPC->getBounds(), NPC->isActive())
				)
		{
			if (getChance(70))
			{
				this->checkBuffType(NPC->getBuffs());
			} else {
				this->checkDebuffType(NPC->getDebuffs());
			}
			NPC->deactivateNPC();
		};
	}
}

void GameState::checkBossCollision()
{
	if (
			this->player->checkCollision(this->boss->getBounds(),
			                             this->boss->isAlive
					                             ())
			)
	{
		this->player->setFightState();
		this->player->savePlayerState();
		this->states->push(new FightState(this->stateData_, this->player,
		                                  this->boss));
	};

}

void GameState::checkBuffType(BuffTypes::Buffs buff)
{
	this->resetAlertDisplayTime();
	if(buff == BuffTypes::Buffs::AttackDPS)
	{
		this->player->addDPS(static_cast<int>(BuffTypes::Buffs::AttackDPS));
		this->updateAlertText("BONUS DPS!!");
	} else if (buff == BuffTypes::Buffs::critic) {
		this->player->addCritic(static_cast<int>(BuffTypes::Buffs::critic));
		this->updateAlertText("BONUS CR!!");
	} else if (buff == BuffTypes::Buffs::speed) {
		this->updateAlertText("FAST & FURIOUS");
		this->player->addSpeed(static_cast<int>(BuffTypes::Buffs::speed));
	} else if (buff == BuffTypes::Buffs::vision) {
		this->updateAlertText("NOTHING WILL HIDE");
		this->player->addVision(static_cast<int>(BuffTypes::Buffs::vision));
		this->updateViewSize();
	} else if (buff == BuffTypes::Buffs::dodge) {
		this->updateAlertText("AGILE AS FISH ><>");
		this->player->addDodge(static_cast<int>(BuffTypes::Buffs::dodge));
	} else if (buff == BuffTypes::Buffs::health) {
		this->updateAlertText("DOUBLE HP!");
		this->player->addHealth(static_cast<int>(BuffTypes::Buffs::health));
	}
}

void GameState::checkDebuffType(BuffTypes::DeBuffs debuff)
{
	this->resetAlertDisplayTime();
	if(debuff == BuffTypes::DeBuffs::AttackDPS)
	{
		this->player->removeDPS(static_cast<int>(BuffTypes::DeBuffs::AttackDPS));
		this->updateAlertText(":c");
	} else if (debuff == BuffTypes::DeBuffs::critic) {
		this->player->removeCritic(static_cast<int>(BuffTypes::DeBuffs::critic));
		this->updateAlertText("YOU ATTACK WEAKLY");
	} else if (debuff == BuffTypes::DeBuffs::speed) {
		this->updateAlertText("SLOW SLOW SLOW");
		this->player->removeSpeed(static_cast<int>(BuffTypes::DeBuffs::speed));
	} else if (debuff == BuffTypes::DeBuffs::vision) {
		this->updateAlertText("I CAN SEE IT DARK");
		this->player->removeVision(static_cast<int>(BuffTypes::DeBuffs::vision));
		this->updateViewSize();
	} else if (debuff == BuffTypes::DeBuffs::dodge) {
		this->updateAlertText("TURTLE");
		this->player->removeDodge(static_cast<int>(BuffTypes::DeBuffs::dodge));
	} else if (debuff == BuffTypes::DeBuffs::health) {
		this->updateAlertText("LOWER HP!");
		this->player->removeHealth(static_cast<int>(BuffTypes::DeBuffs::health));
	}
}

void GameState::updateBOSS(const float &elapsed)
{
	this->boss->animateEnemy(elapsed);
}

void GameState::checkIsBOSSAlive()
{
	if (!this->boss->isAlive() && !this->endGame) {
		this->endGame = true;
		this->killState();
		this->states->push(new OutroState(this->stateData_, this->player->isAlive()));
	}
}

void GameState::checkIsPlayerAlive()
{
	if (!this->player->isAlive() && !this->endGame)
	{
		this->endGame = true;
		this->killState();
		this->states->push(new OutroState(this->stateData_, this->player->isAlive()));
	}
}

void GameState::initializeAlertText()
{
	this->gui_->createText("WHITE", {0,0}, "VERYSMALL", "0", "ALERT", "CENTER",
			"CENTER");
	this->gui_->updateText("ALERT", "dobrej.zabawy");
}

void GameState::initializeBossText()
{

	this->gui_->createText("RED", {0,0}, "VERYSMALL", "0",
			"BOSS");
	sf::Vector2f textPosition = {
			this->GameMap.getBOSSPosition().x + 10,
			this->GameMap.getBOSSPosition().y + 20
	};
	this->gui_->updateTextPosition("BOSS", textPosition);
}

void GameState::updateAlertText(const std::string &text)
{
	if (this->currentAlert != text)
	{
		this->currentAlert = text;
		this->gui_->updateText("ALERT", text);
	}
}

void GameState::updateAlert(const float &elapsed)
{
	if(!this->canBeAlertDisplay) return;
	if (this->alertElapsedDisplayTime <= this->alertDisplayTime) {
		this->alertElapsedDisplayTime += elapsed;
		this->gui_->updateTextPosition("ALERT", this->player->getPosition(),
				"0", "50");
	} else {
		this->canBeAlertDisplay = false;
	}
}

void GameState::resetAlertDisplayTime()
{
	this->canBeAlertDisplay = true;
	this->alertElapsedDisplayTime = 0;
}

void GameState::initializeHPIndicator()
{
	this->updateGameViewPosition();
	this->gui_->createHPIndicator(this->gameViewPosition, "200",
			"10", "0", "Player");
	this->gui_->setCustomHPIndicatorSize("Player",
			this->player->getFieldOfView().x , 0, "", "10");
}

void GameState::updateGameViewPosition()
{
	this->gameViewPosition = {
			this->player->getPosition().x - this->player->getFieldOfView().x
			                                / 2,
			this->player->getPosition().y - this->player->getFieldOfView()
					                                .y / 2
	};
}

void GameState::updateHPIndicatorPosition()
{
	this->updateGameViewPosition();
	this->gui_->updateIndicator(this->player->getPercentOfHealth(), "Player");
	this->gui_->updateHPIndicatorPosition("Player", this->gameViewPosition);
}

void GameState::initializePlayerLevelText()
{
	this->gui_->createText("WHITE", {0,0}, "VERYSMALL", "0", "LEVEL", "CENTER",
	                       "CENTER");
	this->gui_->updateText("LEVEL", std::to_string(this->player->getPlayerLevel()));
}

void GameState::updatePlayerLevelText()
{
	sf::Vector2f textPosition = {
			this->player->getPosition().x,
			this->gameViewPosition.y + this->player->getFieldOfView().y,
	};

	this->gui_->updateTextPosition("LEVEL", textPosition, "", "20");
	this->gui_->updateText("LEVEL", GameState::numberToString<int>(this->player->getPlayerLevel()));
}

void GameState::updateViewSize()
{
	this->initializeView();
	this->updateView();
	this->gui_->setCustomHPIndicatorSize("Player",
	                                     this->player->getFieldOfView().x , 0, "", "10");
}
template<class T>
std::string GameState::numberToString(T number)
{
	std::string str;
	std::stringstream ss;
	ss << number;
	ss >> str;
	return str;
}



bool GameState::getChance(int threshold)
{
	if ((rand() % 100 + 1) <= threshold)
	{
		return true;
	}
	return  false;
}
















