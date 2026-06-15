#include "Game.h"

namespace jh {
	

	Game::Game(olc::PixelGameEngine* pge)
	{
		this->pge = pge;
	}

	Game::~Game()
	{
	}

	void Game::Run()
	{	
		Update();
		LateUpdate();
		Render();
	}
	void Game::Initialize()
	{

		gfxTiles.Load("./assets/blocks.png");

		vLevel.clear();

		for (int y = 0; y < vLevelSize.y; y++) {
			for (int x = 0; x < vLevelSize.x; x++) {
				switch (sLevel[y * vLevelSize.x + x]) {
				case '#':
					// std::make_unique<block_solid>()
					// std::unique_ptr<block_solid> ptr(new block_solid(매게변수...)))
					vLevel.emplace_back(std::make_unique<block_solid>());
					break;
				case 'P':
					vLevel.emplace_back(std::make_unique<block_player>());
					vPlayer = { x,y };
					break;

				case '+':
					vLevel.emplace_back(std::make_unique<block_simple>());
					break;
				default:
					vLevel.emplace_back(nullptr);
					break;
				}
			}
		}

	}
	void Game::Update()
	{

		// Input 에 GetMoveDirectino 을 박으면 생기는 일
		// 1. 일단 매게변수로 pge 를 받음 이건 OK
		// 2. bPusing , dirPush 이걸 어떻게 하는 게 문제다
		// 3. 문제가 되는 이유 Input 하고 Game 에 중복된 두개의 변수가있음
		// 4. 이걸 어떻게 Input -> Game 까지 연결할까 이게 문제다
		// 5. 포인터 매게변수로 넣는건 좀 더럽고 
		// 6. 아니면 구조체로 묶어서 반환하는 것도 좀 그렇고

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
	void Game::LateUpdate()
	{

		if (bPushing) {
			// 현재 플레이어 위치
			olc::vi2d vBlock = vPlayer;

			// 미는걸 허락하는지
			bool bAllowPush = false;
			bool bTest = true;

			while (bTest) {
				// 현재 위치에 블록이 있다면
				if (vLevel[id(vBlock)] != nullptr) {
					if (vLevel[id(vBlock)]->Push((Direction)(((int)dirPush + 2) % 4))) {
						// Block allows push
						switch (dirPush) {
						case Direction::NORTH:
							vBlock.y--;
							break;
						case Direction::SOUTH:
							vBlock.y++;
							break;
						case Direction::EAST:
							vBlock.x++;
							break;
						case Direction::WEST:
							vBlock.x--;
							break;
						}
					}
					// 벽과 만나면 bTest 끝
					else {
						bTest = false;
					}
				}
				// 현재 위치에 블록이 없다면
				else {
					// 미는걸 허락함
					bAllowPush = true;
					bTest = false;
				}
			}

			// 미는 걸 허락한다면
			if (bAllowPush) {
				// 민 블록의 위치와 : 플레이어의 위치가 다르다면
				while (vBlock != vPlayer)
				{
					olc::vi2d vSource = vBlock;

					switch (dirPush) {
					case Direction::NORTH:
						vSource.y++;
						break;
					case Direction::SOUTH:
						vSource.y--;
						break;
					case Direction::EAST:
						vSource.x--;
						break;
					case Direction::WEST:
						vSource.x++;
						break;
					}

					if (vLevel[id(vSource)] != nullptr) vLevel[id(vSource)]->Move();
					// 전과 후를 바꿔줌
					std::swap(vLevel[id(vSource)], vLevel[id(vBlock)]);

					vBlock = vSource;
				}

				switch (dirPush) {
				case Direction::NORTH:
					vPlayer.y--;
					break;
				case Direction::SOUTH:
					vPlayer.y++;
					break;
				case Direction::EAST:
					vPlayer.x++;
					break;
				case Direction::WEST:
					vPlayer.x--;
					break;
				}
			}

		}

	}
	void Game::Render()
	{
		// 화면 초기화
		pge->Clear(olc::BLACK);

		olc::vi2d vTilePos = { 0,0 };

		for (vTilePos.y = 0; vTilePos.y < vLevelSize.y; vTilePos.y++)
		{
			for (vTilePos.x = 0; vTilePos.x < vLevelSize.x; vTilePos.x++)
			{
				auto& b = vLevel[id(vTilePos)];

				if (b) {
					b->DrawSelf(pge, vTilePos, vBlockSize, gfxTiles);
				}
			}
		}
	}
}