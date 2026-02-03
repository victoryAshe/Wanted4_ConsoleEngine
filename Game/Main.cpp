#include <iostream>

#include "Game/Game.h"
#include "Level/SokobanLevel.h"

using namespace Wanted;

int main()
{
	//Wanted::Engine engine;
	//engine.SetNewLevel(new SokobanLevel());
	//engine.Run();

	//Game game;
	//game.Run();


	// WriteConsoleOutput: 문자 배열을 한 번에 콘솔로 넘겨서 그릴 때 사용하는 함수.
	// 1차원 배열을 2차원 배열처럼 써서 넘겨야 함.
	// A 안붙이면 WideChar배열이 기본이라 A를 써서 ASCII를 쓰도록 함.
	
	// WideConsoleOutput을 위한 예시 배열.
	const int width = 3;
	const int height = 3;
	CHAR_INFO charArray[width * height] = {};

	charArray[2 * width + 1].Char.AsciiChar = 'P';
	charArray[2 * width + 1].Attributes = FOREGROUND_GREEN;

	charArray[0 * width + 1].Char.AsciiChar = '#';
	charArray[0 * width + 1].Attributes = FOREGROUND_RED;

	COORD position = {};
	COORD screenSize = { width, height };
	
	SMALL_RECT writeRegion{
		0,
		0,
		static_cast<short>(width),
		static_cast<short>(height)
	};

	WriteConsoleOutputA(
		GetStdHandle(STD_OUTPUT_HANDLE),
		charArray,
		screenSize,
		position,
		&writeRegion
	);

	//CreateConsoleScreenBuffer()
	//SetConsoleActiveScreenBuffer()

	std::cin.get();

	return 0;
}