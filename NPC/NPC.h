//
// Created by Łukasz Kus on 07/06/2021.
//

#ifndef GAME_NPC_H
#define GAME_NPC_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//CLASSES
#include "../States/SettingsData.h"
#include "../headers/Animate.h"
#include "../headers/Path.h"
#include "BuffTypes.h"

class NPC
{
protected:
		BuffTypes::Buffs buffType;
		BuffTypes::DeBuffs deBuffType;
		sf::Vector2f npcPosition_;
		int width = 20;
		int height = 20;

		bool isActive_ = true;

		SettingsData *windowSettings_;
		Path pathManager;
		Animate *animate;
		sf::Sprite npcSprite_;
		sf::Texture texture;
		EntityTypes::NPCs npcClass;

		//CONSTRUCTOR //DESTRUCTOR

		NPC(sf::Vector2f position, SettingsData *windowSettings);

public:
		//CONSTRUCTOR //DESTRUCTOR
		virtual ~NPC();

		//FUNCTIONS

		void animateNPC(const float &seconds);

		void renderNPC(sf::RenderTexture &renderGameTexture);
//	virtual void initStatistics() = 0;


		//GETTERS && SETTERS

		bool isActive();

		void deactivateNPC();

		sf::FloatRect getBounds();

		BuffTypes::Buffs getBuffs();
		BuffTypes::DeBuffs getDebuffs();

};


#endif //GAME_NPC_H
