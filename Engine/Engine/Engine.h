#pragma once

#include "Common/Common.h"

namespace Wanted
{
	// 전방 선언
	class Level;
	class Input;

	// Main game engine class.
	class WANTED_API Engine
	{
	public:
		Engine();
		~Engine();

		// Engine Loop(Game Loop)
		void Run();

		// Engine 종료 함수.
		void QuitEngine();

		// 새 level을 추가(설정)하는 함수.
		void SetNewLevel(Level* newLevel);

	private:
		// GamePlay 시작 함수.
		// Unity의 경우: Start/Awake.
		void BeginPlay();

		// Update 함수
		void Tick(float deltaTime);

		// 그리기 함수. (Draw/Render).
		void Draw();

	private:
		// Engine 종료 Flag
		bool isQuit = false;

		// 입력 관리자.
		Input* input = nullptr;

		// Main Level
		class Level* mainLevel = nullptr;
	};


}

