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

		map->Initialize();

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
		inputState = input->Update(pge);
		
	}
	void Game::LateUpdate()
	{
		olc::vi2d playerPos = map->LateUpdate(inputState);

		PlayerInfo playerInfo = this->player->playerInfo;

		if (inputState.direction != Direction::NONE) {
			playerInfo.facing = inputState.direction;
		}

		playerInfo.pos = playerPos;

		player->LateUpdate(playerInfo);
	}
	void Game::Render()
	{
		renderer->RenderMap(pge,map);
		renderer->RenderPlayer(pge, player, map);
	}
}