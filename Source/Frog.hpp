#pragma once
#include "raylib.h"

class Frog
{
	Vector2 position = {};
	Vector2 speedDir = {};

	const float SPEED = 7;
	const float RADIUS = 25;
	float scale = 50;
	float jumptimer = 0;
	float rotation = 0;

	bool jumping = false;
	bool isonlog = false;

	void Movement();
	void WorldBlock();

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
