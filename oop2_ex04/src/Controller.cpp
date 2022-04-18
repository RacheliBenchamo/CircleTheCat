
#include "Controller.h"
using std::cout;

Controller::Controller()
	:m_window(sf::VideoMode(920, 920),
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
	m_backGroundMusic.play();
	m_backGroundMusic.setLoop(true);
	m_backGroundMusic.setVolume(VOLUME_BG);

	while (m_window.isOpen())
	{
		m_window.clear(sf::Color(255, 240, 245, 255));
		m_window.draw(m_background);
		m_board.draw(m_window);

		
		sf::Event event;

		while (m_window.pollEvent(event))
			CheckOutWhatEvent( event);
		
		m_window.display();
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
		m_board.mouseButtonReleased(event, m_window);
		break;
	case sf::Event::MouseMoved:
		if (m_board.inWindow(event))
			m_board.mouseMoved(event, m_window);
		break;

	}
}
