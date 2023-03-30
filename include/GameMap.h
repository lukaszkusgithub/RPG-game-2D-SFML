//
// Created by Łukasz Kus on 12/05/2021.
//

#ifndef GAME_GAMEMAP_H
#define GAME_GAMEMAP_H

//SFML LIBS
#include <SFML/Graphics.hpp>

//LIBS
#include <vector>
#include <random>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>
#include <chrono>

//CLASSES
#include "Tile.h"

class GameMap
{
private:
	//VARIABLES

	std::vector<Tile *> tiles;

	sf::Vector2f playerPosition;
	sf::Vector2f BOSSPosition;

	std::vector<sf::Vector2f> boundsPosition;
	std::vector<sf::Vector2f> enemyPositions;
	std::vector<sf::Vector2f> NPCPosition;
	std::vector<sf::Vector2f> forestPositions;
	std::vector<sf::Vector2f> waterPositions;
	std::vector<sf::Vector2f> treePositions;
	std::vector<std::pair<sf::Vector2f, std::string>> allPositions;
	sf::Vector2f mapSize;

	int gridLength;
	int tileSize = 20;

	int numberOfTrees;
	int numberOfEnemies;
	int numberOfNPC;

	unsigned seed{};
	std::default_random_engine generator;


	//FUNCTIONS

	void initializeSeed();

	void initializeMapSize();

	void setMapBounds();

	void setEnemiesPositions();

	void setPlayerPosition();

	void setNPCPosition();

	void setBOSSPosition();

	void setBackground();

	void setTiles();

	void setTreePositions();

	void setForestPositions();

	void setWaterPositions();

	void getStartPositionLands(std::map<std::string, int> &data);

	void getUnitsNumber(int &numberOfUnits, int min, int max);

	void getUnitPosition(sf::Vector2f &position);

	bool tileIsReserved(sf::Vector2f position);

	void generateField(std::string type, std::vector<sf::Vector2f> &container);

	void generateUnit(std::string type, std::vector<sf::Vector2f> &container,
	                  int numberOfUnits);


public:
	//CONSTRUCTOR //DESTRUCTOR

	GameMap();

	~GameMap();

	//FUNCTIONS

	void initializeState();

	void renderMap(sf::RenderTexture &renderGameTexture);

	bool checkPositionIsPassable(sf::FloatRect nextPosition);

	int getRandomNumber(int min, int max);

	//GETTERS && SETTERS

	sf::Vector2f getPlayerPosition();

	std::vector<sf::Vector2f> getEnemiesPosition();

	std::vector<sf::Vector2f> getNPCPosition();

	sf::Vector2f getBOSSPosition();


};


#endif //GAME_GAMEMAP_H
