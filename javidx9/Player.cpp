#include "Player.h"

namespace jh {

	void Player::LateUpdate(PlayerInfo playerInfo)
	{
		this->playerInfo = playerInfo;
	}

	void Player::Eat(Map* map, Player* player, InputState inputState)
	{
		olc::vi2d vPrevPlayer = this->playerInfo.pos;
		olc::vi2d vCurPlayer = vPrevPlayer;

		switch (playerInfo.facing) {
		case Direction::NORTH:
			vCurPlayer.y--;
			break;
		case Direction::SOUTH:
			vCurPlayer.y++;
			break;
		case Direction::EAST:
			vCurPlayer.x++;
			break;
		case Direction::WEST:
			vCurPlayer.x--;
			break;
		}

		// 먹기 전에 위치 
		map->vLevel[map->id(vPrevPlayer)] = nullptr;

		// 먹은 후에 위치 
		map->vLevel[map->id(vCurPlayer)] = std::make_unique<block_player>();

		player->playerInfo.pos = vCurPlayer;

   		this->playerInfo.pos = vCurPlayer;
	}
	
}