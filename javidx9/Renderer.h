#pragma once
#include "olcPixelGameEngine.h"
#include "Map.h"

namespace jh {
	class Renderer
	{
	public:
		void Initialize();
		void Render(olc::PixelGameEngine* pge, Map* map);
	private:
		olc::Renderable gfxTiles;

	};
}