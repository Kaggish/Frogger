#pragma once
#include <raylib.h>

class Goal
{
	Vector2 Position = {0, 0};

	const float RADIUS = 25.0f;
	bool Scored = false;


public:
	Rectangle HitBox();
	void Draw(Texture2D& texture);

	void SetPos(Vector2 position);
};
 