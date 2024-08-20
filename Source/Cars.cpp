#include "Cars.hpp"
#include <string>


void Cars::Wrapping()
{
	//TODO: Use the ternary operator to make this into one line
	if (Position.x < 0)
	{
		Position.x = (float)GetScreenWidth();
	}
	if (Position.x > (float)GetScreenWidth())
	{
		Position.x = 0;
	}
}

void Cars::Movement()
{
	Position.x += SPEED;
}

void Cars::Update()
{
	Movement();
	Wrapping();
}

void Cars::Draw(Texture2D &Texture)
{
	DrawTextureV(Texture, Position, WHITE);
}

