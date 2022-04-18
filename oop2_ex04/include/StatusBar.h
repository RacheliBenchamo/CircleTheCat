#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "macros.h"


class StatusBar
{
public:
	StatusBar();
	~StatusBar() {};

	void updateLevel(bool);
	int getLevel() const;
	void setLevel(int);
	void draw(sf::RenderWindow&);
	void resetNumOfLevel();
	bool containsMusicIcon(const sf::Event&) const;
	void setMusicIcon(bool);

private:
	void setCurrClicksText();
	void setLevelText();
	void setMusicIcon();



	
	int m_level;

	sf::Text m_currClicksText;
	sf::Text m_levelText;
	sf::Font m_font;

	sf::Sprite m_musicIcon;
};

