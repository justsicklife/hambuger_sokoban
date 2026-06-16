#include "Input.h"

namespace jh {

	Direction Input::GetMoveDirection(olc::PixelGameEngine* pge)
	{

		Direction dirPush = Direction::NONE;

		if (pge->GetKey(olc::Key::W).bPressed) {
			dirPush = Direction::NORTH;
		}

		if (pge->GetKey(olc::Key::S).bPressed) {
			dirPush = Direction::SOUTH;
		}

		if (pge->GetKey(olc::Key::A).bPressed) {
			dirPush = Direction::WEST;
		}

		if (pge->GetKey(olc::Key::D).bPressed) {
			dirPush = Direction::EAST;
		}

		return dirPush;
	}
}