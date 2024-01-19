#pragma once
#include <vector>

class goal
{
	float m_goalX, m_goalY, m_goalwidth, m_goalheight;
	bool m_taken;
	Sprite m_sprite;

public:
	goal(float p_posX, float p_posY, float p_width, float p_height);
	void DrawGoals();
	void DrawFrog();
	void Draw();
	float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	bool GetTaken();
	void SetGoalX(float p_goalX);
	void SetTaken(bool p_taken);
};
 