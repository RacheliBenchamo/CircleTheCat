
#include "Controller.h"
using std::cout;

//run
void Controller::run()
{

	Board board;
	sf::RenderWindow window(sf::VideoMode(920, 920),
		"Circle The Cat!"
		, sf::Style::Titlebar | sf::Style::Close);

	sf::Texture texture;
	sf::Sprite sprite;
	//drawBackground(texture, sprite, x, y);

	while (window.isOpen())
	{
		window.clear(sf::Color(255, 240, 245, 255));
		window.draw(sprite);
		board.draw(window);
		sf::Event event;

		while (window.pollEvent(event))
			CheckOutWhatEvent(window, event, board);

		window.display();
	}
}

//-----------------------------------------------------------------
//check event
void Controller::CheckOutWhatEvent(sf::RenderWindow& window, sf::Event event,
	Board& board)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		window.close();
		break;
	case sf::Event::MouseButtonReleased:
		board.mouseButtonReleased(event, window);
		break;
	case sf::Event::MouseMoved:
		if (board.inWindow(event))
			board.mouseMoved(event, window);
		break;

	}
}
////------------------------------------------------------
////draw background
//void  Controller::drawBackground(sf::Texture& texture, sf::Sprite& sprite, int x, int y)
//{
//	texture.loadFromFile("wallp.png");
//	sprite.setTexture(texture);
//	sprite.setScale(sf::Vector2f(((float)(P_SIZE * x) / 300),
//		((float)(P_SIZE * y) / 300)));
//
//}