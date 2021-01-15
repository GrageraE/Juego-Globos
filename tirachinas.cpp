#include "tirachinas.h"

#include <raylib.h>

Tirachinas::Tirachinas(const Vector2& pos) : Entidad(pos)
{}

int Tirachinas::getR() const
{
	return this->R;
}

Tirachinas::~Tirachinas()
{}