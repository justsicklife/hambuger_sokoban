#include "Input.h"

namespace jh {

	Direction Input::GetMoveDirection(olc::PixelGameEngine* pge)
	{

		bPushing = false;
		dirPush = Direction::NONE;

		if (pge->GetKey(olc::Key::W).bPressed) {
			dirPush = Direction::NORTH;
			bPushing = true;
		}

		if (pge->GetKey(olc::Key::S).bPressed) {
			dirPush = Direction::SOUTH;
			bPushing = true;
		}

		if (pge->GetKey(olc::Key::A).bPressed) {
			dirPush = Direction::WEST;
			bPushing = true;
		}

		if (pge->GetKey(olc::Key::D).bPressed) {
			dirPush = Direction::EAST;
			bPushing = true;
		}
	}
}