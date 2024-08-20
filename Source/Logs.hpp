#pragma once
#include "raylib.h"

class Logs
{
	void Movement();

public:

	Vector2 Position = { 0.0f, 0.0f };
	const float SPEED = {0.0f};
	const int ID = { 0 };

	void Wrapping(Texture2D& Texture);
	void Update(Texture2D& Texture);
	void Draw(Texture2D& Texture);

	Rectangle HitBox(Texture2D& Texture);
};
