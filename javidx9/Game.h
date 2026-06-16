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

		InputState inputState;

		void Run();
		void Initialize();
		void Update();
		void LateUpdate();
		void Render();

	private:
		olc::PixelGameEngine* pge;
		
		Input* input;
		Map* map;
		Renderer* renderer;
	};
}