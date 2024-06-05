#pragma once
#include "raylib.h"

class Cars
{
	Vector2 Position = {};
	const float SPEED = {};

	void Wrapping();
	void Movement();

public:

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