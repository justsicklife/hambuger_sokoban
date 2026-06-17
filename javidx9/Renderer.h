#pragma once
#include "olcPixelGameEngine.h"
#include "Map.h"
#include "Player.h"

namespace jh {
	class Renderer
	{
	public:
		void Initialize();
		void RenderMap(olc::PixelGameEngine* pge, Map* map);
		void RenderPlayer(olc::PixelGameEngine* pge, Player* player,Map* map);
	private:
		olc::Renderable gfxTiles;

	};
}