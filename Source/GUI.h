#pragma once
#include "Lives.h"
#include <vector>

class gui
{
	float m_scoreX, m_scoreY;
	int m_score;
	Color color;

	std::vector<lives> m_Lives;
public:
	gui();
	void AddScore();
	void AddLives();
	void DeleteLives();
	void Update();
	void Draw();
	int GetScore();
	int GetLives();
};
