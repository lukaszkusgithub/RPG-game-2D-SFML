//
// Created by Łukasz Kus on 29/05/2021.
//

#ifndef GAME_ANIMATE_H
#define GAME_ANIMATE_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <vector>
#include <type_traits>
#include <map>
#include <iostream>

//CLASSES
#include "EntityTypes.h"
#include "Path.h"

class Animate
{
private:
	//VARIABLES

//	std::vector<sf::IntRect> idleFrames;
//	std::vector<sf::IntRect> attackFrames;
//	std::vector<sf::IntRect> walkFrames;
//	std::vector<sf::IntRect> takeHitFrames;
//	std::vector<sf::IntRect> currentFramesSet;

	std::map<std::string, std::vector<sf::IntRect>> typesOfAnimation;
	std::map<std::string, sf::Texture> textures;

	std::string pathToAssets;

	sf::Image sheet;


	int currentFrame;
	int animationFPS = 8;
	float time = 0;

	Path pathManager;

	//FUNCTIONS
	void changeAnimation(sf::Sprite &sprite, const sf::Texture &texture);

	void changeFrame(sf::Sprite &sprite, const float &seconds);

	bool loadImageSheet(const std::string &path);

	static sf::Texture loadTexture(const std::string &path);

	void addFrames(const std::string &path, std::vector<sf::IntRect>
	&container);

	void getAnimationPath(EntityTypes::CharacterClass &type);

	void getAnimationPath(EntityTypes::Enemies &type);

	void getAnimationPath(EntityTypes::NPCs &type);

	void initializeAnimations(EntityTypes::CharacterClass &type);

	void initializeAnimations(EntityTypes::Enemies &type);

	void initializeAnimations(EntityTypes::NPCs &type);

	void initializeAllTypesOfAnimations();

public:
	std::string currentAnimation;

	//CONSTRUCTOR //DESTRUCTOR

	explicit Animate(EntityTypes::CharacterClass &type);

	explicit Animate(EntityTypes::Enemies &type);

	explicit Animate(EntityTypes::NPCs &type);

	~Animate();

	//FUNCTIONS

	void idleAnimation(sf::Sprite &sprite);

	void runRightAnimation(sf::Sprite &sprite);

	void runLeftAnimation(sf::Sprite &sprite);

	void runDownAnimation(sf::Sprite &sprite);

	void runUpAnimation(sf::Sprite &sprite);

	void attackAnimation();

	void walkAnimation();

	void takeHitAnimation();

	void runAnimation(sf::Sprite &sprite, const float &seconds);


};


#endif //GAME_ANIMATE_H
