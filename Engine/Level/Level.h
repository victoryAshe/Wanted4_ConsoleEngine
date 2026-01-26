#pragma once

// STL: Standart Template Library - C++에서 기본 제공
// 크기가 알아서 변경되는 배열 (동적 배열)
#include <vector>


namespace Wanted 
{
	// Class Forward Declaration
	class Actor;

	// 담당 임무: Level에 있는 모든 Actor(물체 관리)
	class Level
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
