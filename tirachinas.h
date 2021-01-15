#pragma once

#include "entidad.h"
#include <raylib.h>

class Tirachinas : public Entidad
{
public:
	Tirachinas(const Vector2& pos);
	~Tirachinas();
	int getR() const;
private:
	const int R = 20;
};
