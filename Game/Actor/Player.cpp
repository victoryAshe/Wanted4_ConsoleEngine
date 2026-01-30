#include "Player.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include "Actor/Box.h"
#include "Level/Level.h"
#include <iostream>
#include <Windows.h>

using namespace Wanted;

Player::Player()
	//:Actor()
	:super('P', Vector2(0,3), Color::Red) // super: RTTI에서 지정해준 부모 객체.
{
	// Render prirority 충분히 높게 설정.
	sortingOrder = 10;
}

void Player::BeginPlay()
{
	// 상위 함수 호출.
	// C++는 부모 함수 가리키는 pointer가 없음.
	super::BeginPlay();

	//std::cout << "TestActor::BeginPlay().\n";
}

void Player::Tick(float deltaTime)
{
	Actor::Tick(deltaTime);

	if (Input::Get().GetKeyDown('Q'))
	{
		// TODO: Game Engine 종료 요청.
		Engine::Get().QuitEngine();
	}

	// "Space" key => Create Box
	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		// Create Box
		if (owner)
		{
			owner->AddNewActor(new Box(GetPosition()));
		}
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

	if (Input::Get().GetKey(VK_UP) && GetPosition().y > 0)
	{
		Vector2 newPosition = GetPosition();
		newPosition.y -= 1;
		SetPosition(newPosition);
	}

	if (Input::Get().GetKey(VK_DOWN) && GetPosition().y < 10)
	{
		Vector2 newPosition = GetPosition();
		newPosition.y += 1;
		SetPosition(newPosition);
	}

	//std::cout << "TestActor::Tick().delataTime: " << deltaTime
	//	<< ", FPS: " << (1.0f / deltaTime) << ".\n";
}

void Player::Draw()
{
	Actor::Draw();
}
