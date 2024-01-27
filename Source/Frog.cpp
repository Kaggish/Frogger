#include "Frog.hpp"

void frog::WorldBlock()
{
	if (position.x - 25 <= 0)
	{
		position.x = 25;
	}
	if (position.x + 25 >= GetScreenWidth())
	{
		position.x = (float)GetScreenWidth() - 25;
	}
	if (position.y - 25 <= 50)
	{
		position.y = 75;
	}
	if (position.y + 25 >= GetScreenHeight())
	{
		position.y = (float)GetScreenHeight() - 25;
	}
}

void frog::Input()
{
	if (IsKeyDown(KEY_W) && jumping == false)
	{
		speedDir = { 0, -7 };
		jumping = true;
		rotation = 0;
	}
	if (IsKeyDown(KEY_A) && jumping == false)
	{
		speedDir = { -7, 0 };
		jumping = true;
		rotation = 270;
	}
	if (IsKeyDown(KEY_S) && jumping == false)
	{
		speedDir = { 0, 7 };
		jumping = true;
		rotation = 180;
	}
	if (IsKeyDown(KEY_D) && jumping == false)
	{
		speedDir = { 7, 0 };
		jumping = true;
		rotation = 90;
	}
}

void frog::Movement()
{
	position.x += speedDir.x;
	position.y += speedDir.y;
}

void frog::Update()
{
	if (jumping == true)
	{
		jumptimer++;
	}
	if (jumptimer == 8)
	{
		jumping = false;
		speedDir = { 0, 0 };
		jumptimer = 0;
	}
	Movement();
	WorldBlock();
}

void frog::Draw(Texture2D &Texture)
{
	DrawTextureEx(Texture, position, rotation, 1.0f, WHITE);
}
