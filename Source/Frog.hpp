#pragma once
#include "raylib.h"

class Frog
{
	Vector2 position = {((float)GetScreenWidth() / 2), 500};
	Vector2 speedDir = {};

	float Offset = 12.5f;

	const float SPEED = 7.0f;
	const float RADIUS = 12.5f;
	float scale = 50.0f;
	float jumptimer = 0.0f;
	float rotation = 0.0f;

	bool jumping = false;
	bool IsOnLog = false;

	void Movement();
	void WorldBlock();
	Rectangle HitBox();

public:
	void Input();
	void Update();
	void Draw(Texture2D& Texture);
	//TODO: Make these functions work later
	/*float GetBoxX();
	float GetBoxY();
	float GetWidth();
	float GetHeight();
	float GetX();
	float GetY();*/
};
