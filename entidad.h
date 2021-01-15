#pragma once

#include <raylib.h>

class Entidad
{
public:
	Entidad(const Vector2& pos);
	~Entidad();

	virtual Vector2 getPos() const;
	virtual void setPos(const Vector2& pos);
private:
	Vector2 pos;
};
