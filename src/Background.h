#pragma once

#include <raylib.h>

namespace flappyBird
{
	struct ParallaxBackground
	{
        Texture2D back;
        Texture2D mid;
        Texture2D front;

        float scrollingBack;
        float scrollingMid;
        float scrollingFore;
	};

    void updateParallax(ParallaxBackground& background);
    void drawParallax(ParallaxBackground& background);
    void unloadBackground(ParallaxBackground& background);
}