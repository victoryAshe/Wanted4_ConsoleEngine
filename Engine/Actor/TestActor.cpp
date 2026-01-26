#include "TestActor.h"
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

	std::cout << "TestActor::Tick().delataTime: " << deltaTime
		<< ", FPS: " << (1.0f / deltaTime) << ".\n";
}

void TestActor::Draw()
{
	Actor::Draw();
}
