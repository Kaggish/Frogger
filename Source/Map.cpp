#include "Map.hpp"

//Map::Map(Screen& p_screen)
//{
//	m_watercolor = { 0, 0 , 255, 255 };
//	m_grasscolor = { 0, 255, 0, 255 };
//	m_safezonecolor = { 127, 0, 255, 255 };
//	m_waterX = 0;
//	m_waterY = 100;
//	m_waterwidth = (float)p_screen.GetWindowWidth();
//	m_waterheight = 200;
//	m_grassX = 0;
//	m_grassY = 0;
//	m_grasswidth = (float)p_screen.GetWindowWidth();
//	m_grassheight = 100;
//	m_safezoneX = 0;
//	m_safezoneY = (float)p_screen.GetWindowHeight() / 2 - 50;
//	m_safezonewidth =(float)p_screen.GetWindowWidth();
//	m_safezoneheight = 100;
//}

void Map::DrawWater()
{
	/*p_screen.DrawRectangle((int)m_waterX, (int)m_waterY, (int)m_waterwidth, (int)m_waterheight, m_watercolor);*/
}

void Map::DrawGrass()
{
	/*p_screen.DrawRectangle((int)m_grassX, (int)m_grassY, (int)m_grasswidth, (int)m_grassheight, m_grasscolor);*/
}

void Map::DrawSafeZone()
{
	/*p_screen.DrawRectangle((int)m_safezoneX, (int)m_safezoneY, (int)m_safezonewidth, (int)m_safezoneheight, m_safezonecolor);
	p_screen.DrawRectangle((int)m_safezoneX, (int)m_safezoneY + 350, (int)m_safezonewidth, (int)m_safezoneheight - 50, m_safezonecolor);*/
}

void Map::Draw()
{
	DrawWater();
	DrawGrass();
	DrawSafeZone();
}

//float Map::GetWaterX()
//{
//	return m_waterX;
//}
//
//float Map::GetWaterY()
//{
//	return m_waterY;
//}
//
//float Map::GetBoxX()
//{
//	return m_waterX + m_waterwidth;
//}
//
//float Map::GetBoxY()
//{
//	return m_waterY + m_waterheight;
//}
