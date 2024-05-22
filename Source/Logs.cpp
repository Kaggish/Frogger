#include "Logs.hpp"

//Logs::Logs(Screen& p_screen, std::string path, float p_logX, float p_logY, float p_logSpeed)
//{
//	m_sprite = p_screen.LoadSprite(path);
//	m_sprite.position.x = p_logX;
//	m_sprite.position.y = p_logY;
//	m_speed.x = p_logSpeed;
//	IsOnLog = false;
//}

void Logs::Wrapping()
{
	/*if (m_sprite.position.x + GetWidth() < 0)
	{
		m_sprite.position.x = (float)p_screen.GetWindowWidth();
	}
	else if (m_sprite.position.x > p_screen.GetWindowWidth())
	{
		m_sprite.position.x = -150;
	}*/
}

void Logs::Movement()
{
	/*m_sprite.position.x += (m_speed.x);*/
}

void Logs::Update()
{
	Movement();
	Wrapping();
}

void Logs::Draw()
{
	/*p_screen.DrawSprite(m_sprite);*/
}

//float Logs::GetX()
//{
//	return m_sprite.position.x;
//}
//
//float Logs::GetY()
//{
//	return m_sprite.position.y;
//}
//
//float Logs::GetBoxX()
//{
//	return m_sprite.position.x + GetWidth();
//}
//
//float Logs::GetBoxY()
//{
//	return m_sprite.position.y + GetHeight();
//}
//
//float Logs::GetWidth()
//{
//	return (float)m_sprite.texture.width;
//}
//
//float Logs::GetHeight()
//{
//	return (float)m_sprite.texture.height;
//}
//
//float Logs::GetSpeed()
//{
//	return m_speed.x;
//}

//void Logs::SetX()
//{
//	/*m_sprite.position.x = p_logPosX;*/
//}
