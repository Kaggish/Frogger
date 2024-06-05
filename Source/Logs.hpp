#pragma once
#include "raylib.h"

class Logs
{
	Vector2 Position = {};
	const float SPEED = {};

	void Movement();

public:
	void Wrapping();
	void Update();
	void Draw();
};
