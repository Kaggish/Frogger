#pragma once

class Lives
{
	float m_LivesX, m_LivesY;
	Sprite m_sprite;

public:
	Lives(float p_LivesX, float p_LivesY);
	void Update();
	void Draw();
	float GetX();
	void SetX(float p_LivesX);
};
