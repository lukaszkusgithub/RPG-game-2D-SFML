//
// Created by Łukasz Kus on 29/05/2021.
//

#ifndef GAME_ENTITYTYPES_H
#define GAME_ENTITYTYPES_H


#include <type_traits>

class EntityTypes
{
public:
	EntityTypes();

	~EntityTypes();

	enum class Type {
		Enemy ,
		NPC,
		Water,
		BOSS,
		Neutral,
		Bound,
		Player,
		Tree,
	};

	enum class CharacterClass {
		Mage,
		Warrior,
		Archer,
		Last,
		First = Mage,
		None
	};

	enum class Enemies {
		Eye,
		Goblin,
		Mushroom,
		Skeleton,
		BOSS,
		First = Eye,
		Last = Skeleton,
	};

	enum class NPCs {
		Hero,
		StrongKnight,
		Beast,
	};

};


#endif //GAME_ENTITYTYPES_H
