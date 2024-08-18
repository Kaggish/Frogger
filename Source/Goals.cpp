#include "Goals.hpp"

Rectangle Goal::HitBox()
{
	return Rectangle(Position.x, Position.y, RADIUS * 4, RADIUS * 4);
}

void Goal::Draw(Texture2D& texture)
{
	DrawTextureV(texture, Position, WHITE);
}
