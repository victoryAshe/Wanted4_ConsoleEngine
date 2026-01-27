#pragma once

#include "Common/Common.h"

namespace Wanted
{
	class Level;

	// Main game engine class.
	class WANTED_API Engine
	{
		// Data.
		// Key에 대하여: Down/Up/Key
		struct KeyState
		{
			// 현재 키가 눌렸는지.
			bool isKeyDown = false;

			// 이전에 키가 눌렸는지.
			bool wasKeyDown = false;
		};


	public:
		Engine();
		~Engine();

		// Engine Loop(Game Loop)
		void Run();

		// Engine 종료 함수.
		void QuitEngine();

		// 입력 확인 함수.
		// 이전에 입력이 안됐는데, 현재 입력이 된 경우 1번 호출
		bool GetKeyDown(int keyCode);
		// 이전에 입력이 됐는데, 현재 입력이 취소된 경우 1번 호출.
		bool GetKeyUp(int keyCode);
		// 현재 눌려있으면 반복 호출.
		bool GetKey(int keyCode);

		// 새 level을 추가(설정)하는 함수.
		void SetNewLevel(Level* newLevel);

	private:
		// 입력 처리 함수.
		void ProcessInput();

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


		// Key State 저장용 배열.
		KeyState keyStates[255] = {};

		// Main Level
		class Level* mainLevel = nullptr;
	};


}

