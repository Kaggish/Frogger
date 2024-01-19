#include "Goals.h"

goal::goal(Screen& p_screen, float p_posX, float p_posY, float p_width, float p_height)
{
	m_goalX = p_posX;
	m_goalY = p_posY;
	m_goalwidth = p_width;
	m_goalheight = p_height;
	m_taken = false;
	m_sprite = p_screen.LoadSprite("Assets/Frog.png");
	m_sprite.scale = 1.5;
}

goal::~goal()
{

}

void goal::DrawGoals(Screen& p_screen)
{
	p_screen.DrawRectangle((int)m_goalX, (int)m_goalY, (int)m_goalwidth, (int)m_goalheight);
}

void goal::DrawFrog(Screen& p_screen)
{
	m_sprite.position.x = GetX();
	m_sprite.position.y = GetY();
	p_screen.DrawSprite(m_sprite);
}

void goal::Draw(Screen& p_screen)
{
	DrawGoals(p_screen);
}

float goal::GetX()
{
	return m_goalX;
}

float goal::GetY()
{
	return m_goalY;
}

float goal::GetBoxX()
{
	return m_goalX + m_goalwidth;
}

float goal::GetBoxY()
{
	return m_goalY + m_goalheight;
}

bool goal::GetTaken()
{
	return m_taken;
}

void goal::SetGoalX(float p_goalX)
{
	m_goalX = p_goalX;
}

void goal::SetTaken(bool p_taken)
{
	m_taken = p_taken;
}
