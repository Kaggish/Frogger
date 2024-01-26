#include "Cars.hpp"
#include <string>


void Cars::Wrapping()
{
	//TODO: Use the ternary operator to make this into one line
	if (position.x < 0)
	{
		position.x = (float)GetScreenWidth();
	}
	else if (position.x > (float)GetScreenWidth())
	{
		position.x = 0;
	}
}

void Cars::Movement()
{
	position.x += SPEED * GetFrameTime();
}

void Cars::Update()
{
	Movement();
	Wrapping();
}

void Cars::Draw(Texture2D &Texture)
{
	DrawTextureV(Texture, position, WHITE);
}

