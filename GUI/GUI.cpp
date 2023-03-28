//
// Created by Łukasz Kus on 15/06/2021.
//

#include <iostream>
#include "GUI.h"


//CONSTRUCTOR //DESTRUCTOR

GUI::GUI(sf::Vector2f windowSize)
{
	this->windowSize = windowSize;
	this->initializeColors();
	this->initializeFonts();
	this->initializeButtonSizes();
	this->initializePositions();
	this->initializeImages();
}

GUI::~GUI()
= default;

//FUNCTIONS

void GUI::initializeColors()
{
	//BUTTONS
	this->buttonColors["GRAY"] = sf::Color({80, 80, 80});
	this->buttonColors["RED"] = sf::Color({255, 0, 0});
	this->buttonColors["GREEN"] = sf::Color({0, 255, 0});
	this->buttonColors["BLUE"] = sf::Color({0, 0, 255});

	//TEXT
	this->textColors["WHITE"] = sf::Color({255, 255, 255});

	//BACKGROUND
	this->backgroundColors["GRAY"] = sf::Color({128, 128, 128});

}

void GUI::initializeFonts()
{
	this->fontSize["LARGE"] = this->windowSize.x / 10;
	this->fontSize["MEDIUM"] = this->windowSize.x / 20;
	this->fontSize["SMALL"] = this->windowSize.x / 40;
	this->fontSize["ULTRASMALL"] = this->windowSize.x / 70;
	this->fontSize["VERYSMALL"] = this->windowSize.x / 55;
	this->loadFont();
}

void GUI::loadFont()
{
	this->font.loadFromFile(this->pathManager.getButtonFont());
}

void GUI::initializePositions()
{
	this->positionsX["CENTER"] = this->windowSize.x / 2;
	this->positionsX["LEFT"] = 0;
	this->positionsX["RIGHT"] = this->windowSize.x;

	this->positionsY["CENTER"] = this->windowSize.y / 2;
	this->positionsY["BOTTOM"] = this->windowSize.y;
	this->positionsY["TOP"] = 0;

	this->margins["0"] = 0;
	this->margins["10"] = 10;
	this->margins["20"] = 20;
	this->margins["30"] = 30;
	this->margins["40"] = 40;
	this->margins["50"] = 50;
	this->margins["100"] = 100;
	this->margins["150"] = 150;
	this->margins["200"] = 200;
}

void GUI::initializeButtonSizes()
{
	this->buttonSizes["5"] = 5;
	this->buttonSizes["10"] = 10;
	this->buttonSizes["15"] = 15;
	this->buttonSizes["20"] = 20;
	this->buttonSizes["25"] = 25;
	this->buttonSizes["50"] = 50;
	this->buttonSizes["75"] = 75;
	this->buttonSizes["100"] = 100;
	this->buttonSizes["200"] = 200;
	this->buttonSizes["300"] = 300;
	this->buttonSizes["400"] = 400;
	this->buttonSizes["500"] = 500;
}

void GUI::initializeImages()
{
	this->images["INTRO"] = this->pathManager.getIntroBackgroundImagePath();
	this->images["FIGHT"] = this->pathManager.getFightBackgroundImagePath();
}

void
GUI::createButton(const std::string& color, sf::Vector2f position,
                  const std::string& sizeX, const std::string& sizeY, const std::string& margin,
                  EntityTypes::CharacterClass characterClass,
                  const std::string& text, const std::string& textSize, const std::string& textColor,
                  const std::string& xAxis, const std::string& yAxis,
                  const std::string& elementAbove, const std::string& elementBelow, float
                  dps, float critRate)
{
	sf::RectangleShape button;
	button.setSize({this->buttonSizes[sizeX], this->buttonSizes[sizeY]});
	button.setFillColor(this->buttonColors[color]);
	button.setPosition(position);

	sf::Text textElement;

	if (xAxis.length() > 1)
	{
		if (xAxis == "CENTER")
		{
			button.setPosition(this->positionsX[xAxis] - button
					                                             .getGlobalBounds().width /
			                                             2, button
					                                                .getPosition().y +
			                                                this->margins[margin]);
		}
		else
		{
			button.setPosition(this->positionsX[xAxis] + this->margins[margin],
			                   button
					                   .getPosition().y +
			                   this->margins[margin]);
		};
	}

	if (yAxis.length() > 1)
	{
		if (yAxis == "CENTER")
		{
			button.setPosition(button.getPosition().x + this->margins[margin],
			                   this->positionsX[yAxis] -
			                   button.getGlobalBounds().height
			                   / 2);
		}
		else
		{
			button.setPosition(button.getPosition().x + this->margins[margin],
			                   this->positionsX[yAxis] + this->margins[margin]);
		};
	}

	if (elementAbove.length() > 1)
	{
		sf::FloatRect elementAboveBounds = std::get<2>
				(this->BUTTONS[elementAbove])
				.getGlobalBounds();
		sf::Vector2f pos;
		pos.x = elementAboveBounds.left;


		pos.y = elementAboveBounds.top
		        + elementAboveBounds.height
		        + this->margins[margin];

		button.setPosition(pos);
	}

	if (elementBelow.length() > 1)
	{
		sf::FloatRect elementBelowBounds = std::get<2>
				(this->BUTTONS[elementBelow])
				.getGlobalBounds();
		sf::Vector2f pos;
		pos.x = elementBelowBounds.top
		        - elementBelowBounds.height
		        - this->margins[margin];

		pos.y = elementBelowBounds.left;

		button.setPosition(pos);
	}


	if (text.length() > 1)
	{

		textElement.setString(text);
		textElement.setFont(this->font);
		textElement.setFillColor(this->textColors[textColor]);
		textElement.setCharacterSize(this->fontSize[textSize]);
		textElement.setPosition(button.getGlobalBounds().left + button
				                                                        .getGlobalBounds().width /
		                                                        2 -
		                        textElement.getGlobalBounds().width / 2,
		                        button
				                        .getGlobalBounds().top +
		                        button.getGlobalBounds().height / 2 -
		                        textElement.getGlobalBounds().height);
		this->TEXTS[text] = textElement;
	}

	this->BUTTONS[text] = std::make_tuple(characterClass, textElement,
	                                      button, dps, critRate);

}

