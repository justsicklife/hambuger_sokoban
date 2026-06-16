#include "Input.h"

namespace jh {
	
	InputState Input::Update(olc::PixelGameEngine* pge)
	{

		InputState inputState = {};

		Direction dir = GetMoveDirection(pge);
		
		bool isShiftHeld = GetShiftHeld(pge);

		inputState.direction = dir;
		inputState.directionMode = isShiftHeld;

		return inputState;
	}

	Direction Input::GetMoveDirection(olc::PixelGameEngine* pge)
	{

		Direction dir = Direction::NONE;

		if (pge->GetKey(olc::Key::W).bPressed) {
			dir = Direction::NORTH;
		}

		if (pge->GetKey(olc::Key::S).bPressed) {
			dir = Direction::SOUTH;
		}

		if (pge->GetKey(olc::Key::A).bPressed) {
			dir = Direction::WEST;
		}

		if (pge->GetKey(olc::Key::D).bPressed) {
			dir = Direction::EAST;
		}

		return dir;
	}

	bool Input::GetShiftHeld(olc::PixelGameEngine* pge)
	{
		bool isShiftHeld = false;

		if (pge->GetKey(olc::Key::SHIFT).bHeld) {
			isShiftHeld = true;
		}

		return isShiftHeld;
	}
}