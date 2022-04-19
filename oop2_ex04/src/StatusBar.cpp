#pragma once
#include "StatusBar.h"
#include "FileManager.h"
#include <iostream>


//--------------------------------------------------
//constructor

StatusBar::StatusBar() : m_level(0)
{
	this->m_font = (*(FileManager::p2FileManager().getFont()));
	setHeadlineText();
	setCurrClicksText();
	setLevelText();
	setMusicIcon();
}
//------------------------------------------

void StatusBar::updateLevel(const bool isLevelUp)
{
	if (isLevelUp)
		this->m_level++;

	this->m_levelText.setString("Level :" + std::to_string(this->m_level));
}
//------------------------------------------
void StatusBar::updateClicks(const int numOfClicks)
{
	this->m_currClicksText.setString("Clicks :" + std::to_string(numOfClicks));
}
int StatusBar::getLevel() const
{
	return this->m_level;
}
//------------------------------------------

void StatusBar::setLevel(const int lev)
{
	this->m_level = lev;
}
//------------------------------------------
void StatusBar::draw(sf::RenderWindow& window, const int numOfClicks, const bool isLevelUp)
{
	updateClicks(numOfClicks);
	updateLevel(isLevelUp);

	window.draw(this->m_headlineText);
	window.draw(this->m_currClicksText);
	window.draw(this->m_levelText);
	window.draw(this->m_musicIcon);
}
//------------------------------------------

void StatusBar::resetNumOfLevel()
{
	m_level = 0;
}
//------------------------------------------

bool StatusBar::containsMusicIcon(const sf::Event& event) const
{
	if (this->m_musicIcon.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
		return true;
	return false;
}
//------------------------------------------

void StatusBar::setMusicIcon(const bool isSoundOn)
{
	this->m_musicIcon.setTexture(*FileManager::p2FileManager().getMusicIcon(isSoundOn));
}
//--------------------------------------------
void StatusBar::setHeadlineText()
{
	this->m_headlineText.setFont(*FileManager::p2FileManager().getFont());
	this->m_headlineText.setCharacterSize(STATUS_BAR_CHAR_SIZE-10);
	this->m_headlineText.setPosition(300, 0);
	this->m_headlineText.setColor(sf::Color(153, 153, 255, 255));
	this->m_headlineText.setOutlineColor(sf::Color::White);
	this->m_headlineText.setOutlineThickness(STATUS_BAR_OUTLINE_THICKNESS);
	this->m_headlineText.setString("Circle The Cat");
}
//--------------------------------------------

void StatusBar::setCurrClicksText()
{
	this->m_currClicksText.setFont(*FileManager::p2FileManager().getFont());
	this->m_currClicksText.setCharacterSize(STATUS_BAR_CHAR_SIZE);
	this->m_currClicksText.setPosition(650, BUFF_DISTANCE);
	this->m_currClicksText.setColor(sf::Color(153, 153, 255, 255));
	this->m_currClicksText.setOutlineColor(sf::Color(230, 230, 255, 255));
	this->m_currClicksText.setOutlineThickness(STATUS_BAR_OUTLINE_THICKNESS);

}
//--------------------------------------------

void StatusBar::setLevelText()
{
	this->m_levelText.setFont(*FileManager::p2FileManager().getFont());
	this->m_levelText.setCharacterSize(STATUS_BAR_CHAR_SIZE);
	this->m_levelText.setPosition(50, BUFF_DISTANCE);
	this->m_levelText.setColor(sf::Color(153, 153, 255, 255));
	this->m_levelText.setOutlineColor(sf::Color(230, 230, 255, 255));
	this->m_levelText.setOutlineThickness(STATUS_BAR_OUTLINE_THICKNESS);
}
//--------------------------------------------

void StatusBar::setMusicIcon()
{
	this->m_musicIcon.setTexture(*FileManager::p2FileManager().getMusicIcon(true));
	this->m_musicIcon.setPosition(WINDOW_WIDTH / 1.3,  BUFF_DISTANCE / 2);
	this->m_musicIcon.scale(MUSIC_ICON_SCALE);
}