void
GUI::createText(const std::string& color, sf::Vector2f position, const std::string& size,
                const std::string& margin, const std::string& text, const std::string& xAxis,
                const std::string& yAxis)
{
	sf::Text textElement;
	textElement.setString(text);
	textElement.setFillColor(this->textColors[color]);
	textElement.setCharacterSize(this->fontSize[size]);
	textElement.setPosition(position);
	textElement.setFont(this->font);
	if (xAxis.length() > 0)
	{
		if (xAxis == "CENTER")
		{
			textElement.setPosition(this->positionsX[xAxis] - textElement
					                                                  .getGlobalBounds().width /
			                                                  2,
			                        textElement
					                        .getPosition().y);
		}
		else
		{
			textElement.setPosition(this->positionsX[xAxis],
			                        textElement.getPosition().y);
		}
	}

	if (yAxis.length() > 0)
	{
		if (yAxis == "CENTER")
		{
			textElement.setPosition(textElement.getPosition().x,
			                        this->positionsX[yAxis] -
			                        textElement.getGlobalBounds()
					                        .height / 2);
		}
		else
		{
			textElement.setPosition(textElement.getPosition().x,
			                        this->positionsX[yAxis]);
		}
	}

	textElement.setPosition(textElement.getPosition().x + this->margins[margin],
	                        textElement.getPosition().y +
	                        this->margins[margin]);

	this->TEXTS[text] = textElement;
}


void GUI::createBackground(const std::string& color)
{
	this->BACKGROUND.setSize(this->windowSize);
	this->BACKGROUND.setFillColor(this->backgroundColors[color]);
}

//SETTERS && GETTERS

void GUI::addButtonColor(const std::string &name, sf::Color color)
{
	this->backgroundColors[name] = color;
}

void GUI::addBackgroundColor(const std::string &name, sf::Color color)
{
	this->buttonColors[name] = color;

}

void GUI::addTextColor(const std::string &name, sf::Color color)
{
	this->textColors[name] = color;
}

void GUI::addFontSize(const std::string &name, int size)
{
	this->fontSize[name] = size;
}

sf::RectangleShape GUI::getButton(const std::string& name)
{
	return std::get<2>(this->BUTTONS[name]);
}

sf::Text GUI::getText(const std::string& name)
{
	return this->TEXTS[name];
}

sf::FloatRect GUI::getButtonBounds(const std::string& name)
{
	return std::get<2>(this->BUTTONS[name]).getGlobalBounds();
}

std::vector<sf::FloatRect> GUI::getAllButtonsBounds(const std::string& name)
{
	std::vector<sf::FloatRect> bounds;
	for (const auto &button : BUTTONS)
	{
		bounds.emplace_back(std::get<2>(this->BUTTONS[button.first])
				                    .getGlobalBounds());
	}
	return bounds;
}

bool GUI::checkButtonClick(const sf::FloatRect mouseRect)
{
	for (const auto &button : BUTTONS)
	{
		sf::FloatRect bounds = std::get<2>(this->BUTTONS[button.first])
				.getGlobalBounds();
		if (mouseRect.intersects(bounds) == 1)
		{
			this->lastClickedButton = button.first;
			return true;
		}
	}
	return false;
}

EntityTypes::CharacterClass GUI::getClickedButtonSpecialValue()
{
	return std::get<0>(this->BUTTONS[this->lastClickedButton]);
}

void GUI::renderButtons(sf::RenderTexture &renderGameTexture)
{
	for (const auto &button : this->BUTTONS)
	{
		renderGameTexture.draw(std::get<2>(this->BUTTONS[button.first]));
		renderGameTexture.draw(std::get<1>(this->BUTTONS[button.first]));
	}
}

void GUI::renderBackground(sf::RenderTexture &renderGameTexture)
{
	renderGameTexture.draw(this->BACKGROUND);
}

void GUI::renderTexts(sf::RenderTexture &renderGameTexture)
{
	for (const auto &text : this->TEXTS)
	{
		renderGameTexture.draw(text.second);
	}
}

