#pragma once
#include "olcPixelGameEngine.h"
#include "Block.h"

namespace jh {
	class Map
	{
	public:
		Map();
		~Map();

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

		olc::vf2d vLevelSize = { 16,15 };
		olc::vf2d vBlockSize = { 16,16 };

		olc::vi2d vPlayer;
		std::vector<std::unique_ptr<block>> vLevel;

		int id(const olc::vi2d& pos) const
		{
			return pos.y * vLevelSize.x + pos.x;
		}

		void Initialize();
		void LateUpdate(Direction dirPush);
	private:
	
	};
}