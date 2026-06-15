#pragma once
#include  "olcPixelGameEngine.h"
#include "Block.h"
#include "Direction.h"

namespace jh {

	class Game
	{
	public:
		Game(olc::PixelGameEngine* pge);
		~Game();

		std::string sLevel =
			"################"
			"#..............#"
			"#...+...+......#"
			"#.......+...|..#"
			"#...P...+...|..#"
			"#...........|..#"
			"#......---.....#"
			"#.5............#"
			"#..............#"
			"#.+++..........#"
			"#.........#.@..#"
			"#.-.......#.@..#"
			"#......+....@..#"
			"#..............#"
			"################";

		bool bPushing = false;
		Direction dirPush;

		void Run();
		void Initialize();
		void Update();
		void LateUpdate();
		void Render();
	private:
		olc::PixelGameEngine* pge;

		olc::vf2d vLevelSize = { 16,15 };
		olc::vf2d vBlockSize = { 16,16 };

		olc::vi2d vPlayer;
		std::vector<std::unique_ptr<block>> vLevel;

		olc::Renderable gfxTiles;

		int id(const olc::vi2d& pos) const
		{
			return pos.y * vLevelSize.x + pos.x;
		}
	};
}