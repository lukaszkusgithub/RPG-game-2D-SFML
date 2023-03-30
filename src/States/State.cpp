//
// Created by Łukasz Kus on 27/05/2021.
//

#include "../../include/States/State.h"

//CONSTRUCTOR //DESTRUCTOR


State::State(StateData *stateData)
{
	this->windowSettings = stateData->windowSettings;
	this->renderWindow = stateData->renderWindow;
	this->states = stateData->states;
	this->stateData_ = stateData;
	this->gui_ = new GUI(stateData->windowSettings->getWindowSize());
}

State::~State()
{
	delete this->gui_;
}

//FUNCTIONS

void State::checkEndStateLife()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->endLife = true;
	}
}

bool State::getEndLife() const
{
	return this->endLife;
}

void State::updateMousePostion()
{
	this->mousePositionPixel = sf::Mouse::getPosition();
	this->mousePositionWindow = sf::Mouse::getPosition(*this->renderWindow);
	this->mouseRect = {
			static_cast<float> (this->mousePositionWindow.x),
			static_cast<float>(this->mousePositionWindow.y), 10, 10
	};
	this->mouseRectPixel = {
			static_cast<float> (this->mousePositionPixel.x),
			static_cast<float>(this->mousePositionPixel.y), 10, 10
	};
}
