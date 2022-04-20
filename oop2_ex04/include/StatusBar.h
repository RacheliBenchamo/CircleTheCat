#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "macros.h"


class StatusBar
{
public:
	StatusBar();
	~StatusBar() {};

	void updateLevel(const bool);
	void updateClicks(const int);
	int getLevel() const;
	void setLevel(const int);
	void draw(sf::RenderWindow&, const int, const bool);
	void resetNumOfLevel();
	bool containsMusicIcon(const sf::Event&) const;
	bool containsRestartIcon(const sf::Event&) const;
	bool containsUndoIcon(const sf::Event&) const;
	void setMusicIcon(const bool);


private:
	void setCurrClicksText();
	void setLevelText();
	void setHeadlineText();
	void setButtons();
	void setMusicIcon();
	void setButtonLiner();
	void setRestartIcon();
	void setUndoIcon();

	
	int m_level;
	sf::RectangleShape m_buttonLiner;
	sf::Text m_currClicksText;
	sf::Text m_headlineText;
	sf::Text m_levelText;
	sf::Font m_font;

	sf::Sprite m_resetIcon;
	sf::Sprite m_undoIcon;
	sf::Sprite m_musicIcon;
};

