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
			// 이미 BeginPlay 호출된 actor는 건너뛰기.
			if (actor->HasBeganPlay())
			{
				continue;
			}

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

	void Level::AddNewActor(Actor* newActor)
	{
		// TODO: 나중에 Frame 처리 고려해서 따로 추가 작업 해야함.
		actors.emplace_back(newActor);
	}

}