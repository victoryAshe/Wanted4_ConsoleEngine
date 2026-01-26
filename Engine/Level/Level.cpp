#include "Level.h"
#include "Actor/Actor.h"

namespace Wanted {
	Level::Level()
	{

	}

	Level::~Level()
	{
		// memory 정리.
		for (Actor*& actor : actors)
		{
			if (actor)
			{
				delete actor;
				actor = nullptr;
			}
		}

		// 배열 초기화.
		actors.clear();
	}

	void Level::BeginPlay() 
	{
		// Actor에 event 흘리기.
		for (Actor*& actor : actors)
		{
			// TODO: 이미 BeginPlay 호출된 actor는 건너뛰기.
			actor->BeginPlay();
		}
	}
	void Level::Tick(float deltaTime)
	{
		// Actor에 event 흘리기.
		for (Actor*& actor : actors)
		{
			actor->Tick(deltaTime);
		}
	}

	void Level::Draw()
	{
		// Actor에 event 흘리기.
		for (Actor*& actor : actors)
		{
			actor->Draw();
		}

	}

}