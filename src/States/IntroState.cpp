//
// Created by Łukasz Kus on 06/06/2021.
//

#include "../../include/States/IntroState.h"

IntroState::IntroState(StateData *stateData) : State(stateData)
{
	this->gui_ = new GUI(this->windowSettings->getWindowSize());
	this->initializeSprite();
	this->initializeBackground();
}

IntroState::~IntroState()
= default;

void IntroState::killState()
{
	this->endLife = true;
}

void IntroState::updateKeyBinds(const float &elapsed)
{
	this->checkEndStateLife();
}

void IntroState::updateState(const float &elapsed)
{
	this->updateKeyBinds(elapsed);
	this->updateMousePostion();
	this->checkIsEndOfAnimation(elapsed);
}

void IntroState::renderState(sf::RenderTarget *renderTarget)
{
	if (this->endLife) return;
	if (!renderTarget)
	{
		renderTarget = this->renderWindow;
	}
	this->renderGameTexture.clear(sf::Color::Black);

	this->gui_->renderBackground(this->renderGameTexture);
	this->gui_->renderBackgroundImage(this->renderGameTexture);

	this->renderGameTexture.display();
	renderTarget->draw(this->renderSprite);
}

void IntroState::initializeSprite()
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

void IntroState::initializeBackground()
{
	this->gui_->createBackground("GRAY");
	this->gui_->createBackgroundImage("INTRO");
}

void IntroState::checkIsEndOfAnimation(const float &elapsed)
{
	this->seconds += elapsed;
	if (this->seconds >= this->introTime)
	{
		this->seconds = 0;
		this->states->push(new ClassMenuState(this->stateData_));
		this->killState();
	}
}