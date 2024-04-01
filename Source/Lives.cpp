#include "Lives.hpp"

Lives::Lives(Screen& p_screen, float p_LivesX, float p_LivesY)
{
	m_sprite = p_screen.LoadSprite("Assets/Frog.png");
	m_sprite.position.x = p_LivesX;
	m_sprite.position.y = p_LivesY;
}

Lives::~Lives()
{

}

void Lives::Update(Screen& p_screen)
{

}

void Lives::Draw(Screen& p_screen)
{
	p_screen.DrawSprite(m_sprite);
}

float Lives::GetX()
{
	return m_sprite.position.x;
}

void Lives::SetX(float p_LivesX)
{
	m_sprite.position.x = p_LivesX;
}
