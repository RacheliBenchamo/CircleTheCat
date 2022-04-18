#include "Board.h"
#include <iostream>
#include "FileManager.h"
#include "StatusBar.h"
#include <array>

class Controller
{
public:

	Controller();
	~Controller() {};

	void run();

private:
	void CheckOutWhatEvent( sf::Event );

	sf::RenderWindow m_window;
	sf::Sound m_backGroundMusic;
	sf::RectangleShape m_background;
	Board m_board;
	StatusBar m_statusBar;

	bool m_playButton;
	bool m_existFile = true;
	bool m_out = false;

};