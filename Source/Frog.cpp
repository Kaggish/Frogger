#include "Frog.hpp"
#include <cmath>

Rectangle Frog::HitBox()
{
	return Rectangle(position.x, position.y, RADIUS * 2.0f, RADIUS * 2.0f);
}

void Frog::WorldBlock()
{
	if (position.x <= 0)
	{
		position.x = 0;
	}
	if (position.x >= GetScreenWidth())
	{
		position.x = (float)GetScreenWidth();
	}
	if (position.y <= 0)
	{
		position.y = 0;
	}
	if (position.y >= GetScreenHeight())
	{
		position.y = (float)GetScreenHeight();
	}
}

Vector2 Point(float cX, float cY, float angle, Vector2 point)
{
	float s = sin(angle);
	float c = cos(angle);

	// translate point back to origin:
	point.x -= cX;
	point.y -= cY;

	// rotate point
	float xnew = point.x * c - point.y * s;
	float ynew = point.x * s + point.y * c;

	// translate point back:
	point.x = xnew + cX;
	point.y = ynew + cY;

	return point;
}


void Frog::Input()
{
	if (IsKeyPressed(KEY_W) && jumping == false)
	{
		speedDir = { 0, -7 };
		jumping = true;
		rotation = 0;
	}
	if (IsKeyPressed(KEY_A) && jumping == false)
	{
		speedDir = { -7, 0 };
		jumping = true;
		rotation = 270;
	}
	if (IsKeyPressed(KEY_S) && jumping == false)
	{
		speedDir = { 0, 7 };
		jumping = true;
		rotation = 180;
	}
	if (IsKeyPressed(KEY_D) && jumping == false)
	{
		speedDir = { 7, 0 };
		jumping = true;
		rotation = 90;
	}
}

void Frog::Movement()
{
	position.x += speedDir.x;
	position.y += speedDir.y;
}

void Frog::Update()
{
	if (jumping == true)
	{
		jumptimer++;
	}
	if (jumptimer == 4)
	{
		jumping = false;
		speedDir = { 0, 0 };
		jumptimer = 0;
	}
	Movement();
	WorldBlock();
}

void Frog::Draw(Texture2D &Texture)
{
	DrawTexturePro(Texture, 
		Rectangle(0.0f, 0.0f, static_cast<float>(Texture.width), static_cast<float>(Texture.height)), 
		Rectangle(position.x, position.y, static_cast<float>(Texture.width), static_cast<float>(Texture.height)),
		{Texture.width/2.0f, Texture.height/2.0f}, rotation, WHITE); //This Is fcking disgusting, can´t come up how to rotate the texture
}
