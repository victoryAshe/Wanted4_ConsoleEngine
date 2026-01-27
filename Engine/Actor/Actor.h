#pragma once

#include "Common/Common.h"

namespace Wanted
{
	class WANTED_API Actor
	{
	public:
		Actor();
		virtual ~Actor();

		// GamePlay Event.
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// Getter.
		inline bool HasBeganPlay() const { return hasBeganPlay; }
		bool IsActive() const
		{
			return isActive && !destroyRequested;
		}

		//inline bool DestroyRequested() const { return destroyRequested; }

	protected:
		// 이미 BeginPlay event를 받았는지 여부.
		bool hasBeganPlay = false;

		// 활성화 상태 여부.
		bool isActive = true;

		// 현재 frame에 삭제 요청 받았는지 여부.
		bool destroyRequested = false;
	};

}

