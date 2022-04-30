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
	void handelMouseButtonReleased(sf::Event);
	void handelMusicButtonReleased();
	void endGame();
	void winGameScreen();
	void winLevelScreen();
	void setWinScreen(backgroundsType, sounds);

	sf::Clock m_gameClock;
	sf::RenderWindow m_window;
	sf::Sound m_backGroundMusic;
	sf::RectangleShape m_background;
	Board m_board;
	StatusBar m_statusBar;
	bool m_playButton;
};