#include "TestActor.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include <iostream>
#include <Windows.h>

using namespace Wanted;

TestActor::TestActor()
	//:Actor()
	:super('T', Vector2(0,3)) // super: RTTI에서 지정해준 부모 객체.
{
}

void TestActor::BeginPlay()
{
	// 상위 함수 호출.
	// C++는 부모 함수 가리키는 pointer가 없음.
	super::BeginPlay();

	//std::cout << "TestActor::BeginPlay().\n";
}

void TestActor::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// TODO: Game Engine 종료 요청.
		Wanted::Engine::Get().QuitEngine();
	}

	// 이동
	if (Input::Get().GetKey(VK_RIGHT) && GetPosition().x <20)
	{
		Vector2 newPosition = GetPosition();
		newPosition.x += 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_LEFT) && GetPosition().x > 0)
	{
		Vector2 newPosition = GetPosition();
		newPosition.x -= 1;
		SetPosition(newPosition);
	}

	//std::cout << "TestActor::Tick().delataTime: " << deltaTime
	//	<< ", FPS: " << (1.0f / deltaTime) << ".\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
