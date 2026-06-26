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

		olc::vi2d pos = player->playerInfo.pos;

		olc::vi2d size = map->vBlockSize;

		// 플레이어 좌표에 있는 것을 가져옴
		auto& b = map->vLevel[map->id(pos)];

		int a = 10;

		if (b != nullptr) {
			pge->FillRect(pos * size, size, olc::WHITE);

			switch (player->playerInfo.facing)
			{
			case Direction::NORTH:
				pge->DrawString(pos * size, "NORTH", olc::RED, 1);
				break;
			case Direction::EAST:
				pge->DrawString(pos * size, "EAST", olc::RED, 1);
				break;
			case Direction::SOUTH:
				pge->DrawString(pos * size, "SOUTH", olc::RED, 1);
				break;
			case Direction::WEST:
				pge->DrawString(pos * size, "WEST", olc::RED, 1);
				break;
			default :
				pge->DrawString(pos * size, "NONE", olc::RED, 1);
				break;
			}

		}

	}
}