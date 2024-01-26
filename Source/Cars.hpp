#pragma once
#include "raylib.h"

class Cars
{
	void Movement();
	void Wrapping();


public:
	Vector2 position;
	const float SPEED = 0;

	void Update();
	void Draw(Texture2D& Texture);
};

	//TODO:Create these functions for later functionality,
	/*float GetX();
	float GetY();
	float GetBoxX();
	float GetBoxY();
	float GetWidth(Texture2D& texture);
	float GetHeight(Texture2D& texture);*/
	/*void SetX(float p_carPosX);*/