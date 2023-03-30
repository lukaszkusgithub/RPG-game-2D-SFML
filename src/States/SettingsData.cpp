//
// Created by Łukasz Kus on 28/05/2021.
//

#include "../../include/States/SettingsData.h"

//CONSTRUCTOR //DESTRUCTOR

SettingsData::SettingsData()
{
}

SettingsData::~SettingsData()
= default;

//GETTERS && SETTERS

float SettingsData::getWidth()
{
	return this->windowWidth;
}

float SettingsData::getHeight()
{
	return this->windowHeight;
}

sf::Vector2f SettingsData::getWindowSize()
{
	return sf::Vector2f(this->windowWidth, this->windowHeight);
}

float SettingsData::getFrameRate()
{
	return this->frameRate;
}

bool SettingsData::getVsyncSettings()
{
	return this->VSYNC;
}

EntityTypes::CharacterClass SettingsData::getCharacterClass()
{
	return this->characterClass_;
}


void SettingsData::setCharacterClass(EntityTypes::CharacterClass characterClass)
{
	this->characterClass_ = characterClass;
}

void SettingsData::setWidth(float x)
{
	this->windowWidth = x;
}

void SettingsData::setHeight(float y)
{
	this->windowHeight = y;
}

void SettingsData::setTitle(std::string title)
{
	this->gameTitle = title;
}

void SettingsData::setFramerate(int framerate)
{
	this->frameRate = framerate;
}

void SettingsData::setVSYNC(bool vsync)
{
	this->VSYNC = vsync;
}



