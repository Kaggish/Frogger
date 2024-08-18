#pragma once
#include "raylib.h"

class Logs
{
	void Movement();

public:

	Vector2 Position = { 0.0f, 0.0f };
	const float SPEED = {};

	void Wrapping();
	void Update();
	void Draw(Texture2D& Texture);

	Rectangle HitBox();
};
