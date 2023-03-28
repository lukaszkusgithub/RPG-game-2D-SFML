//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../headers/GameMap.h"

//CONSTRUCTOR //DESTRUCTOR

GameMap::GameMap()
{
	this->gridLength = 40;
	this->gridLength -= 1;
	this->numberOfTrees = this->gridLength % this->tileSize * 10;
	this->numberOfEnemies = 25;
	this->numberOfNPC = 5;
}

GameMap::~GameMap()
{
	for (auto &tile : this->tiles) {
		delete tile;
	}
	this->tiles.clear();
}

//FUNCTIONS

void GameMap::initializeState()
{
	initializeSeed();
	initializeMapSize();
	setBackground();
	setMapBounds();
	setPlayerPosition();
	setBOSSPosition();
	setForestPositions();
	setWaterPositions();
	setNPCPosition();
	setEnemiesPositions();
	setTreePositions();
	setTiles();
}

//INITIALIZERS

void GameMap::initializeSeed(){
	this->seed = std::chrono::system_clock::now().time_since_epoch().count();
	this->generator.seed(this->seed);
}

void GameMap::initializeMapSize()
{
	this->mapSize.x = this->gridLength * tileSize;
	this->mapSize.y = this->gridLength * tileSize;
}

//WORLD CREATOR

void GameMap::setBackground()
{

	Tile *background  = new Tile(sf::Vector2f(0,0), "Grass.png",
	                             EntityTypes::Type::Neutral,
	                                   true);
	background->setTileSize(this->mapSize.x, this->mapSize.y);

	tiles.emplace_back(background);
}

void GameMap::setMapBounds() {
	sf::Vector2f position (0,0);
	for (int i = 0; i < this->gridLength+1; i++) {
		for (int j = 0; j < this->gridLength+1; j++) {
			if (i == 0 || i == this->gridLength)
			{
				this->boundsPosition.emplace_back(position);
				this->allPositions.emplace_back(std::make_pair(position,
				                                               "Bound"));
				position.x += 20;
			}
			else if (j == 0 || j == this->gridLength - 1)
			{
				this->boundsPosition.emplace_back(position);
				this->allPositions.emplace_back(std::make_pair(position,
				                                               "Bound"));
				position.x += this->mapSize.x;
			}
		}
		position.x = 0;
		position.y +=20;
	}
}

void GameMap::setEnemiesPositions()
{
	int numberOfUnits;

	getUnitsNumber(numberOfUnits, 10, numberOfEnemies);

//	this->enemyPositions.clear();

	this->generateUnit("Enemy", this->enemyPositions, numberOfUnits);
}

void GameMap::setPlayerPosition()
{
	int x = this->mapSize.x / 2.0 - ((int)this->mapSize.x / 2 % this->tileSize);
	int y = this->mapSize.y / 2.0 - ((int)this->mapSize.y / 2 % this->tileSize);
	this->playerPosition.x = x;
	this->playerPosition.y = y;
	this->allPositions.emplace_back(std::make_pair(this->playerPosition,
	                                               "Player"));
	sf::Vector2f pos;
	pos.y = this->playerPosition.y;
	for (int i = -1; i < 3; i++) {
		for (int j = -1; j < 2; j++) {
			pos.x = this->playerPosition.x + j * 20;
			this->allPositions.emplace_back(std::make_pair(pos,
			                                               "Player"));
		}
		pos.y =  this->playerPosition.y + i * 20;
	}
}

void GameMap::setNPCPosition()
{
	int numberOfUnits;

	getUnitsNumber(numberOfUnits, 3, numberOfNPC);

//	this->NPCPosition.clear();

	this->generateUnit("NPC", this->NPCPosition, numberOfUnits);
}

void GameMap::setBOSSPosition()
{
	sf::Vector2f position;
	bool isReserved;
	do
	{
		getUnitPosition(position);
		isReserved = tileIsReserved(position);
		this->BOSSPosition.x = position.x;
		this->BOSSPosition.y = position.y;
		this->allPositions.emplace_back(std::make_pair(position,
			                                               "BOSS"));
	}
	while (isReserved);

	sf::Vector2f pos;
	pos.y = this->BOSSPosition.y;
	for (int i = -1; i < 3; i++) {
		for (int j = -1; j < 2; j++) {
			pos.x = this->BOSSPosition.x + j * 20;
			this->allPositions.emplace_back(std::make_pair(pos,
			                                               "BOSS"));
		}
		pos.y =  this->BOSSPosition.y + i * 20;
	}
}

void GameMap::setTiles()
{

	for (auto &tilePosition : this->allPositions) {
		std::string texturePath = tilePosition.second + ".png";
		if (tilePosition.second == "Tree") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::Tree,
			                           false));
		}
		else if(tilePosition.second == "Water") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::Water,
			                           false));
		}
		else if(tilePosition.second == "NPC") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::NPC,
			                           true));
		}
		else if(tilePosition.second == "BOSS") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::BOSS,
			                           true));
		}
		else if(tilePosition.second == "Player") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::Player,
			                           true));
		}
		else if(tilePosition.second == "Enemy") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::Enemy,
			                           true));
		} else if(tilePosition.second == "Bound") {
			this->tiles.emplace_back(new Tile( tilePosition.first, texturePath,
			                                   EntityTypes::Type::Bound,
			                           false));
		}
	}
}

