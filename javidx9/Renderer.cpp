#include "Renderer.h"

namespace jh {
	void Renderer::Initialize()
	{
		gfxTiles.Load("./assets/blocks.png");
	}

	void Renderer::RenderMap(olc::PixelGameEngine* pge, Map* map)
	{

		// 화면 초기화
		pge->Clear(olc::BLACK);

		olc::vi2d vTilePos = { 0,0 };

		for (vTilePos.y = 0; vTilePos.y < map->vLevelSize.y; vTilePos.y++)
		{
			for (vTilePos.x = 0; vTilePos.x < map->vLevelSize.x; vTilePos.x++)
			{
				auto& b = map->vLevel[map->id(vTilePos)];

				if (b != nullptr && !b->IsPlayer()) {
					b->DrawSelf(pge, vTilePos, map->vBlockSize, gfxTiles);
				}
			}
		}
	}

	void Renderer::RenderPlayer(olc::PixelGameEngine* pge, Player* player,Map* map)
	{

		auto& b = map->vLevel[map->id(player->playerInfo.pos)];

		if (b != nullptr) {
			b->DrawSelf(pge, player->playerInfo.pos, map->vBlockSize, gfxTiles);
		}

	}
}