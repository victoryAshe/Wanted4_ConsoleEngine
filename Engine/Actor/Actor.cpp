#include "Actor.h"
#include "iostream"
#include "Windows.h"

namespace Wanted
{
	Actor::Actor(const char image, const Vector2& position)
		: image(image), position(position)
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::BeginPlay() 
	{
		// Event 받은 후에는 flag 설정.
		hasBeganPlay = true;
	}

	void Actor:: Tick(float deltaTime)
	{
	}

	void Actor:: Draw()
	{
		// Actor의 현재 position으로 console position 위치 이동.
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);

		// 이동한 positoin에 글자 그리기.
		std::cout << image;
	}

	void Actor::SetPosition(const Vector2& newPosition)
	{
		// Actor의 position으로 console position 위치 이동.
		COORD coord = {};
		coord.X = static_cast<short>(position.x);
		coord.Y = static_cast<short>(position.y);

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);

		// 해당 위치의 글자 값 지우기. (빈 칸 그리기).
		std::cout << ' ';

		// 새로운 위치 설정.
		position = newPosition;
	}

}