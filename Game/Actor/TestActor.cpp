#include "TestActor.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include <iostream>

void TestActor::BeginPlay()
{
	// 상위 함수 호출.
	// C++는 부모 함수 가리키는 pointer가 없음.
	Actor::BeginPlay();

	std::cout << "TestActor::BeginPlay().\n";
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// TODO: Game Engine 종료 요청.
		Wanted::Engine::Get().QuitEngine();
	}

	std::cout << "TestActor::Tick().delataTime: " << deltaTime
		<< ", FPS: " << (1.0f / deltaTime) << ".\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
