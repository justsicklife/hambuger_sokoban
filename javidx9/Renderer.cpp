#include "Renderer.h"

namespace jh {
	void Renderer::Initialize()
	{
		gfxTiles.Load("./assets/blocks.png");
	}

	void Renderer::Render(olc::PixelGameEngine* pge, Map* map)
	{
		// 화면 초기화
		pge->Clear(olc::BLACK);

		olc::vi2d vTilePos = { 0,0 };

		for (vTilePos.y = 0; vTilePos.y < map->vLevelSize.y; vTilePos.y++)
		{
			for (vTilePos.x = 0; vTilePos.x < map->vLevelSize.x; vTilePos.x++)
			{
				auto& b = map->vLevel[map->id(vTilePos)];

				if (b) {
					b->DrawSelf(pge, vTilePos, map->vBlockSize, gfxTiles);
				}
			}
		}
	}
}