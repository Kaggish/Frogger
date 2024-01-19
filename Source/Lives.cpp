#include "Lives.h"

lives::lives(Screen& p_screen, float p_LivesX, float p_LivesY)
{
	m_sprite = p_screen.LoadSprite("Assets/Frog.png");
	m_sprite.position.x = p_LivesX;
	m_sprite.position.y = p_LivesY;
}

lives::~lives()
{

}

void lives::Update(Screen& p_screen)
{

}

void lives::Draw(Screen& p_screen)
{
	p_screen.DrawSprite(m_sprite);
}

float lives::GetX()
{
	return m_sprite.position.x;
}

void lives::SetX(float p_LivesX)
{
	m_sprite.position.x = p_LivesX;
}
