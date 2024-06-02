#include "Frog.hpp"

Rectangle Frog::HitBox()
{
	return Rectangle(position.x - Offset, position.y - Offset, RADIUS * 2.0f, RADIUS * 2.0f);
}

void Frog::WorldBlock()
{
	if (position.x - Offset <= 0)
	{
		position.x = 0 + Offset;
	}
	if (position.x + Offset >= GetScreenWidth())
	{
		position.x = (float)GetScreenWidth() - Offset;
	}
	if (position.y - Offset <= 0)
	{
		position.y = 0 + Offset;
	}
	if (position.y + Offset >= GetScreenHeight())
	{
		position.y = (float)GetScreenHeight() - Offset;
	}
}


void Frog::Input()
{
	if (IsKeyPressed(KEY_W) && jumping == false)
	{
		speedDir = { 0, -8 };
		jumping = true;
		rotation = 0;
	}
	if (IsKeyPressed(KEY_A) && jumping == false)
	{
		speedDir = { -8, 0 };
		jumping = true;
		rotation = 270;
	}
	if (IsKeyPressed(KEY_S) && jumping == false)
	{
		speedDir = { 0, 8 };
		jumping = true;
		rotation = 180;
	}
	if (IsKeyPressed(KEY_D) && jumping == false)
	{
		speedDir = { 8, 0 };
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
		{Texture.width/2.0f, Texture.height/2.0f}, rotation, WHITE); //This is fcking disgusting, can´t come up how to rotate the texture
	DrawRectangle((int)HitBox().x, (int)HitBox().y, (int)RADIUS * 2, (int)RADIUS * 2, RED);
}
