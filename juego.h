#pragma once

#include <raylib.h>

class Juego
{
public:
	Juego(const Vector2& screen);
	~Juego();

	void run();
private:
	Vector2 screen;
};
