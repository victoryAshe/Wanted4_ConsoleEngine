#pragma once

namespace Wanted
{
	class Actor
	{
	public:
		Actor();
		virtual ~Actor();

		// GamePlay Event.
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

	protected:
	};

}

