#include "Cars.hpp"
#include <string>

Cars::Cars(std::string path, float p_carX, float p_carY, float p_carSpeed)
{
	m_sprite = p_screen.LoadSprite(path);
	m_sprite.position.x = p_carX;
	m_sprite.position.y = p_carY;
	m_speed.x = p_carSpeed;
	m_sprite.position.x += 10;
	m_sprite.origin = { 12.5, 12.5 };
}

void Cars::Wrapping()
{
	if (m_sprite.position.x < 0)
	{
		m_sprite.position.x = (float)p_screen.GetWindowWidth();
	}
	else if (m_sprite.position.x > (float)p_screen.GetWindowWidth())
	{
		m_sprite.position.x = 0;
	}
}

void Cars::Movement()
{
	m_sprite.position.x += (m_speed.x);
}

void Cars::Update()
{
	Movement();
	Wrapping();
}

void Cars::Draw()
{
	p_screen.DrawSprite(m_sprite);
}

float Cars::GetX()
{
	return m_sprite.position.x;
}

float Cars::GetY()
{
	return m_sprite.position.y;
}

float Cars::GetBoxX()
{
	return m_sprite.position.x + GetWidth();
}

float Cars::GetBoxY()
{
	return m_sprite.position.y + GetHeight();
}

float Cars::GetWidth()
{
	return (float)m_sprite.texture.width;
}

float Cars::GetHeight()
{
	return (float)m_sprite.texture.height;
}

void Cars::SetX(float p_carPosX)
{
	m_sprite.position.x = p_carPosX;
}

