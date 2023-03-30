//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_PATH_H
#define GAME_PATH_H

//LIBS
#include <string>

class Path
{
private:
	std::string settingsPath = "config/settings.ini";
	std::string assetsPath = "assets/Textures/PNG/";

	//ENEMIES
	std::string enemiesPath = "assets/Textures/ENEMIES/";
	std::string enemiesPathSkeleton = "assets/Textures/ENEMIES/skeleton/";
	std::string enemiesPathEye = "assets/Textures/ENEMIES/eye/";
	std::string enemiesPathGoblin = "assets/Textures/ENEMIES/goblin/";
	std::string enemiesPathMushroom = "assets/Textures/ENEMIES/mushroom/";

	//HEROES
	std::string heroesPath = "assets/Textures/HEROES/";
	std::string heroesPathMage = "assets/Textures/HEROES/mage/";
	std::string heroesPathWarrior = "assets/Textures/HEROES/warrior/";
	std::string heroesPathArcher = "assets/Textures/HEROES/archer/";

	//NPC
	std::string npcPath = "assets/Textures/NPC/";
	std::string npcPathHero = "assets/Textures/NPC/hero/";
	std::string npcPathStrongKnight = "assets/Textures/NPC/strongknight/";
	std::string npcPathBeast = "assets/Textures/NPC/beast/";


	std::string bossesPath = "assets/Textures/ENEMIES/boss/";

	std::string buttonFont = "assets/Fonts/arial.ttf";

	//BACKGROUND BACKGROUNDS
	std::string backgroundImageIntro = "assets/Textures/BACKGROUNDS/intro"
	                                   ".png";
	std::string backgroundImageFight = "assets/Textures/BACKGROUNDS/fight"
	                                   ".png";

	//AUDIO

		std::string mainTheme = "assets/AUDIO/mainTheme.wav";

public:
	//CONSTRUCTOR //DESTRUCTOR

	Path();

	~Path();

	//FUNCTIONS

	std::string getSettingsPath();

	std::string getAssetsPath();

	std::string getBOSSESPath();

	//ENEMIES
	std::string getEnemiesPath();

	std::string getEnemySkeletonPath();

	std::string getEnemyEyePath();

	std::string getEnemyGoblinPath();

	std::string getEnemyMushroomPath();

	//HEROES
	std::string getHeroesPath();

	std::string getHeroesMagePath();

	std::string getHeroesWarriorPath();

	std::string getHeroesArcherPath();

	//NPC
	std::string getNPCPath();

	std::string getNPCBeastPath();

	std::string getNPCHeroPath();

	std::string getNPCStrongKnightPath();

	//FONTS
	std::string getButtonFont();

	//BACKGROUND BACKGROUNDS
	std::string getIntroBackgroundImagePath();

	std::string getFightBackgroundImagePath();

	//AUDIO

	std::string getAudioMainTheme();

};


#endif //GAME_PATH_H
