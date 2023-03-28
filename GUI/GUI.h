//
// Created by Łukasz Kus on 15/06/2021.
//

#ifndef GAME_GUI_H
#define GAME_GUI_H

//SFML LIBS
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//CLASSES
#include "../headers/EntityTypes.h"
#include "../Characters/AttackTypes.h"
#include "../headers/Path.h"

class GUI
{
private:
	sf::RectangleShape BACKGROUND;
	std::map<std::string, std::tuple<EntityTypes::CharacterClass, sf::Text,
			sf::RectangleShape, float, float>> BUTTONS;

	std::map<std::string, std::tuple<sf::RectangleShape, sf::RectangleShape>> HPINDICATORS;


	sf::Texture backgroundImageTexture;
	sf::Sprite backgroundImageShape;

	std::string lastClickedButton;

	sf::Vector2f windowSize;

	Path pathManager;

	//COLORS
	std::map<std::string, sf::Color> buttonColors;
	std::map<std::string, sf::Color> backgroundColors;
	std::map<std::string, sf::Color> textColors;

	std::map<std::string, std::string> images;


	void initializeColors();

	void addButtonColor(const std::string &name, sf::Color color);

	void addBackgroundColor(const std::string &name, sf::Color color);

	void addTextColor(const std::string &name, sf::Color color);

	//FONTS
	std::map<std::string, sf::Text> TEXTS;
	std::map<std::string, float> fontSize;
	sf::Font font;

	void initializeFonts();

	void loadFont();

	void addFontSize(const std::string &name, int size);

	//POSITIONS
	std::map<std::string, float> positionsX;
	std::map<std::string, float> positionsY;

	std::map<std::string, float> margins;

	void initializePositions();


	//BUTTONSIZE
	std::map<std::string, float> buttonSizes;

	void initializeButtonSizes();

	void initializeImages();


protected:


public:

	//CONSTRUCTOR //DESTRUCTOR

	GUI(sf::Vector2f windowSize);

	~GUI();

	//FUNCTIONS

	void createBackground(const std::string& color);

	void createBackgroundImage(const std::string& name);

	void createButton(
			const std::string& color,
			sf::Vector2f position,
			const std::string& sizeX,
			const std::string& sizeY,
			const std::string& margin,
			EntityTypes::CharacterClass characterClass
			= EntityTypes::CharacterClass::None,
			const std::string& text = "",
			const std::string& textSize = "",
			const std::string& textColor = "",
			const std::string& xAxis = "",
			const std::string& yAxis = "",
			const std::string& elementAbove = "",
			const std::string& elementBelow = "",
			float dps = 0,
			float critRate = 0
	);

	void createHPIndicator(
			sf::Vector2f position,
			const std::string& sizeX,
			const std::string& sizeY,
			const std::string& margin,
			const std::string& name
	);


	void createText(
			const std::string& color,
			sf::Vector2f position,
			const std::string& size,
			const std::string& margin,
			const std::string& text,
			const std::string& xAxis = "",
			const std::string& yAxis = ""
	);


	sf::RectangleShape getButton(const std::string& name);

	sf::Text getText(const std::string& name);

	sf::FloatRect getButtonBounds(const std::string& name);

	std::vector<sf::FloatRect> getAllButtonsBounds(const std::string& name);

	bool checkButtonClick(sf::FloatRect mouseRect);

	EntityTypes::CharacterClass getClickedButtonSpecialValue();

	void renderButtons(sf::RenderTexture &renderGameTexture);

	void renderHPIndicators(sf::RenderTexture &renderGameTexture);

	void renderTexts(sf::RenderTexture &renderGameTexture);

	void renderBackground(sf::RenderTexture &renderGameTexture);

	void renderBackgroundImage(sf::RenderTexture &renderGameTexture);

	void renderText(sf::RenderTexture &renderGameTexture, const std::string
	&name);

	void scaleBackgroundImage(const std::string& name, float x, float y);

	float getClickedButtonDPS();

	float getClickedButtonCriticRate();

	void updateIndicator(float percent, const std::string &name);

	void updateText(const std::string &name, const std::string &text);

	void updateTextPosition(const std::string &name, sf::Vector2f position,
			const std::string &marginX = "", const std::string &marginY = "");

	void setCustomButtonSize(
			const std::string& name,
			float sizeXCustom = 0,
			float sizeYCustom = 0,
			const std::string& sizeX = "",
			const std::string& sizeY = ""
	);

	void setCustomHPIndicatorSize(
			const std::string& name,
			float sizeXCustom = 0,
			float sizeYCustom = 0,
			const std::string& sizeX = "",
			const std::string& sizeY = ""
	);

	void updateHPIndicatorPosition(const std::string& name, sf::Vector2f
	position);

};


#endif //GAME_GUI_H
