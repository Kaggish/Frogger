#include "Logs.hpp"


Rectangle Logs::HitBox(Texture2D& Texture)
{
	return Rectangle(Position.x, Position.y, (float)Texture.width, (float)Texture.height);
}

void Logs::Wrapping(Texture2D& Texture)
{
	if (Position.x + (float)Texture.width < 0)
	{
		Position.x = (float)GetScreenWidth();
	}
	if (Position.x > (float)GetScreenWidth())
	{
		Position.x = 0.0f - (float)Texture.width;
	}
}

void Logs::Movement()
{
	Position.x += SPEED;
}

void Logs::Update(Texture2D& Texture)
{
	Movement();
	Wrapping(Texture);
}

void Logs::Draw(Texture2D& Texture)
{
	DrawTextureV(Texture, Position, WHITE);
	/*DrawRectangle(static_cast<int>(HitBox(Texture).x), static_cast<int>(HitBox(Texture).y), static_cast<int>(HitBox(Texture).width), static_cast<int>(HitBox(Texture).height), RED);*/
}