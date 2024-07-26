#pragma once
#include "raylib.h"

class Frog
{
	Vector2 Position = {((float)GetScreenWidth() / 2), 750};
	Vector2 speedDir = {};

	float Offset = 25.0f;

	const float SPEED = 5.0f;
	const float RADIUS = 25.0f;
	float jumptimer = 0.0f;
	float rotation = 0.0f;

	bool jumping = false;
	bool IsOnLog = false;

	void Movement();
	void WorldBlock();

public:
	void Input();
	void Update();
	void Draw(Texture2D& Texture);
	
	Rectangle HitBox();
};
