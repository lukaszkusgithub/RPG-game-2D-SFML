//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../include/Path.h"

//CONSTRUCTOR //DESTRUCTOR

Path::Path()
= default;

Path::~Path()
= default;

//FUNCTIONS

std::string Path::getSettingsPath()
{
	return this->settingsPath;
}

std::string Path::getAssetsPath()
{
	return this->assetsPath;
}

std::string Path::getNPCPath()
{
	return this->npcPath;
}

std::string Path::getBOSSESPath()
{
	return this->bossesPath;
}

//ENEMIES

std::string Path::getEnemiesPath()
{
	return this->enemiesPath;
}

std::string Path::getEnemySkeletonPath()
{
	return this->enemiesPathSkeleton;
}

std::string Path::getEnemyEyePath()
{
	return this->enemiesPathEye;
}

std::string Path::getEnemyGoblinPath()
{
	return this->enemiesPathGoblin;
}

std::string Path::getEnemyMushroomPath()
{
	return this->enemiesPathMushroom;
}

//HEROES

std::string Path::getHeroesPath()
{
	return this->heroesPath;
}

std::string Path::getHeroesMagePath()
{
	return this->heroesPathMage;
}

std::string Path::getHeroesWarriorPath()
{
	return this->heroesPathWarrior;
}

std::string Path::getButtonFont()
{
	return this->buttonFont;
}

std::string Path::getHeroesArcherPath()
{
	return this->heroesPathArcher;
}

std::string Path::getNPCBeastPath()
{
	return this->npcPathBeast;
}

std::string Path::getNPCStrongKnightPath()
{
	return this->npcPathStrongKnight;
}

std::string Path::getNPCHeroPath()
{
	return this->npcPathHero;
}

std::string Path::getFightBackgroundImagePath()
{
	return backgroundImageFight;
}

std::string Path::getIntroBackgroundImagePath()
{
	return backgroundImageIntro;
}

std::string Path::getAudioMainTheme()
{
	return this->mainTheme;
}

