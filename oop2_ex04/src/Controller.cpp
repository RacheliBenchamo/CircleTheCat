
#include "Controller.h"
using std::cout;

Controller::Controller()
	:m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"Circle The Cat!", sf::Style::Titlebar | sf::Style::Close)
	//, m_playButton(true)
{
	m_window.setFramerateLimit(15);

	m_backGroundMusic.setBuffer(*FileManager::p2FileManager().getSound(S_BACKROUND));
	m_background.setSize({ WINDOW_WIDTH, WINDOW_HEIGHT + STATUS_BAR_HEIGHT });
	m_background.setTexture(FileManager::p2FileManager().getBackGround(GAME_BACKGROUND));
}

//run
void Controller::run()
{
	int levCount = 0;
	m_backGroundMusic.play();
	m_backGroundMusic.setLoop(true);
	m_backGroundMusic.setVolume(VOLUME_BG);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(255, 240, 245, 255));
		m_window.draw(m_background);
		m_statusBar.draw(m_window, m_board.getClickCount(),m_board.getWinLevel());
		m_board.draw(m_window);

		sf::Event event;

		while (m_window.pollEvent(event))
			CheckOutWhatEvent( event);
		m_window.display();

		if (m_board.getWinLevel())
		{
			if (levCount < NUM_OF_LEVELS)
			{
				//win msg
				m_board.startNewLevel();
				levCount++;
			}
			else
				endGame();
		}
		if (m_board.getLoseLevel())
			//lose msg
			m_board.restartLevel();
	}
}

//-----------------------------------------------------------------
//check event
void Controller::CheckOutWhatEvent( sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		m_window.close();
		break;
	case sf::Event::MouseButtonReleased:
		handelMouseButtonReleased(event);
		break;
	}
}

//----------------------------------------------
//handle the event that occurred when the MouseButtonReleased

void Controller::handelMouseButtonReleased(sf::Event event)
{
	if (m_statusBar.containsMusicIcon(event))
		handelMusicButtonReleased();

	else if (m_statusBar.containsRestartIcon(event))
		m_board.restartLevel();
	else if (m_statusBar.containsUndoIcon(event))
		m_board.undo();
	else
		m_board.mouseButtonReleased(event, m_window);
}

//----------------------------------------------
//stopping or playing background music

void Controller::handelMusicButtonReleased()
{
	if (m_backGroundMusic.getStatus() == sf::SoundSource::Status::Playing)
	{
		m_backGroundMusic.stop();
		m_statusBar.setMusicIcon(false);
	}
	else
	{
		m_backGroundMusic.play();
		m_statusBar.setMusicIcon(true);
	}
}
//----------------------------------------------

void Controller::endGame()
{

}
