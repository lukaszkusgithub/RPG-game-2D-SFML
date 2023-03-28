//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_TILE_H
#define GAME_TILE_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <string>
#include <iostream>

//CLASSES
#include "Path.h"
#include "EntityTypes.h"

class Tile
{
private:
		//VARIABLES
		sf::Texture tileTexture;
		EntityTypes::Type type;
		bool isPassable_;
		bool isEnd;
		Path pathManager;
		int width = 20;
		int height = 20;


public:
		//VARIABLES
		sf::Sprite tileSprite;

		//CONSTRUCTOR //DESTRUCTOR

		Tile(sf::Vector2f position, std::string texture, EntityTypes::Type, bool);

		~Tile();

		//FUNCTIONS

		void setPosition(sf::Vector2f position);

		bool setTexture(const std::string &textureName);

		//GETTERS && SETTERS
		void setTileSize(int x, int y);

		bool isPassable();

		sf::FloatRect getBounds();

		sf::Vector2f getPosition();

};


#endif //GAME_TILE_H
