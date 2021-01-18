#include "juego.h"
#include "tirachinas.h"
#include "globo.h"

#include <raylib.h>
#include <stdexcept>
#include <vector>
#include <random>
#include <cmath>

#define FPS 60
#define LIMIT_FOR_CHECKING_X 45
#define LIMIT_FOR_CHECKING_Y 66

Juego::Juego(const Vector2& screen) : screen(screen), globosReventados(0)
{}

void Juego::run()
{
	// --- INIT ---
	InitWindow(this->screen.x, this->screen.y, "Juego Globos");
	SetTargetFPS(FPS);
	// Player
	Tirachinas player({this->screen.x / 2, this->screen.y / 2});
	auto playerTexture = LoadTexture("mira.png");
	// Globos
	std::vector<Globo> globos;
	auto textureGlobo = LoadTexture("globo.png");
	// Background
	auto backgroundImg = LoadImage("cielo.png");
	this->resizeImage(&backgroundImg, this->screen.x, this->screen.y);
	auto textureBackground = LoadTextureFromImage(backgroundImg);

	while (!WindowShouldClose()) // --- GAME LOOP ---
	{
		// Logic
		player.setPos(GetMousePosition());

		if(globos.size() < 3)
		globos.push_back(Globo({ this->random(), this->screen.y - 30 }));

		int i = 0;
		for (auto& globo : globos)
		{
			globo.setPos({ globo.getPos().x, globo.getPos().y - 5 });
			// Check if the player shooted a balloon
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				if (std::abs(player.getPos().x - globo.getPos().x) < LIMIT_FOR_CHECKING_X)
				{
					if (std::abs(player.getPos().y - globo.getPos().y) < LIMIT_FOR_CHECKING_Y)
					{
						globos.erase(globos.begin() + i);
						printf("Reventado: %d\n", i);
						++this->globosReventados;
						break;
					}
				}
			}
			// Check if the balloon goes away from the screen (y axis)
			if (globo.getPos().y < 0)
			{
				globos.erase(globos.begin() + i);
				break;
			}
			++i;
		}
		// Draw
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		DrawTexture(textureBackground, 0, 0, RAYWHITE);
		DrawTextureV(playerTexture, { player.getPos().x - 170 / 2, player.getPos().y - 170 / 2 }, RAYWHITE);
		for (const auto& globo : globos)
		{
			DrawTextureV(textureGlobo, globo.getPos(), RAYWHITE);
		}
		DrawText(TextFormat("%d", this->globosReventados), this->screen.x - 60, 30, 30, RED);

		EndDrawing();
	}
	UnloadTexture(textureBackground);
	UnloadTexture(playerTexture);
	UnloadTexture(textureGlobo);
}

void Juego::resizeImage(Image* img, int base, int heigh)
{
	try
	{
		ImageResizeNN(img, base, heigh);
	}
	catch (std::out_of_range& e)
	{
		printf("EXCEPTION: %s", e.what());
	}
}

float Juego::random()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> urd(0, this->screen.x);
	return urd(mt);
}

Juego::~Juego()
{
	CloseWindow();
}