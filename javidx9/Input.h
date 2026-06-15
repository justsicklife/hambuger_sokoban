#pragma once
#include "Direction.h"
#include "olcPixelGameEngine.h"

namespace jh {
	class Input
	{
	public:
		// 이동하면 방향을 반환 하는 메서드
		Direction GetMoveDirection(olc::PixelGameEngine* pge);
		// 밀면 true 
		bool bPushing = false;
		// 방향 값을 갖는 필드
		Direction dirPush;
	private:
		
	};
}