void GameMap::setTreePositions()
{
	int numberOfUnits;

	getUnitsNumber(numberOfUnits, 0, numberOfTrees);

//	this->treePositions.clear();

	this->generateUnit("Tree", this->treePositions, numberOfUnits);
}

void GameMap::setForestPositions()
{
	this->generateField("Tree", this->forestPositions);
}

void GameMap::setWaterPositions()
{
	this->generateField("Water", this->waterPositions);
}

void GameMap::generateUnit(std::string type, std::vector<sf::Vector2f>
        &container, int numberOfUnits) {
	for (int i = 0; i < numberOfUnits;) {
		sf::Vector2f position;
		getUnitPosition(position);
		bool isReserved = tileIsReserved(position);
		if (!isReserved)
		{
			container.emplace_back(position);
			this->allPositions.emplace_back(std::make_pair(position,
			                                               type));
			i++;
		}
	}
}

void GameMap::generateField(std::string type, std::vector<sf::Vector2f>
&container) {
	std::map<std::string, int> data;

	getStartPositionLands(data);

	float xPosition = data["x"];
	float yPosition = data["y"];

	sf::Vector2f position;

	for (int i = 0; i < data["rowsX"]; i++)
	{
		bool isReserved;
		position.x = xPosition;
		position.y = yPosition;
		isReserved = tileIsReserved(position);
		if (isReserved) {
			return;
		}
		for (int j = 0; j <= data["rowsY"]; j++)
		{
			position.x  = xPosition;
			isReserved = tileIsReserved(position);
			if (!isReserved)
			{
				container.emplace_back(
						sf::Vector2f(position));
				this->allPositions.emplace_back(std::make_pair(position,
				                                               type));
				xPosition += this->tileSize;
			}
			else
			{
				break;
			}
		}
		yPosition += this->tileSize;
		xPosition = data["x"];
	}
}

//AUXILIARY FNCTIONS

void GameMap::getStartPositionLands(std::map<std::string, int>& data) {
	std::uniform_int_distribution<int> rows(1, this->gridLength/2);
	std::uniform_int_distribution<int> position(this->tileSize, this->mapSize.x -
	this->tileSize);

	std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
	data["rowsX"] = rows(this->generator);
	data["rowsY"] = rows(this->generator);
	int x = position(this->generator);
	int y = position(this->generator);
	data["x"] = x - x % this->tileSize;
	data["y"] = y - y % this->tileSize;
}

void GameMap::getUnitsNumber(int & numberOfUnits, int min, int max) {
	std::uniform_int_distribution<int> numberOf(min, max);
	numberOfUnits = numberOf(this->generator);
}

void GameMap::getUnitPosition(sf::Vector2f & position) {
	std::uniform_int_distribution<int> pos(this->tileSize, this->mapSize.x -
	this->tileSize);
	int x = pos(this->generator);
	int y = pos(this->generator);
	position.x = x - x % this->tileSize;
	position.y = y - y % this->tileSize;
}

bool GameMap::tileIsReserved(sf::Vector2f position)
{
	auto pt = std::find_if(allPositions.begin(), allPositions.end(),
	                       [position](std::pair<sf::Vector2f, std::string> p) {
		                       return p.first == position;
	                       });
	return pt != allPositions.end();
}

int GameMap::getRandomNumber(const int min = 0, const int max = 2) {
	std::uniform_int_distribution<int> number(min, max);
	return number(this->generator);
}

bool GameMap::checkPositionIsPassable(sf::FloatRect characterNextBounds)
{
	float tileResize = 3.0;
	for (const auto &tile : tiles) {
		sf::FloatRect tileBounds = tile->getBounds();
		sf::FloatRect newTileBounds = {
			tileBounds.left + tileResize,
			tileBounds.top + tileResize,
			tileBounds.width -  2*tileResize,
			tileBounds.height - 2*tileResize
		};

		if(characterNextBounds.intersects(newTileBounds) == 1
		&& !tile->isPassable())
		{
			return false;
		}
	}
	return true;
}

//RENDER

void GameMap::renderMap(sf::RenderTexture &renderGameTexture)
{
	for (const auto &tile : tiles) {
		renderGameTexture.draw(tile->tileSprite);
	}
}

//GETTERS && SETTERS

sf::Vector2f GameMap::getPlayerPosition()
{
	return this->playerPosition;
}

std::vector<sf::Vector2f> GameMap::getEnemiesPosition()
{
	return this->enemyPositions;
}

std::vector<sf::Vector2f> GameMap::getNPCPosition()
{
	return this->NPCPosition;
}

sf::Vector2f GameMap::getBOSSPosition()
{
	return this->BOSSPosition;
}


