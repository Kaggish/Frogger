#include "Cars.h"
#include <string>

cars::cars(Screen& p_screen, std::string path, float p_carX, float p_carY, float p_carSpeed)
{
	m_sprite = p_screen.LoadSprite(path);
	m_sprite.position.x = p_carX;
	m_sprite.position.y = p_carY;
	m_speed.x = p_carSpeed;
	m_sprite.position.x += 10;
	m_sprite.origin = { 12.5, 12.5 };
}

void cars::Wrapping(Screen& p_screen)
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

void cars::Movement()
{
	m_sprite.position.x += (m_speed.x);
}

void cars::Update(Screen& p_screen)
{
	Movement();
	Wrapping(p_screen);
}

void cars::Draw(Screen& p_screen)
{
	p_screen.DrawSprite(m_sprite);
}

float cars::GetX()
{
	return m_sprite.position.x;
}

float cars::GetY()
{
	return m_sprite.position.y;
}

float cars::GetBoxX()
{
	return m_sprite.position.x + GetWidth();
}

float cars::GetBoxY()
{
	return m_sprite.position.y + GetHeight();
}

float cars::GetWidth()
{
	return (float)m_sprite.texture.width;
}

float cars::GetHeight()
{
	return (float)m_sprite.texture.height;
}

void cars::SetX(float p_carPosX)
{
	m_sprite.position.x = p_carPosX;
}

