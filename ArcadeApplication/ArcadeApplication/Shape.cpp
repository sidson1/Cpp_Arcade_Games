#include "Shape.h"

Vec2D Shape::GetCenterPoint() const
{
	return Vec2D();
}

void Shape::MoveBy(const Vec2D& deltaOffset)
{
	for (Vec2D& point : mPoints)
	{
		point += deltaOffset;
	}
}