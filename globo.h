#pragma once

#include "entidad.h"
#include <raylib.h>

class Globo : public Entidad
{
public:
	Globo(const Vector2& pos, bool state = true);
	bool getState() const;
	void setState(bool state);
	~Globo();
private:
	bool state;
	/*
	* true -> Levitando
	* false -> Reventado
	*/
};
