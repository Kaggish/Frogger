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

void Map::Draw(Texture2D& WaterTexture, Texture2D& GrassTexture, Texture2D& RoadTexture, Texture2D& SafeZoneTexture)
{
	for (int j = 0; j < 17; j++)
	{
		for (int x = 0; x < 16; x++)
		{
			if (mapLayout[j][x] == 0)
			{
				DrawTextureV(GrassTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
			}
			else if (mapLayout[j][x] == 1)
			{
				DrawTextureV(WaterTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
			}
			else if (mapLayout[j][x] == 2)
			{
				DrawTextureV(SafeZoneTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
			}
			else if (mapLayout[j][x] == 3)
			{
				DrawTextureV(WaterTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
			}
			else if (mapLayout[j][x] == 4)
			{
				DrawTextureV(RoadTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
			}
		}
	}
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
