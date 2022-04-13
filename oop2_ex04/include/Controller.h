#include "Board.h"
#include <iostream>

class Controller
{
public:

	Controller() {}
	~Controller() {}

	void run();

private:
	void CheckOutWhatEvent(sf::RenderWindow& window, sf::Event event, Board& board);
	//void drawBackground(sf::Texture& texture, sf::Sprite& sprite, int x, int y);

	bool m_existFile = true;
	bool m_out = false;

};