void GUI::renderBackgroundImage(sf::RenderTexture &renderGameTexture)
{
	renderGameTexture.draw(this->backgroundImageShape);
};

void GUI::createBackgroundImage(const std::string& name)
{

	if (!this->backgroundImageTexture.loadFromFile(this->images[name]))
	{
		return;
	}

	sf::Image originalImage;
	if (!originalImage.loadFromFile(this->images[name]))
		return;

	sf::Vector2u sizeOfImage = originalImage.getSize();

	float scaleX = this->windowSize.x / sizeOfImage.x;
	float scaleY = this->windowSize.y / sizeOfImage.y;


	this->backgroundImageShape.setTexture(backgroundImageTexture);
	this->backgroundImageShape.setPosition(0, 0);
	this->backgroundImageShape.setScale(scaleX, scaleY);
}

void GUI::scaleBackgroundImage(const std::string& name, float x, float y)
{
	sf::Image originalImage;
	if (!originalImage.loadFromFile(this->images[name]))
		return;

	sf::Vector2u sizeOfImage = originalImage.getSize();

	float scaleX = x / sizeOfImage.x;
	float scaleY = y / sizeOfImage.y;

	this->backgroundImageShape.setScale(scaleX, scaleY);
}

float GUI::getClickedButtonDPS()
{
	return std::get<3>(this->BUTTONS[this->lastClickedButton]);
}

float GUI::getClickedButtonCriticRate()
{
	return std::get<4>(this->BUTTONS[this->lastClickedButton]);

}

void
GUI::createHPIndicator(sf::Vector2f position, const std::string& sizeX,
                       const std::string& sizeY,
                       const std::string& margin, const std::string& name)
{
	sf::RectangleShape indicator;
	sf::RectangleShape bgc;
	indicator.setSize({this->buttonSizes[sizeX], this->buttonSizes[sizeY]});
	indicator.setFillColor(this->buttonColors["RED"]);
	indicator.setPosition(position);
	bgc.setSize({this->buttonSizes[sizeX], this->buttonSizes[sizeY]});
	bgc.setFillColor(this->buttonColors["GRAY"]);
	bgc.setPosition(position);

	this->HPINDICATORS[name] = std::make_tuple(indicator, bgc);
}

void GUI::renderHPIndicators(sf::RenderTexture &renderGameTexture)
{
	for (const auto &indicator : this->HPINDICATORS)
	{
		renderGameTexture.draw(
				std::get<1>(this->HPINDICATORS[indicator.first]));
		renderGameTexture.draw(std::get<0>(this->HPINDICATORS[indicator
				.first]));
	}
}

void GUI::updateIndicator(float percent, const std::string &name)
{
	sf::Vector2f size = std::get<1>(this->HPINDICATORS[name]).getSize();
	size.x *= percent;
	std::get<0>(this->HPINDICATORS[name]).setSize(size);
}

void GUI::updateText(const std::string &name, const std::string &text)
{
	this->TEXTS[name].setString(text);
}

void GUI::renderText(sf::RenderTexture &renderGameTexture, const std::string
		&name)
{
	renderGameTexture.draw(this->TEXTS[name]);
}

void GUI::updateTextPosition(const std::string &name, sf::Vector2f position,
                             const std::string &marginX, const std::string
                             &marginY)
{
	sf::Vector2f centerPosition =
	{
		position.x - this->TEXTS[name].getGlobalBounds().width / 2,
		position.y
	};
	if (marginX.length() > 1) {
		centerPosition.x -= this->margins[marginX];
	}
	if (marginY.length() > 1) {
		centerPosition.y -= this->margins[marginY];
	}

	this->TEXTS[name].setPosition(centerPosition);
}

void GUI::setCustomButtonSize(const std::string& name, float sizeXCustom,
		float sizeYCustom, const std::string &sizeX, const std::string &sizeY)
{

	sf::Vector2f size = {sizeXCustom , sizeYCustom};

	if (sizeX.length() > 1) {
		size.x = this->buttonSizes[sizeX];
	}
	if (sizeY.length() > 1) {
		size.x = this->buttonSizes[sizeY];
	}

	std::get<2>(this->BUTTONS[name]).setSize(size);
}

void GUI::setCustomHPIndicatorSize(const std::string& name, float sizeXCustom,
                              float sizeYCustom, const std::string &sizeX, const std::string &sizeY)
{

	sf::Vector2f size = {sizeXCustom , sizeYCustom};

	if (sizeX.length() > 1) {
		size.x = this->buttonSizes[sizeX];
	}
	if (sizeY.length() > 1) {
		size.y = this->buttonSizes[sizeY];
	}

	std::get<0>(this->HPINDICATORS[name]).setSize(size);
	std::get<1>(this->HPINDICATORS[name]).setSize(size);
}

void
GUI::updateHPIndicatorPosition(const std::string &name, sf::Vector2f position)
{
	std::get<0>(this->HPINDICATORS[name]).setPosition(position);
	std::get<1>(this->HPINDICATORS[name]).setPosition(position);
}


































