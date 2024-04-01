#pragma once
#include "Lives.hpp"
#include <vector>

class GUI
{
	float m_scoreX, m_scoreY;
	int m_score;
	Color color;

	std::vector<Lives> m_Lives;
public:
	GUI();
	void AddScore();
	void AddLives();
	void DeleteLives();
	void Update();
	void Draw();
	int GetScore();
	int GetLives();
};
