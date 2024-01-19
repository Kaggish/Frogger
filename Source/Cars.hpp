#pragma once
#include "raylib.h"

class Cars
{
	void Movement();
	void Wrapping();

	Vector2 pos;

public:
	Cars(std::string path, float p_carX, float p_carY, float carSpeed);
	void Update();
	void Draw();
	float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	float GetWidth();
	float GetHeight();
	void SetX(float p_carPosX);
};
