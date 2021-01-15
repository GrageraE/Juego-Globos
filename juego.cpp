#include "juego.h"
#include "tirachinas.h"

#include <raylib.h>

#define FPS 60

Juego::Juego(const Vector2& screen) : screen(screen)
{}

void Juego::run()
{
	InitWindow(this->screen.x, this->screen.y, "Juego Globos");
	SetTargetFPS(FPS);
	Tirachinas player({this->screen.x / 2, this->screen.y / 2});
	while (!WindowShouldClose()) // --- GAME LOOP ---
	{
		// Logic
		player.setPos(GetMousePosition());
		// Draw
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		DrawCircleV(player.getPos(), player.getR(), MAROON);

		EndDrawing();
	}
}

Juego::~Juego()
{
	CloseWindow();
}