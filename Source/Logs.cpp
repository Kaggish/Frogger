#include "Logs.h"

logs::logs(Screen& p_screen, std::string path, float p_logX, float p_logY, float p_logSpeed)
{
	m_sprite = p_screen.LoadSprite(path);
	m_sprite.position.x = p_logX;
	m_sprite.position.y = p_logY;
	m_speed.x = p_logSpeed;
	m_onlog = false;
}

logs::~logs()
{

}

void logs::Wrapping(Screen& p_screen)
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

void logs::Movement()
{
	m_sprite.position.x += (m_speed.x);
}

void logs::Update(Screen& p_screen)
{
	Movement();
	Wrapping(p_screen);
}

void logs::Draw(Screen& p_screen)
{
	p_screen.DrawSprite(m_sprite);
}

float logs::GetX()
{
	return m_sprite.position.x;
}

float logs::GetY()
{
	return m_sprite.position.y;
}

float logs::GetBoxX()
{
	return m_sprite.position.x + GetWidth();
}

float logs::GetBoxY()
{
	return m_sprite.position.y + GetHeight();
}

float logs::GetWidth()
{
	return (float)m_sprite.texture.width;
}

float logs::GetHeight()
{
	return (float)m_sprite.texture.height;
}

float logs::GetSpeed()
{
	return m_speed.x;
}

bool logs::GetOnLog()
{
	return m_onlog;
}

void logs::SetX(float p_logPosX)
{
	m_sprite.position.x = p_logPosX;
}

void logs::SetOnlog(bool p_onlog)
{
	m_onlog = p_onlog;
}
