#pragma once
#include "raylib.h"

class Logs
{
	const float SPEED;

	void Movement();

public:
	void Wrapping();
	void Update();
	void Draw();

	float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	float GetWidth();
	float GetHeight();
	float GetSpeed();
	void SetX(float p_logPosX);
};
