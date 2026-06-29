#pragma once
#include "olcPixelGameEngine.h"
#include "Block.h"
#include "Input.h"

namespace jh {

	class Player;

	class Map
	{
	public:
		Map();
		~Map();

		std::string sLevel =
			"################"
			"#..............#"
			"#...B...B......#"
			"#.......T...|..#"
			"#...P...T...|..#"
			"#...........|..#"
			"#......---.....#"
			"#.5............#"
			"#......C.......#"
			"#.+++..........#"
			"#.........#.@..#"
			"#.-.......#.@..#"
			"#......+....@..#"
			"#..............#"
			"################";

		olc::vf2d vLevelSize = { 16,15 };
		olc::vf2d vBlockSize = { 16,16 };

		//olc::vi2d vPlayer;
		std::vector<std::unique_ptr<block>> vLevel;

		int id(const olc::vi2d& pos) const
		{
			return pos.y * vLevelSize.x + pos.x;
		}

		void Initialize(Player* player);
		/// <summary>
		/// 업데이트에서 입력을 받고 
		/// 입력에 맞는 행동을 하는 메서드
		/// </summary>
		/// <param name="inputState"></param>
		olc::vi2d LateUpdate(InputState inputState, Player* player);
	private:
	
	};
}