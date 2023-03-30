//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../include/Tile.h"

//CONSTRUCTOR //DESTRUCTOR

Tile::Tile(const sf::Vector2f position, const std::string texture,
           const EntityTypes::Type type, const bool isPassable_)
{
	if (!this->setTexture(texture))
	{
		return;
	}
	this->type = type;
	this->isPassable_ = isPassable_;
	this->setPosition(position);
}

Tile::~Tile()
= default;

//FUNCTIONS

void Tile::setPosition(const sf::Vector2f position)
{
	this->tileSprite.setPosition(position);
}

bool Tile::setTexture(const std::string &textureName)
{
	if (!this->tileTexture.loadFromFile(this->pathManager.getAssetsPath() +
	                                    textureName))
	{
		return false;
	}
	this->tileTexture.setSmooth(true);
	this->tileSprite.setTexture(tileTexture);
	this->tileSprite.setTextureRect(
			sf::IntRect(0, 0, this->width, this->height));
	return true;
}

//GETTERS && SETTERS

void Tile::setTileSize(int x, int y)
{
	this->width = x;
	this->height = y;
	this->tileTexture.setRepeated(true);
	this->tileSprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

bool Tile::isPassable()
{
	return this->isPassable_;
}

sf::FloatRect Tile::getBounds()
{
	return this->tileSprite.getGlobalBounds();
}

sf::Vector2f Tile::getPosition()
{
	return this->tileSprite.getPosition();
}




