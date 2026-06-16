#pragma once
#include "olcPixelGameEngine.h"
#include "Direction.h"

namespace jh {
	/// <summary>
	/// 캐릭터의 정보를 담는 클래스
	/// 캐릭터가 먹은 재료 정보
	/// 캐릭터의 방향 
	/// </summary>
	class Player
	{
	public:
		olc::vi2d pos;
		Direction facing = Direction::SOUTH;
	private:

	};
}