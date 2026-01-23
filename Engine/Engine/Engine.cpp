#include "Engine.h"
#include <iostream>
#include <Windows.h>

namespace Wanted 
{
	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
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
				Tick(1.0f / 60.0f);
				Draw();

				// 이전 시간 값 갱신.
				previousTime = currentTime;

				// 현재 입력 값을 이전 입력 값으로 저장.
				for (int ix = 0; ix < 255; ++ix)
				{
					keyStates[ix].wasKeyDown = keyStates[ix].isKeyDown;
				}
			}

			// TODO: 정리 작업.
			std::cout << "Engine has been shutdown....";
		}
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

	void Engine::Tick(float deltaTime)
	{
		std::cout
			<< "DeltaTime: " << deltaTime
			<< ", FPS: " << (1.0f / deltaTime) << "\n";

		if(GetKeyDown(VK_ESCAPE))
		{
			QuitEngine();
		}
	}

	void Engine::Draw()
	{
	}
}