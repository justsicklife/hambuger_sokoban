#pragma once
#include  "olcPixelGameEngine.h"
#include "Block.h"
#include "Direction.h"
#include "Map.h"
#include "Input.h"
#include "Renderer.h"

namespace jh {

	class Game
	{
	public:
		Game(olc::PixelGameEngine* pge);
		~Game();

		//std::string sLevel =
		//	"################"
		//	"#..............#"
		//	"#...+...+......#"
		//	"#.......+...|..#"
		//	"#...P...+...|..#"
		//	"#...........|..#"
		//	"#......---.....#"
		//	"#.5............#"
		//	"#..............#"
		//	"#.+++..........#"
		//	"#.........#.@..#"
		//	"#.-.......#.@..#"
		//	"#......+....@..#"
		//	"#..............#"
		//	"################";

		Direction dirPush;

		void Run();
		void Initialize();
		void Update();
		void LateUpdate();
		void Render();
	private:
		olc::PixelGameEngine* pge;

		//olc::vf2d vLevelSize = { 16,15 };
		//olc::vf2d vBlockSize = { 16,16 };

		//olc::vi2d vPlayer;
		//std::vector<std::unique_ptr<block>> vLevel;
		// 
		//int id(const olc::vi2d& pos) const
		//{
		//	return pos.y * vLevelSize.x + pos.x;
		//}
		
		Input* input;
		Map* map;
		Renderer* renderer;
	};
}