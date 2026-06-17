#pragma once
#include "Direction.h"
#include  "olcPixelGameEngine.h"

namespace jh {

	struct block {
		block()
		{

		}

		virtual void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin)
		{

		}

		virtual bool Push(Direction from) {
			return true;
		}

		virtual void Move() {

		}

		virtual bool IsPlayer() {
			return false;
		}

	};

	struct block_solid : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			//pge->FillRect(pos * size, size, olc::BLUE);
			pge->DrawPartialSprite(pos * size, skin.Sprite(), olc::vi2d(0, 0) * size, size);

		}

		bool Push(Direction from) override
		{
			return false;
		}

	};

	struct block_player : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			pge->FillRect(pos * size, size, olc::WHITE);
		}

		bool Push(Direction from) override
		{
			return true;
		}

		bool IsPlayer() {
			return true;
		}
	};


	struct block_simple : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			//pge->FillRect(pos * size, size, olc::RED);
			pge->DrawPartialSprite(pos * size, skin.Sprite(), olc::vi2d(1, 0) * size, size);
		}

		bool Push(Direction from) override
		{
			return true;
		}
	};

}

