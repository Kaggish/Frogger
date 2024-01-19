#pragma once

class map
{
	float m_waterX, m_waterY, m_waterwidth, m_waterheight, m_grassX, m_grassY, m_grassheight, m_grasswidth, m_safezoneX, m_safezoneY, m_safezonewidth, m_safezoneheight;
	Color m_watercolor;
	Color m_grasscolor;
	Color m_safezonecolor;
	void DrawWater();
	void DrawGrass();
	void DrawSafeZone();
public:
	map();
	void Draw();
	float GetWaterX();
	float GetWaterY();
	float GetBoxX();
	float GetBoxY();
};