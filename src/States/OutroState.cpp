//
// Created by Łukasz Kus on 07/06/2021.
//

#include "../../include/States/OutroState.h"


//CONSTRUCTOR //DESTRUCTOR

OutroState::OutroState(StateData *stateData, bool value) : State(stateData)
{
	this->initializeSprite();
	this->loadFont();
	this->isWon = value;
	this->initializeBackground(this->windowSettings->getWindowSize());
	this->initializeText();
}


OutroState::~OutroState()
{
}

//FUNCTIONS

void OutroState::updateKeyBinds(const float &elapsed)
{
	this->checkEndStateLife();
}

void OutroState::renderState(sf::RenderTarget *renderTarget)
{
	if (this->endLife) return;
	if (!renderTarget)
	{
		renderTarget = this->renderWindow;
	}

	this->renderGameTexture.clear(sf::Color::Black);

	this->renderGameTexture.draw(this->background);

	this->renderGameTexture.draw(this->MenuText);

	this->renderGameTexture.display();

	renderTarget->draw(this->renderSprite);
}

void OutroState::updateState(const float &elapsed)
{
	this->updateKeyBinds(elapsed);
	this->updateMousePostion();
}

void OutroState::killState()
{
	this->endLife = true;
}

void OutroState::initializeSprite()
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

void OutroState::initializeBackground(sf::Vector2f windowSize)
{
	this->background.setSize(windowSize);
	this->background.setFillColor(this->backgroundColor);
}

void OutroState::loadFont()
{
	this->font.loadFromFile(this->pathManager.getButtonFont());
}

void OutroState::initializeText()
{
	if (this->isWon) {
		this->MenuText.setString("WYGRALES (Wcisnij ESC zeby wyjsc)");
	} else {
		this->MenuText.setString("PRZEGRALES (Wcisnij ESC zeby wyjsc)");
	}
	this->MenuText.setCharacterSize(this->windowSettings->getHeight() / 20);
	this->MenuText.setFillColor(this->textColor);
	this->MenuText.setFont(this->font);

	sf::Vector2f textPosition = {
			this->windowSettings->getWidth() / 2
			- this->MenuText.getGlobalBounds().width / 2,
			50
	};

	this->MenuText.setPosition(textPosition);
}

