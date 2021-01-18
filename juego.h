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
	void resizeImage(Image* img, int base, int heigh);
	float random();
	unsigned globosReventados;
};
