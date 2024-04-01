#include "Logs.hpp"

Logs::Logs(Screen& p_screen, std::string path, float p_logX, float p_logY, float p_logSpeed)
{
	m_sprite = p_screen.LoadSprite(path);
	m_sprite.position.x = p_logX;
	m_sprite.position.y = p_logY;
	m_speed.x = p_logSpeed;
	isonlog = false;
}

Logs::~Logs()
{

}

void Logs::Wrapping(Screen& p_screen)
{
	if (m_sprite.position.x + GetWidth() < 0)
	{
		m_sprite.position.x = (float)p_screen.GetWindowWidth();
	}
	else if (m_sprite.position.x > p_screen.GetWindowWidth())
	{
		m_sprite.position.x = -150;
	}
}

void Logs::Movement()
{
	m_sprite.position.x += (m_speed.x);
}

void Logs::Update(Screen& p_screen)
{
	Movement();
	Wrapping(p_screen);
}

void Logs::Draw(Screen& p_screen)
{
	p_screen.DrawSprite(m_sprite);
}

float Logs::GetX()
{
	return m_sprite.position.x;
}

float Logs::GetY()
{
	return m_sprite.position.y;
}

float Logs::GetBoxX()
{
	return m_sprite.position.x + GetWidth();
}

float Logs::GetBoxY()
{
	return m_sprite.position.y + GetHeight();
}

float Logs::GetWidth()
{
	return (float)m_sprite.texture.width;
}

float Logs::GetHeight()
{
	return (float)m_sprite.texture.height;
}

float Logs::GetSpeed()
{
	return m_speed.x;
}

bool Logs::GetOnLog()
{
	return isonlog;
}

void Logs::SetX(float p_logPosX)
{
	m_sprite.position.x = p_logPosX;
}

void Logs::SetOnlog(bool p_onlog)
{
	isonlog = p_onlog;
}
