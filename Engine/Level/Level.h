#pragma once
#pragma warning(disable: 4251)  // 미봉책: Actor*이 Warning을 띄우기 때문에 해당 Warning을 비활성화처리. 어쩔 수 없이 써야함.



// STL: Standart Template Library - C++에서 기본 제공
// 크기가 알아서 변경되는 배열 (동적 배열)
#include <vector>

#include "Common/common.h"

namespace Wanted 
{
	// Class Forward Declaration
	class Actor;

	// 담당 임무: Level에 있는 모든 Actor(물체 관리)
	class WANTED_API Level
	{
	public:
		Level();
		virtual ~Level();

		// GamePlay Event.
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// Actor 추가 함수.
		void AddNewActor(Actor* newActor);


	protected:
		// Actor 배열
		std::vector<Actor*> actors;
	};

}
