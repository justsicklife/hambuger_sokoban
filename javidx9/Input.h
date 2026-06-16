#pragma once
#include "Direction.h"
#include "olcPixelGameEngine.h"

namespace jh {
	class Input
	{
	public:
		// 이동하면 방향을 반환 하는 메서드
		Direction GetMoveDirection(olc::PixelGameEngine* pge);;
	private:
		
	};
}