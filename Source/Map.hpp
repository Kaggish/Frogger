#pragma once
#include "raylib.h"

class Map
{
	Vector2 waterPosition = {};
	Vector2 grassPosition = {};
	Vector2 safeZonePosition = {};

	const float waterRadius = 25.0f;
	const float grassRadius = 25.0f;
	const float safeZoneRadius = 25.0f;

	void DrawWater();
	void DrawGrass();
	void DrawSafeZone();
public:
	void Draw();
	float GetWaterX();
	float GetWaterY();
	float GetBoxX();
	float GetBoxY();
};