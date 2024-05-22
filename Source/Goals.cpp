#include "Goals.hpp"

//Goal::Goal(float p_posX, float p_posY, float p_width, float p_height)
//{
//	m_goalX = p_posX;
//	m_goalY = p_posY;
//	m_goalwidth = p_width;
//	m_goalheight = p_height;
//	m_taken = false;
//	m_sprite = p_screen.LoadSprite("Assets/Frog.png");
//	m_sprite.scale = 1.5;
//}

void Goal::Draw(Texture2D& texture)
{
	DrawTextureEx(texture, position, 0, 1.0f, WHITE);
}

//float Goal::GetX()
//{
//	return m_goalX;
//}
//
//float Goal::GetY()
//{
//	return m_goalY;
//}
//
//float Goal::GetBoxX()
//{
//	return m_goalX + m_goalwidth;
//}
//
//float Goal::GetBoxY()
//{
//	return m_goalY + m_goalheight;
//}
//
//bool Goal::GetTaken()
//{
//	return m_taken;
//}
//
//void Goal::SetGoalX(float p_goalX)
//{
//	m_goalX = p_goalX;
//}
//
//void Goal::SetTaken(bool p_taken)
//{
//	m_taken = p_taken;
//}
