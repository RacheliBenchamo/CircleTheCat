#pragma once
#include "FileManager.h"
#include <iostream>

//--------------------------------------------------
//constructor

FileManager::FileManager()
{
	//loads from all the files:
	loadFromFileIcons();
	loadAudio();
	loadMusicIcon();
	loadBackgrounds();
}
//--------------------------------------------------
//return unic pointer to the object
FileManager& FileManager::p2FileManager()
{
	static FileManager m_instance;
	return m_instance;
}
//--------------------------------------------------
// load all the object images

void FileManager::loadFromFileIcons()
{
	//m_icons[GIFT].loadFromFile("Gift.png");

	this->m_font.loadFromFile("Seagram tfb.ttf");
}
//--------------------------------------------------
// load all the audio

void FileManager::loadAudio()
{
	/*m_audio[S_LOSE_LEVEL].loadFromFile("loseLevelSound.wav");
	m_audio[S_WIN_LEVEL].loadFromFile("winLevelSound.wav");
	m_audio[S_WIN_GAME].loadFromFile("winGameSound.wav");*/
	m_audio[S_BACKROUND].loadFromFile("backgroundMusic.wav");

}
//--------------------------------------------------
// load the music sprites

void FileManager::loadMusicIcon()
{
	m_musicTexture[0].loadFromFile("musicOn.png");
	m_musicTexture[1].loadFromFile("musicOff.png");
}

//--------------------------------------------------
// load the backgrounds sprites

void FileManager::loadBackgrounds()
{
	
	m_backgrounds[GAME_BACKGROUND].loadFromFile("gameBackground.png");
	/*m_backgrounds[WIN_LEVEL_BACKGROUND].loadFromFile("winLevelBackground.png");
	m_backgrounds[WIN_GAME_BACKGROUND].loadFromFile("winGameBackground.png");*/
}
//--------------------------------------------

const sf::SoundBuffer* FileManager::getSound(sounds sound)const
{
	return &this->m_audio[(int)sound];
}
//--------------------------------------------------

const sf::Texture* FileManager::getMusicIcon(bool musicOn)const
{
	if (musicOn)
		return &this->m_musicTexture[0];
	else
		return &this->m_musicTexture[1];
}
//--------------------------------------------------

const sf::Texture* FileManager::getBackGround(backgroundsType place)const
{
	return &this->m_backgrounds[place];
}
////--------------------------------------------------
//
//const sf::Texture* FileManager::getCatTexture()const
//{
//	//return &this->m_icons[place];
//}
//--------------------------------------------------

const sf::Font* FileManager::getFont()const
{
	return &this->m_font;
}

