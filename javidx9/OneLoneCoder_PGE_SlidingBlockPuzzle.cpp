#define OLC_PGE_APPLICATION
#include  "olcPixelGameEngine.h"
#include "Game.h"

//constexpr int NORTH = 0;
//constexpr int EAST = 1;
//constexpr int SOUTH = 2;
//constexpr int WEST = 3;


class BlockPuzzle : public olc::PixelGameEngine
{
public :
	BlockPuzzle() {
		sAppName = "BlockPuzzle";
	}

public:

	void LoadLevel(int n) {

	}

	bool OnUserCreate() override {
		mGame = new jh::Game(this);

		mGame->Initialize();

		LoadLevel(0);
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {

		mGame->Update();

		if (GetKey(olc::Key::R).bPressed) {
			LoadLevel(0);
		}

		mGame->LateUpdate();

		mGame->Render();

		return true;
	}
	private:
		jh::Game* mGame;

};

int main() {
	BlockPuzzle demo;
	if (demo.Construct(256, 240, 4, 4)) {
		demo.Start();
	}
	return 0;
}