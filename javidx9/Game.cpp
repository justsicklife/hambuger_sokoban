#include "Game.h"

namespace jh {
	

	Game::Game(olc::PixelGameEngine* pge)
	{
		this->pge = pge;
		this->input = new Input();
		this->map = new Map();
		this->renderer = new Renderer();
		this->player = new Player();
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
		renderer->Initialize();

		map->Initialize(player);

	}
	void Game::Update()
	{
		inputState = input->Update(pge);
	}

	void Game::LateUpdate()
	{
		// 멤버 플레이어 정보 가져옴
		PlayerInfo playerInfo = this->player->playerInfo;

		//player->playerInfo.pos = map->vPlayer;


		// 먹는 키를 누르면 

		if (inputState.eat) {
			player->Eat(map, player,inputState);
		}
		// 쉬프트 누르면 방향 만 변화함
		else if (inputState.directionMode) {
			if (inputState.direction != Direction::NONE) {
				playerInfo.facing = inputState.direction;
			}
			this->player->playerInfo = playerInfo;
		}

		else if(inputState.move) {
			// Push 메서드
			olc::vi2d playerPos = map->LateUpdate(inputState,player);

			// 방향이 존재한다면
			if (inputState.direction != Direction::NONE) {
				// 방향을 초기화 해줌
				playerInfo.facing = inputState.direction;
			}
 
			playerInfo.pos = playerPos;
			this->player->playerInfo = playerInfo;
		}
	}

	void Game::Render()
	{
		renderer->RenderMap(pge,map);
		renderer->RenderPlayer(pge, player, map);
	}
}