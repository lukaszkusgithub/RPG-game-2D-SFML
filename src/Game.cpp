//
// Created by Łukasz Kus on 12/05/2021.
//

#include "../headers/Game.h"


//CONSTRUCTOR //DESTRUCTOR

Game::Game()
{
	this->initializeGameWindow();
	this->initializeGameStateData();
	this->initializeGameStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

//FUNCTIONS

void Game::loadSettings(std::map<std::string, int>
                        &settingsData)
{

	std::string settingsText;

	std::fstream settingsFile(this->pathManager.getSettingsPath());

	if (settingsFile.is_open())
	{
		std::stringstream str;
		str << settingsFile.rdbuf();
		settingsText = str.str();
	}
	settingsFile.close();

	std::regex settingsRegex(R"((\w*)=(\d*))");
	std::smatch match;
	while (regex_search(settingsText, match, settingsRegex))
	{
		settingsData[match[1]] = std::stoi(match[2]);
		settingsText = match.suffix();
	}
}

void Game::initializeGameWindow()
{
	std::map<std::string, int> settingsData;
	std::string gameTitle = "Knigghto";
	loadSettings(settingsData);

	this->window = new sf::RenderWindow(sf::VideoMode(settingsData["width"],
	                                                  settingsData["width"]),
	                                    gameTitle);
	this->window->setVerticalSyncEnabled(settingsData["frame_rate"]);
	this->window->setFramerateLimit(settingsData["vsync"]);

	this->windowSettings.setWidth(this->window->getSize().x);
	this->windowSettings.setHeight(this->window->getSize().y);
	this->windowSettings.setFramerate(settingsData["frame_rate"]);
	this->windowSettings.setTitle(gameTitle);
	this->windowSettings.setVSYNC(settingsData["vsync"]);

}

void Game::runGame()
{
	while (this->window->isOpen())
	{
		updateTime();
		updateEvents();
		updateGame();
		renderGame();
	}
}

void Game::closeGame()
{
	std::cout << "Close game";
}

void Game::updateGame()
{
	if (!this->states.empty())
	{
		this->states.top()->updateState(this->elapsed.asSeconds());
		if (this->states.top()->getEndLife())
		{
      this->states.top()->killState();
			delete this->states.top();
			this->states.pop();
		}
	} else if (this->states.empty())
	{
		this->closeGame();
		this->window->close();
	}
}

void Game::updateEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
		{
			std::cout << "asd";
			this->window->close();
		}
	}
}

void Game::updateTime()
{
	this->elapsed = this->clock.restart();
}

void Game::initializeGameStates()
{
	this->states.emplace(new IntroState(&this->stateData));
}

void Game::initializeGameStateData()
{
	this->stateData.renderWindow = this->window;
	this->stateData.states = &this->states;
	this->stateData.windowSettings = &this->windowSettings;
}

void Game::renderGame()
{
	this->window->clear();

	if (!this->states.empty())
	{
		this->states.top()->renderState(this->window);
	}

	this->window->display();
}


