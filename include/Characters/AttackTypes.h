//
// Created by Łukasz Kus on 20/06/2021.
//

#ifndef GAME_ATTACKTYPES_H
#define GAME_ATTACKTYPES_H

//LIBS
#include <vector>
#include <string>
#include <map>


class AttackTypes
{
public:
	static const int numberOfSpecialAttacks = 3;

	static std::vector<std::string> archerAttacks() {
		return  {"Fire Arrow", "Rain Of Arrows", "Double Arrow"};
	}

	static std::vector<std::string> warriorAttacks() {
		return {"Slash","Strong Hit", "Kick"};
	}

	static std::vector<std::string> mageAttacks() {
		return {"Fireball","FrozeBall", "WaterBall"};
	}


	static std::map<std::string, float> archerAttacksDPS () {
		std::map<std::string, float> container = {
				{"Fire Arrow", 800},
				{"Rain Of Arrows", 900},
				{"Double Arrow", 900},
		};
		return container;
	};

	static std::map<std::string, float> archerAttacksCritRate () {
		std::map<std::string, float> container =
		{
				{"Fire Arrow", 98},
				{"Rain Of Arrows", 10},
				{"Double Arrow", 50},
		};
		return container;
	};

	static std::map<std::string, float> warriorAttacksDPS () {
		std::map<std::string, float> container =
		{
				{"Slash", 1000},
				{"Strong Hit", 500},
				{"Kick", 600},
		};
		return container;
	};

	static std::map<std::string, float> warriorAttacksCritRate () {
		std::map<std::string, float> container =
		{
			{"Slash", 98},
			{"Strong Hit", 50},
			{"Kick", 70},
		};
		return container;
	};

	static std::map<std::string, float> MageAttacksDPS () {
		std::map<std::string, float> container =
		{
			{"Fireball", 1000},
			{"FrozeBall", 1500},
			{"WaterBall", 1700},
		};
		return container;
	};

	static std::map<std::string, float> MageAttacksCritRate () {
		std::map<std::string, float> container =
		{
				{"Fireball", 98},
				{"FrozeBall", 54},
				{"WaterBall", 0},
		};
		return container;
	};



};


#endif //GAME_ATTACKTYPES_H
