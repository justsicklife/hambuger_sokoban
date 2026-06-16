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

	bool OnUserCreate() override {
		mGame = new jh::Game(this);

		mGame->Initialize();

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override {

		mGame->Run();

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