#include "Engine.h"
#include "Level/Level.h"
#include <iostream>
#include <Windows.h>

namespace Wanted 
{
	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
		// mainLevel 제거.
		delete mainLevel;
		mainLevel = nullptr;
	}

	void Engine::Run()
	{
		// 시계의 정밀도.
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);

		// Frame 계산용 변수
		int64_t currentTime = 0;
		int64_t previousTime = 0;
		
		// Hardware Timer로 시간 구하기.
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);

		// Engine 시작 직전에는 두 시간 값을 동일하도록 맞춤.
		currentTime = time.QuadPart;
		previousTime = currentTime;

		// 기준 Frame(단위: 초).
		float targetFrameRate = 120.0f;
		float oneFrameTime = 1.0f / targetFrameRate;


		// Engine Loop (Game Loop)
		while (!isQuit)
		{
			// 현재 시간 구하기.
			QueryPerformanceCounter(&time);
			currentTime = time.QuadPart;

			// Frame Time 계산
			float deltaTime
				= static_cast<float>(currentTime - previousTime);

			// 초 단위로 변환
			deltaTime = deltaTime
				/ static_cast<float>(frequency.QuadPart);

			// 고정 frame 기법.
			if (deltaTime >= oneFrameTime)
			{
				ProcessInput();

				// Frame 처리.
				BeginPlay();
				Tick(deltaTime);
				Draw();

				// 이전 시간 값 갱신.
				previousTime = currentTime;

				// 현재 입력 값을 이전 입력 값으로 저장.
				for (int ix = 0; ix < 255; ++ix)
				{
					keyStates[ix].wasKeyDown = keyStates[ix].isKeyDown;
				}
			}

		}

		// TODO: 정리 작업.
		std::cout << "Engine has been shutdown....";
	}

	void Engine::QuitEngine()
	{
		isQuit = true;
	}

	bool Engine::GetKeyDown(int keyCode)
	{
		return keyStates[keyCode].isKeyDown 
			&& !keyStates[keyCode].wasKeyDown;
	}

	bool Engine::GetKeyUp(int keyCode)
	{
		return !keyStates[keyCode].isKeyDown
			&& keyStates[keyCode].wasKeyDown;
	}

	bool Engine::GetKey(int keyCode)
	{
		return keyStates[keyCode].isKeyDown;
	}

	void Engine::SetNewLevel(Level* newLevel)
	{
		// 기존 레벨 있는지 확인.
		// 있으면 기존 레벨 제거.
		// TODO: 임시 코드. 레벨 전환할 때는 바로 제거하면 안됨!
		if (mainLevel)
		{
			delete mainLevel;
			mainLevel = nullptr;
		}

		mainLevel = newLevel;
	}

	void Engine::ProcessInput()
	{
		// Key 마다의 Input 읽기.
		// !!! OS가 제공하는 기능을 사용할 수 밖에 없음!
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].isKeyDown
				= (GetAsyncKeyState(ix) & 0x8000) > 0 ? true : false;

		}

	}

	void Engine::BeginPlay()
	{
		// Level이 있으면 event 전달.
		if (!mainLevel)
		{
			// Silent is violent. 침묵은 폭력이다.
			// Log message 남기지 않으면 안된다!
			std::cout << "Error: Engine::BeginPlay(). mainLevel is empty.\n";
			return;
		}

		mainLevel->BeginPlay();

	}

	void Engine::Tick(float deltaTime)
	{
		//std::cout
		//	<< "DeltaTime: " << deltaTime
		//	<< ", FPS: " << (1.0f / deltaTime) << "\n";
		
		// ESC 키 누르면 종료.
		if(GetKeyDown(VK_ESCAPE))
		{
			QuitEngine();
		}

		// Level에 event 흘리기.
		// 예외 처리.
		if (!mainLevel)
		{
			std::cout << "Error: Engine::Tick(). mainLevel is empty.\n";
			return;
		}

		mainLevel->Tick(deltaTime);
	}

	void Engine::Draw()
	{
		// Level에 event 흘리기.
		// 예외 처리.
		if (!mainLevel)
		{
			std::cout << "Error: Engine::Draw(). mainLevel is empty.\n";
			return;
		}

		mainLevel->Draw();
	}
}