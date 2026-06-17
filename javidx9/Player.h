#pragma once
#include "olcPixelGameEngine.h"
#include "Direction.h"

namespace jh {

	struct PlayerInfo {
		olc::vi2d pos;
		Direction facing;
		// 먹은 재료 들
		// std::stack<> stomach
	};

	/// <summary>
	/// 캐릭터의 정보를 담는 클래스
	/// 캐릭터가 먹은 재료 정보
	/// 캐릭터의 방향 
	/// </summary>
	class Player
	{
	public:

		PlayerInfo playerInfo;

		/// <summary>
		/// player 위치, 방향 초기화 해줌
		/// 설계 : 
		/// </summary>
		void LateUpdate(PlayerInfo playerInfo);
	private:
		
	};
}