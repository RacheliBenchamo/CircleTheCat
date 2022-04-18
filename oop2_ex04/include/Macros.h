#pragma once

#include <string>
#include <SFML/Graphics.hpp>

const int BOARD_LEN = 11;

// general data
const unsigned int NUM_OF_ICONS = 14;
const unsigned int NUM_OF_SOUNDS = 14;
const unsigned int NUM_OF_BACKGROUNDS = 5;
const unsigned int NUM_OF_DIRECTION = 4;
const unsigned int P_SIZE = 75; // pixel size

const sf::Color BASE_COLOR = sf::Color(250, 235, 215, 255);
const sf::Color CLICKED_COLOR = sf::Color(188, 143, 143, 255);

//volume data
const unsigned int VOLUME_BG = 5;
const unsigned int VOLUME_COLLISION = 6;

// window data
const int MAX_HEIGHT = 12;
const int MAX_WIDTH = 27;
const int WINDOW_WIDTH = MAX_WIDTH * P_SIZE;
const int WINDOW_HEIGHT = (MAX_HEIGHT + 1) * P_SIZE;

//time data
const int WIN_WIAT = 70;

//speed data
const float BASE_SPEED = 100.;

// for the menu
const sf::Vector2f SCREEN_CENTER = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
const int HEADER_SIZE = 80;
const int REG_CHAR_SIZE = 70;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;

// for the status bar
const int STATUS_BAR_HEIGHT = 50;
const int STATUS_BAR_CHAR_SIZE = 60;
const float STATUS_BAR_OUTLINE_THICKNESS = 3.0;
const int BUFF_DISTANCE = 40;
const sf::Vector2f MUSIC_ICON_SCALE = { 0.08f, 0.08f };

//direction data
const sf::Vector2f DVec[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


enum icons
{
	CAT,
	EMPTY
};
enum sounds
{
	
	S_WIN_LEVEL, S_WIN_GAME, S_LOSE_LEVEL, S_BACKROUND
};

enum backgroundsType
{
	GAME_BACKGROUND, WIN_LEVEL_BACKGROUND,
	WIN_GAME_BACKGROUND
};

enum giftType
{
	TAKE_TO_PREV_LEVEL, MOVE_FAIRIES, TAKE_TIME, ADD_TIME
};

enum direction
{
	LEFT, RIGHT, UP, DOWN,
};

