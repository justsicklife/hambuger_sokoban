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
		
		virtual bool isIngredient() {
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
			//pge->FillRect(pos * size, size, olc::WHITE
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

		bool isIngredient() {
			return true;
		}
	};

	struct block_bun : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			//pge->FillRect(pos * size, size, olc::RED);
			pge->DrawString(pos * size, "bun", olc::Pixel(245, 167, 66));
		}

		bool Push(Direction from) override
		{
			return true;
		}

		bool isIngredient() {
			return true;
		}
	};

	struct block_patty : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			//pge->FillRect(pos * size, size, olc::RED);
			pge->DrawString(pos * size, "patty", olc::Pixel(245, 108, 66));
		}

		bool Push(Direction from) override
		{
			return true;
		}

		bool isIngredient() {
			return true;
		}
	};

	struct block_tomato : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			//pge->FillRect(pos * size, size, olc::RED);
			pge->DrawString(pos * size, "tomato", olc::Pixel(255, 30, 5));
		}

		bool Push(Direction from) override
		{
			return true;
		}

		bool isIngredient() {
			return true;
		}
	};

	struct block_cheese : public block
	{
		void DrawSelf(olc::PixelGameEngine* pge, const olc::vi2d& pos, const olc::vi2d& size, const olc::Renderable& skin) override
		{
			//pge->FillRect(pos * size, size, olc::RED);
			pge->DrawPartialSprite(pos * size, skin.Sprite(), olc::vi2d(5, 0) * size, size);
			//pge->DrawString(pos * size, "cheese", olc::Pixel(242, 191, 7));
		}

		bool Push(Direction from) override
		{
			return true;
		}

		bool isIngredient() {
			return true;
		}
	};
}

