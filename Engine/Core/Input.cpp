#include "Input.h"
#include "Windows.h"
#include <iostream>

namespace Wanted 
{ 
	// 전역 변수 초기화.
	Input* Input::instance = nullptr;

	Input::Input()
	{
		// 객체가 초기화되면 자기 자신의 주소를 저장.
		instance = this;
	}

	Input::~Input()
	{
		// memory 관리는 Engine에서 하기 때문에 따로 지울 필요는 없음.
	}

	void Input::ProcessInput()
	{
		// Key 마다의 Input 읽기.
		// !!! OS가 제공하는 기능을 사용할 수 밖에 없음!
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].isKeyDown
				= (GetAsyncKeyState(ix) & 0x8000) > 0 ? true : false;

		}

	}

	void Input::SavePreviousInputStates()
	{
		// 현재 입력 값을 이전 입력 값으로 저장.
		for (int ix = 0; ix < 255; ++ix)
		{
			keyStates[ix].wasKeyDown = keyStates[ix].isKeyDown;
		}
	}

	bool Input::GetKeyDown(int keyCode)
	{
		return keyStates[keyCode].isKeyDown
			&& !keyStates[keyCode].wasKeyDown;
	}

	bool Input::GetKeyUp(int keyCode)
	{
		return !keyStates[keyCode].isKeyDown
			&& keyStates[keyCode].wasKeyDown;
	}

	bool Input::GetKey(int keyCode)
	{
		return keyStates[keyCode].isKeyDown;
	}

	Input& Input::Get()
	{
		// Singleton.
		// 이 함수는 Contents Project에서 접근하므로,
		// Engine은 이미 초기화 완료 상태.
		if (!instance)
		{
			std::cout << "Error: Input::Get(). instance is null.\n";

			// Debug Mode에서만 동작!
			// 자동으로 중단점 걸림.
			__debugbreak();
		}

		// Lazy-Pattern.
		// Effective C++에 나오는 것.
		// 실행 시점 직전에 instance를 생성.
		// Engine에서는 Lazy-Pattern을 안씀!
		//static Input instance;
		//return instance;

		return *instance;
	}

}