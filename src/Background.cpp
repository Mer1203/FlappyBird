#include "Background.h"

#include "Screen.h"

namespace flappyBird
{
	void updateParallax(ParallaxBackground& bg)
	{
		bg.scrollingBack -= 40.0f * GetFrameTime();
		bg.scrollingMid -= 120.0f * GetFrameTime();
		bg.scrollingFore -= 250.0f * GetFrameTime();

		float scale = (float)screenHigh / bg.back.height;

		if (bg.scrollingBack <= -bg.back.width * scale) bg.scrollingBack = 0.0f;
		if (bg.scrollingMid <= -bg.mid.width * scale) bg.scrollingMid = 0.0f;
		if (bg.scrollingFore <= -bg.front.width * scale) bg.scrollingFore = 0.0f;
	}

	void drawParallax(const ParallaxBackground& bg)
	{

		float scale = (float)screenHigh / bg.back.height;

		float scaledWidthBack = bg.back.width * scale;
		float scaledWidthMid = bg.mid.width * scale;
		float scaledWidthFore = bg.front.width * scale;

		DrawTextureEx(bg.back, Vector2{ bg.scrollingBack, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(bg.back, Vector2{ scaledWidthBack + bg.scrollingBack, 0.0f }, 0.0f, scale, WHITE);


		DrawTextureEx(bg.mid, Vector2{ bg.scrollingMid, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(bg.mid, Vector2{ scaledWidthMid + bg.scrollingMid, 0.0f }, 0.0f, scale, WHITE);


		DrawTextureEx(bg.front, Vector2{ bg.scrollingFore, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(bg.front, Vector2{ scaledWidthFore + bg.scrollingFore, 0.0f }, 0.0f, scale, WHITE);
	}

	void unloadBackground(ParallaxBackground& bg)
	{
		UnloadTexture(bg.back);
		UnloadTexture(bg.mid);
		UnloadTexture(bg.front);
	}
}