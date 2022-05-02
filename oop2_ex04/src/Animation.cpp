#include "Animation.h"

Animation::Animation(const sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	m_imageCount = imageCount;
	m_switchTime = switchTime;
	m_totalTime = 0.0f;
	m_currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(m_imageCount.x);
	uvRect.height = texture->getSize().y / float(m_imageCount.y);
}

void Animation::Update(int row, float deltaTime, bool faseRight)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;

		if (m_currentImage.x >= m_imageCount.x)
			m_currentImage.x = 0;

	}
	uvRect.top = m_currentImage.y * uvRect.height;

	if (faseRight)
	{
		uvRect.left = m_currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (m_currentImage.x + 1) * uvRect.width;
		uvRect.width = -abs(uvRect.width);
	}
}
