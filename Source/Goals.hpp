#pragma once
#include <raylib.h>

class Goal
{
	static constexpr float RADIUS = 25.0f;

public:
	Vector2 Position = { 0.0f, 0.0f };
	bool Scored = false;

	void Draw(Texture2D& texture);

	Rectangle HitBox();
};
 