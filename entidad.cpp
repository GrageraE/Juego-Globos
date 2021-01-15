#include "entidad.h"

#include <raylib.h>

Entidad::Entidad(const Vector2& pos) : pos(pos)
{}

Vector2 Entidad::getPos() const
{
	return this->pos;
}

void Entidad::setPos(const Vector2& pos)
{
	this->pos = pos;
}

Entidad::~Entidad()
{}