#include "Background.h"

#include "Screen.h"

namespace flappyBird
{
	void updateParallax(ParallaxBackground& background)
	{
		background.scrollingBack -= 50.0f * GetFrameTime();
		background.scrollingMid -= 100.0f * GetFrameTime();
		background.scrollingFore -= 150.0f * GetFrameTime();

		float scale = (float)screenHigh / background.back.height;

		if (background.scrollingBack <= -background.back.width * scale)
		{
			background.scrollingBack = 0.0f;
		}

		if (background.scrollingMid <= -background.mid.width * scale)
		{
			background.scrollingMid = 0.0f;
		}

		if (background.scrollingFore <= -background.front.width * scale)
		{
			background.scrollingFore = 0.0f;
		}
	}

	void drawParallax(ParallaxBackground& background)
	{
		float scale = (float)screenHigh / background.back.height;

		float scaledWidthBack = background.back.width * scale;
		float scaledWidthMid = background.mid.width * scale;
		float scaledWidthFore = background.front.width * scale;

		DrawTextureEx(background.back, Vector2{ background.scrollingBack, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(background.back, Vector2{ scaledWidthBack + background.scrollingBack, 0.0f }, 0.0f, scale, WHITE);

		DrawTextureEx(background.mid, Vector2{ background.scrollingMid, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(background.mid, Vector2{ scaledWidthMid + background.scrollingMid, 0.0f }, 0.0f, scale, WHITE);

		DrawTextureEx(background.front, Vector2{ background.scrollingFore, 0.0f }, 0.0f, scale, WHITE);
		DrawTextureEx(background.front, Vector2{ scaledWidthFore + background.scrollingFore, 0.0f }, 0.0f, scale, WHITE);
	}

	void unloadBackground(ParallaxBackground& background)
	{
		UnloadTexture(background.back);
		UnloadTexture(background.mid);
		UnloadTexture(background.front);
	}
}