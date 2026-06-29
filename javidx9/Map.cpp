#include "Map.h"
#include "Player.h"

namespace jh {
	Map::Map()
	{
	}
	Map::~Map()
	{
	}
	void Map::Initialize(Player* player)
	{
		vLevel.clear();

		for (int y = 0; y < vLevelSize.y; y++) {
			for (int x = 0; x < vLevelSize.x; x++) {
				switch (sLevel[y * vLevelSize.x + x]) {
				case '#':
					// std::make_unique<block_solid>()
					// std::unique_ptr<block_solid> ptr(new block_solid(매게변수...)))
					vLevel.emplace_back(std::make_unique<block_solid>());
					break;
				case 'P':
					vLevel.emplace_back(std::make_unique<block_player>());
					player->playerInfo.pos = { x,y };
					break;

				case 'T':
					vLevel.emplace_back(std::make_unique<block_tomato>());
					break;
				case 'C':
					vLevel.emplace_back(std::make_unique<block_cheese>());
					break;
				case 'B':
					vLevel.emplace_back(std::make_unique<block_bun>());
					break;
				default:
					vLevel.emplace_back(nullptr);
					break;
				}
			}
		}
	}
	
	olc::vi2d Map::LateUpdate(InputState inputState,Player* player)
	{
		if (inputState.direction != Direction::NONE) {
			// 현재 플레이어 위치
			olc::vi2d vBlock = player->playerInfo.pos;

			// 미는걸 허락하는지
			bool bAllowPush = false;

			bool bTest = true;

			while (bTest) {
				// 현재 위치에 블록이 있다면
				if (vLevel[id(vBlock)] != nullptr) {
					if (vLevel[id(vBlock)]->Push((Direction)(((int)inputState.direction + 2) % 4))) {
						// Block allows push
						switch (inputState.direction) {
						case Direction::NORTH:
							vBlock.y--;
							break;
						case Direction::SOUTH:
							vBlock.y++;
							break;
						case Direction::EAST:
							vBlock.x++;
							break;
						case Direction::WEST:
							vBlock.x--;
							break;
						}
					}
					// 벽과 만나면 bTest 끝
					else {
						bTest = false;
					}
				}
				// 현재 위치에 블록이 없다면
				else {
					// 미는걸 허락함
					bAllowPush = true;
					bTest = false;
				}
			}

			// 미는 걸 허락한다면
			if (bAllowPush) {
				// 민 블록의 위치와 : 플레이어의 위치가 다르다면
				while (vBlock != player->playerInfo.pos)
				{
					olc::vi2d vSource = vBlock;

					switch (inputState.direction) {
					case Direction::NORTH:
						vSource.y++;
						break;
					case Direction::SOUTH:
						vSource.y--;
						break;
					case Direction::EAST:
						vSource.x--;
						break;
					case Direction::WEST:
						vSource.x++;
						break;
					}

					if (vLevel[id(vSource)] != nullptr) vLevel[id(vSource)]->Move();
					// 전과 후를 바꿔줌
					std::swap(vLevel[id(vSource)], vLevel[id(vBlock)]);

					vBlock = vSource;
				}

				switch (inputState.direction) {
				case Direction::NORTH:
					player->playerInfo.pos.y--;
					break;
				case Direction::SOUTH:
					player->playerInfo.pos.y++;
					break;
				case Direction::EAST:
					player->playerInfo.pos.x++;
					break;
				case Direction::WEST:
					player->playerInfo.pos.x--;
					break;
				}
			}

		}
		return player->playerInfo.pos;
	}

}