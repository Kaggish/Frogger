#pragma once
#include "Lives.hpp"
#include <vector>

class GUI
{
	Vector2 Position = {};
	
	int score = 0;

	std::vector<Lives> m_Lives;

public:
	void AddScore();
	void AddLives();
	void DeleteLives();
	void Update();
	void Draw();
	int GetScore();
	int GetLives();
};
