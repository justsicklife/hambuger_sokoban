#pragma once
#include "Direction.h"
#include "olcPixelGameEngine.h"

namespace jh {
	struct InputState
	{
		Direction direction = Direction::NONE;

		// true 방향 조절 모드
		// false 일반 이동 모드
		bool directionMode = false;

		bool eat = false;
		bool spit = false;
		bool undo = false;
		bool reset = false;
	};

	class Input
	{
	public:
		InputState Update(olc::PixelGameEngine* pge);
	private:

		// 이동하면 방향을 반환 하는 메서드
		Direction GetMoveDirection(olc::PixelGameEngine* pge);

		bool GetShiftHeld(olc::PixelGameEngine* pge);
	};
}