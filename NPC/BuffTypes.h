//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_BUFFTYPES_H
#define GAME_BUFFTYPES_H

//LIBS
#include <string>
#include <cstdlib>


class BuffTypes
{
private:


public:
		static const int numberOfBuffs = 6;
		static const int numberOfDeBuffs = 6;

		enum class Buffs
		{
				health = 2,
				speed = 50,
				vision = 100,
				dodge = 5,
				critic = 10,
				AttackDPS = 1000,
		};

		enum class DeBuffs
		{
				health = 1500,
				speed = 20,
				vision = 50,
				dodge = 5,
				critic = 10,
				AttackDPS = 500,
		};

		static BuffTypes::Buffs getRandomBuff();

		static BuffTypes::DeBuffs getRandomDeBuff();

};


#endif //GAME_BUFFTYPES_H
