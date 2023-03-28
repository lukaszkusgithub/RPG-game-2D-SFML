//
// Created by Łukasz Kus on 27/05/2021.
//

#include "ClassMenuState.h"


//CONSTRUCTOR //DESTRUCTOR

ClassMenuState::ClassMenuState(StateData *stateData) : State(stateData)
{
	this->gui_ = new GUI(this->windowSettings->getWindowSize());

	this->initializeSprite();
	this->initializeBackground();
	this->initializeButtons();
	this->initializeText();
}


ClassMenuState::~ClassMenuState()
{
}

//FUNCTIONS

void ClassMenuState::initializeBackground()
{
	this->gui_->createBackground("GRAY");
}


void ClassMenuState::updateKeyBinds(const float &elapsed)
{
	this->checkEndStateLife();
}

void ClassMenuState::renderState(sf::RenderTarget *renderTarget)
{
	if (this->endLife) return;
	if (!renderTarget)
	{
		renderTarget = this->renderWindow;
	}
//
	this->renderGameTexture.clear(sf::Color::Black);

	this->gui_->renderBackground(this->renderGameTexture);
	this->gui_->renderButtons(this->renderGameTexture);
	this->gui_->renderTexts(this->renderGameTexture);

	this->renderGameTexture.display();
//
	renderTarget->draw(this->renderSprite);
}

void ClassMenuState::updateState(const float &elapsed)
{
	this->updateKeyBinds(elapsed);
	this->updateMousePostion();
	this->checkChoseButton();
}

void ClassMenuState::killState()
{
	this->endLife = true;
}

void ClassMenuState::initializeSprite()
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

void ClassMenuState::initializeText()
{
	this->gui_->createText("WHITE", {0, 0}, "LARGE", "10", "Choose your class",
	                       "CENTER");
}


void ClassMenuState::initializeButtons()
{


	this->gui_->createButton("GRAY", {0, 0}, "200", "100", "200",
	                         EntityTypes::CharacterClass::Warrior, "Warrior",
	                         "MEDIUM",
	                         "WHITE", "CENTER");
	this->gui_->createButton("GRAY", {0, 0}, "200", "100", "50",
	                         EntityTypes::CharacterClass::Mage, "Mage",
	                         "MEDIUM",
	                         "WHITE", "", "", "Warrior");
	this->gui_->createButton("GRAY", {0, 0}, "200", "100", "50",
	                         EntityTypes::CharacterClass::Archer, "Archer",
	                         "MEDIUM",
	                         "WHITE", "", "", "Mage");

}


void ClassMenuState::checkChoseButton()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->gui_->checkButtonClick(mouseRect))
		{
			this->windowSettings->setCharacterClass
					(this->gui_->getClickedButtonSpecialValue());
			this->killState();
			this->states->push(new GameState(this->stateData_));
		}
	}
}





