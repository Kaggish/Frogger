#include "Map.hpp"

Rectangle Map::WaterHitBox()
{
	return Rectangle(0, 60, static_cast<float>(GetScreenWidth()), 100);
}

void Map::Draw(Texture2D& WaterTexture, Texture2D& GrassTexture, Texture2D& RoadTexture, Texture2D& SafeZoneTexture)
{
	

	for (int j = 0; j < 17; j++)
	{
		for (int x = 0; x < 16; x++)
		{
			switch (mapLayout[j][x])
			{
				case 0:
					DrawTextureV(GrassTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
					break;

				case 1:
					DrawTextureV(WaterTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
					break;

				case 2:
					DrawTextureV(SafeZoneTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
					break;

				case 3:
					DrawTextureV(RoadTexture, { static_cast<float>(x * (Radius * 2)), static_cast<float>(j * (Radius * 2)) }, WHITE);
					break;
			}
		}
	}
}
