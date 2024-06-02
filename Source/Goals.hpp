#pragma once
#include <raylib.h>

class Goal
{
	Vector2 position = {};

	const float RADIUS = 10.0f;

	bool Scored = false;

public:
	void Draw(Texture2D& texture);
	/*float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	bool GetTaken();
	void SetGoalX(float p_goalX);
	void SetTaken(bool p_taken);*/
};
 