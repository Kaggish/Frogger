#include "Logs.hpp"


Rectangle Logs::HitBox()
{
	return Rectangle();
}

void Logs::Wrapping()
{
	if (Position.x < 0)
	{
		Position.x = (float)GetScreenWidth();
	}
	if (Position.x > (float)GetScreenWidth())
	{
		Position.x = 0;
	}
}

void Logs::Movement()
{
	Position.x += SPEED;
}

void Logs::Update()
{
	Movement();
	Wrapping();
}

void Logs::Draw(Texture2D& Texture)
{
	DrawTextureV(Texture, Position, WHITE);
}