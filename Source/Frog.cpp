#include "Frog.hpp"

Rectangle Frog::HitBox()
{
	return Rectangle(Position.x - (Offset / 2.0f), Position.y - (Offset / 2.0f), RADIUS, RADIUS);
}

void Frog::WorldBlock()
{
	if (Position.x - Offset <= 0)
	{
		Position.x = 0 + Offset;
	}
	if (Position.x + Offset >= GetScreenWidth())
	{
		Position.x = (float)GetScreenWidth() - Offset;
	}
	if (Position.y - Offset <= 0)
	{
		Position.y = 0 + Offset;
	}
	if (Position.y + Offset >= GetScreenHeight())
	{
		Position.y = (float)GetScreenHeight() - Offset;
	}
}


void Frog::Input()
{
	if (IsKeyPressed(KEY_W))
	{
		speedDir = { 0, -SPEED };
		jumping = true;
		rotation = 0;
	}
	if (IsKeyPressed(KEY_A))
	{
		speedDir = { -SPEED, 0 };
		jumping = true;
		rotation = 270;
	}
	if (IsKeyPressed(KEY_S))
	{
		speedDir = { 0, SPEED };
		jumping = true;
		rotation = 180;
	}
	if (IsKeyPressed(KEY_D))
	{
		speedDir = { SPEED, 0 };
		jumping = true;
		rotation = 90;
	}
}

void Frog::Movement()
{
	Position.x += speedDir.x;
	Position.y += speedDir.y;
}

void Frog::Update()
{
	if (jumptimer >= 10)
	{
		jumping = false;
		speedDir = { 0, 0 };
		jumptimer = 0;
	}

	if (jumping)
	{
		Movement();
		jumptimer++;
	}

	WorldBlock();
}

void Frog::Draw(Texture2D &Texture)
{
	DrawTexturePro(Texture, 
		Rectangle(0.0f, 0.0f, static_cast<float>(Texture.width), static_cast<float>(Texture.height)), 
		Rectangle(Position.x, Position.y, static_cast<float>(Texture.width), static_cast<float>(Texture.height)),
		{Texture.width/2.0f, Texture.height/2.0f}, rotation, WHITE); //This is fcking disgusting, can´t come up how to rotate the texture

	/*DrawRectangle(static_cast<int>(HitBox().x), static_cast<int>(HitBox().y), static_cast<int>(HitBox().width), static_cast<int>(HitBox().height), RED);*/
}
