//
// Created by Łukasz Kus on 29/05/2021.
//

#include "../include/Animate.h"

//CONSTRUCTOR //DESTRUCTOR


Animate::Animate(EntityTypes::CharacterClass &type)
{
	this->initializeAnimations(type);
}

Animate::Animate(EntityTypes::Enemies &type)
{
	this->initializeAnimations(type);
}

Animate::Animate(EntityTypes::NPCs &type)
{
	this->initializeAnimations(type);
}

Animate::~Animate()
= default;

//FUNCTIONS

void Animate::getAnimationPath(EntityTypes::Enemies &type)
{
	if (type == EntityTypes::Enemies::Skeleton)
	{
		this->pathToAssets = pathManager.getEnemySkeletonPath();
	}
	else if (type == EntityTypes::Enemies::Eye)
	{
		this->pathToAssets = pathManager.getEnemyEyePath();
	}
	else if (type == EntityTypes::Enemies::Goblin)
	{
		this->pathToAssets = pathManager.getEnemyGoblinPath();
	}
	else if (type == EntityTypes::Enemies::Mushroom)
	{
		this->pathToAssets = pathManager.getEnemyMushroomPath();
	} else if (type == EntityTypes::Enemies::BOSS)
	{
		this->pathToAssets = pathManager.getBOSSESPath();
	}
}

void Animate::getAnimationPath(EntityTypes::CharacterClass
                               &type)
{
	if (type == EntityTypes::CharacterClass::Mage)
	{
		this->pathToAssets = pathManager.getHeroesMagePath();
	}
	else if (type == EntityTypes::CharacterClass::Warrior)
	{
		this->pathToAssets = pathManager.getHeroesWarriorPath();
	}
	else if (type == EntityTypes::CharacterClass::Archer)
	{
		this->pathToAssets = pathManager.getHeroesArcherPath();
	}
}

void Animate::getAnimationPath(EntityTypes::NPCs
                               &type)
{
	if (type == EntityTypes::NPCs::Hero)
	{
		this->pathToAssets = pathManager.getNPCHeroPath();
	}
	else if (type == EntityTypes::NPCs::Beast)
	{
		this->pathToAssets = pathManager.getNPCBeastPath();
	}
	else if (type == EntityTypes::NPCs::StrongKnight)
	{
		this->pathToAssets = pathManager.getNPCStrongKnightPath();
	}
}


bool Animate::loadImageSheet(const std::string &path)
{
	return this->sheet.loadFromFile(path);
}


void Animate::addFrames(const std::string &path, std::vector<sf::IntRect>
&container)
{
	bool loaded = this->loadImageSheet(path);
	if (loaded)
	{
		sf::Vector2u imageSize = this->sheet.getSize();
		unsigned int frames = imageSize.x / imageSize.y;
		int x = 0;
		for (int i = 0; i < frames; i++)
		{
			container.emplace_back(sf::IntRect(x, 0, imageSize.y, imageSize.y));
			x += imageSize.y;
		}
	}
}

void Animate::changeAnimation(sf::Sprite &sprite, const sf::Texture &texture)
{
	sprite.setTexture(texture);
	this->currentFrame = 0;
	this->animationFPS = this->typesOfAnimation[this->currentAnimation].size
			();
	sprite.setTextureRect
			(this->typesOfAnimation[this->currentAnimation][currentFrame]);
	sf::Vector2f scaleSize(20.0f / sprite.getLocalBounds().width, 20.0f /
	                                                              sprite.getLocalBounds().height);
	sprite.setScale(scaleSize);
}

void Animate::initializeAnimations(EntityTypes::CharacterClass &type)
{
//	typesOfAnimation["attack"];
	typesOfAnimation["idle"];
	typesOfAnimation["runLeft"];
	typesOfAnimation["runRight"];
	typesOfAnimation["runUp"];
	typesOfAnimation["runDown"];
//	typesOfAnimation["takeHit"];

	this->getAnimationPath(type);
	this->initializeAllTypesOfAnimations();
}

void Animate::initializeAnimations(EntityTypes::Enemies &type)
{
//	typesOfAnimation["attack"];
	typesOfAnimation["idle"];
//	typesOfAnimation["takeHit"];

	this->getAnimationPath(type);
	this->initializeAllTypesOfAnimations();
}

void Animate::initializeAnimations(EntityTypes::NPCs &type)
{
	typesOfAnimation["idle"];
	this->getAnimationPath(type);
	this->initializeAllTypesOfAnimations();
}

void Animate::initializeAllTypesOfAnimations()
{
	for (auto &animationType : this->typesOfAnimation)
	{
		std::string path = this->pathToAssets + animationType.first + ".png";
		sf::Texture texture = Animate::loadTexture(path);
		textures[animationType.first] = texture;
		addFrames(path, animationType.second);
	}
}


sf::Texture Animate::loadTexture(const std::string &path)
{
	sf::Texture texture;
	texture.loadFromFile(path);
	return texture;

}

void Animate::runRightAnimation(sf::Sprite &sprite)
{
	if (this->currentAnimation != "runRight")
	{
		this->currentAnimation = "runRight";
		this->changeAnimation(sprite, this->textures[this->currentAnimation]);
	}
}


void Animate::runLeftAnimation(sf::Sprite &sprite)
{
	if (this->currentAnimation != "runLeft")
	{
		this->currentAnimation = "runLeft";
		this->changeAnimation(sprite, this->textures[this->currentAnimation]);
	}
}

void Animate::runDownAnimation(sf::Sprite &sprite)
{
	if (this->currentAnimation != "runDown")
	{
		this->currentAnimation = "runDown";
		this->changeAnimation(sprite, this->textures[this->currentAnimation]);
	}
}

void Animate::runUpAnimation(sf::Sprite &sprite)
{
	if (this->currentAnimation != "runUp")
	{
		this->currentAnimation = "runUp";
		this->changeAnimation(sprite, this->textures[this->currentAnimation]);
	}
}

void Animate::idleAnimation(sf::Sprite &sprite)
{
	if (this->currentAnimation != "idle")
	{
		this->currentAnimation = "idle";
		this->changeAnimation(sprite, this->textures[this->currentAnimation]);
	}
}

void Animate::runAnimation(sf::Sprite &sprite, const float &seconds)
{
	this->changeFrame(sprite, seconds);
}

void Animate::changeFrame(sf::Sprite &sprite, const
float &seconds)
{
	this->time += seconds;
	if (this->time > (1.0 / this->animationFPS))
	{
		this->time = 0;
		this->currentFrame += 1;
		if (this->currentFrame >=
		    this->typesOfAnimation[this->currentAnimation].size
				    ())
		{
			currentFrame = 0;
		}
		sprite.setTextureRect(
				this->typesOfAnimation[this->currentAnimation][currentFrame]);
		sf::Vector2f scaleSize(20.0f / sprite.getLocalBounds().width, 20.0f /
		                                                              sprite.getLocalBounds().height);
		sprite.setScale(scaleSize);
	}
}

