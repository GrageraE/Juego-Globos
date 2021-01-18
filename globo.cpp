#include "globo.h"
#include <raylib.h>

Globo::Globo(const Vector2& pos, bool state) : Entidad(pos), state(state)
{}

bool Globo::getState() const
{
	return this->state;
}

void Globo::setState(bool state)
{
	this->state = state;
}

Globo::~Globo()
{}
