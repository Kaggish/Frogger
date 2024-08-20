#pragma once
#include "raylib.h"

class Cars
{

	void Wrapping();
	void Movement();

public:
	Vector2 Position = {0.0f, 0.0f};
	const float SPEED = {0.0f};
	const int ID = { 0 };

	void Update();
	void Draw(Texture2D& Texture);
};