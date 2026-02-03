#include "Actor.h"
#include "Util/Util.h"
#include "Render/Renderer.h"
#include <iostream>
#include <Windows.h>

namespace Wanted
{
	Actor::Actor(const char image, 
		const Vector2& position,
		Color color)
		: image(image), position(position), color(color)
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
		// Renderer에 그리기 요청.
		Renderer::Draw(position, color, image);
	}

	void Actor::SetPosition(const Vector2& newPosition)
	{
		// Renderer에 빈칸 그리기 요청.
		Renderer::Draw(position, ' ');

		// 새로운 위치 설정.
		position = newPosition;
	}
}