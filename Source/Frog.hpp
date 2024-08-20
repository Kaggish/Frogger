#pragma once
#include "raylib.h"

class Frog
{
	Vector2 Position = {((float)GetScreenWidth() / 2), 750};
	Vector2 speedDir = { 0.0f, 0.0f };

	float Offset = 25.0f;

	const float SPEED = 5.0f;
	const float RADIUS = 25.0f;
	float jumptimer = 0.0f;
	float rotation = 0.0f;


	void Movement();
	void WorldBlock();

public:
	bool IsOnLog = false;
	bool jumping = false;

	void Input();
	void Update();
	void Draw(Texture2D& Texture);
	
	Rectangle HitBox();
};
