#include "Background.h"
namespace flappyBird
{
	void updateParallax(ParallaxBackground& bg)
	{
		bg.scrollingBack -= 0.1f;
		bg.scrollingMid -= 0.5f;
		bg.scrollingFore -= 1.0f;

		// Reiniciar cuando la textura recorra su ancho escalado (x2)
		if (bg.scrollingBack <= -bg.back.width * 2) bg.scrollingBack = 0;
		if (bg.scrollingMid <= -bg.mid.width * 2) bg.scrollingMid = 0;
		if (bg.scrollingFore <= -bg.front.width * 2) bg.scrollingFore = 0;
	}
	void drawParallax(const ParallaxBackground& bg)
	{
		DrawTextureEx(bg.back, (Vector2) { bg.scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(bg.back, (Vector2) { bg.back.width * 2 + bg.scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

		// Capa media
		DrawTextureEx(bg.mid, (Vector2) { bg.scrollingMid, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(bg.mid, (Vector2) { bg.mid.width * 2 + bg.scrollingMid, 0 }, 0.0f, 2.0f, WHITE);

		// Capa frontal
		DrawTextureEx(bg.front, (Vector2) { bg.scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(bg.front, (Vector2) { bg.front.width * 2 + bg.scrollingFore, 0 }, 0.0f, 2.0f, WHITE);
	}
}