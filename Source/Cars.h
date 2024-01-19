#pragma once
#include "raylib.h"

class cars
{
	virtual void Movement();
	void Wrapping();

public:
	cars(std::string path, float p_carX, float p_carY, float carSpeed);
	virtual void Update();
	virtual void Draw();
	float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	float GetWidth();
	float GetHeight();
	void SetX(float p_carPosX);
};
