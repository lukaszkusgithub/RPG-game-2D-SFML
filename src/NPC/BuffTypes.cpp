//
// Created by Łukasz Kus on 07/06/2021.
//

#include <iostream>
#include "../../include/NPC/BuffTypes.h"


BuffTypes::Buffs BuffTypes::getRandomBuff()
{
	int buffInt = rand() % BuffTypes::numberOfBuffs;
	switch (buffInt) {
		case 0:
			return BuffTypes::Buffs::health;
		case 1:
			return BuffTypes::Buffs::speed;
		case 2:
			return BuffTypes::Buffs::vision;
		case 3:
			return BuffTypes::Buffs::dodge;
		case 4:
			return BuffTypes::Buffs::critic;
		case 5:
			return BuffTypes::Buffs::AttackDPS;
	}
    return BuffTypes::Buffs::AttackDPS;
}

BuffTypes::DeBuffs BuffTypes::getRandomDeBuff()
{
	int buffInt = rand() % BuffTypes::numberOfDeBuffs;
	switch (buffInt) {
		case 0:
			return BuffTypes::DeBuffs::health;
		case 1:
			return BuffTypes::DeBuffs::speed;
		case 2:
			return BuffTypes::DeBuffs::vision;
		case 3:
			return BuffTypes::DeBuffs::dodge;
		case 4:
			return BuffTypes::DeBuffs::critic;
		case 5:
			return BuffTypes::DeBuffs::AttackDPS;
	}
    return BuffTypes::DeBuffs::health;
}



