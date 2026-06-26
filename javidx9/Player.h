#pragma once
#include "olcPixelGameEngine.h"
#include "Direction.h"
#include <vector>
#include "block.h"
#include "Map.h"

namespace jh {

	struct PlayerInfo {
		// 플레이어의 위치를 나타냄
		olc::vi2d pos; 
		// 플레이어의 방향을 나타냄
		Direction facing;
		// 먹은 재료 들
		std::vector<block> stomach;
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
		/// 변경 사항 : 메서드 이름 변경 해야 할듯 
		/// </summary>
		void LateUpdate(PlayerInfo playerInfo);

		/// <summary>
		/// 먹는 키를 누르면 발동 되는 LateUpdate 단에서 실행 되는 메소드
		/// 
		/// </summary>
		/// <param name="map"></param>
		/// <param name="inputState"></param>
		void Eat(Map* map, InputState inputState);
	private:
		
	};
}