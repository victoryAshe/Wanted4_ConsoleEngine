#include "SokobanLevel.h"
#include "Actor/Player.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"
#include <iostream>

SokobanLevel::SokobanLevel()
{
	//if (Wanted::Input::Get().GetKeyDown('Q')) {}

	// TestActor ACtor를 Level에 추가.
	//AddNewActor(new Player());

	//LoadMap("../Assets/Map.txt");
	//LoadMap("Map.txt");
	LoadMap("Stage1.txt");
}

void SokobanLevel::LoadMap(const char* filename)
{
	// Load File.
	// 최종 경로 만들기.
	char path[2048] = {};
	sprintf_s(path, 2048, "../Assets/%s", filename);

	// Open File.
	FILE* file = nullptr;
	fopen_s(&file, path, "rt");

	// null check
	if (!file)
	{
		// use std error console 
		std::cerr << "Failed to open map file.\n";

		// stop int debugMode if a error occurs
		__debugbreak();
	}

	// Read map.
	// read map size
	fseek(file, 0, SEEK_END);

	// 마지막 위치에 대한 사이즈 읽기.
	size_t fileSize = ftell(file);

	// File Position 되돌리기.
	rewind(file);

	// Create buffer to read data from file.
	char* data = new char[fileSize + 1];

	//Read data
	fread(data, sizeof(char), fileSize, file);

	// 읽어온 문자열을 분석(Parsing)해서 출력
	// index를 사용해 한 문자씩 읽기.
	int index = 0;

	// 객체를  생성할 위치 값.
	Wanted::Vector2 position(0,0);

	while(index < fileSize)
	{
		// Read char.
		char mapCharacter = data[index];
		++index;

		if(mapCharacter =='\n')
		{
			//std::cout << "\n";
			// 개행: y좌표는 하나 늘리고, x좌표 초기화.
			++position.y;
			position.x = 0;
			continue;
		}

		/*
		* [5 kinds of actor]
		#: Wall
		.: Ground
		p: Player
		b: Box
		t: Target
		*/
		// 한 문자씩 처리.
		switch (mapCharacter)
		{
		case '#':
		case '1':
			//std::cout << "#";
			AddNewActor(new Wall(position));
			break;

		case '.':
			//std::cout << " ";
			AddNewActor(new Ground(position));
			break;

		case 'p':
			//std::cout << "P";
			// Player: Movable
			AddNewActor(new Player(position));
			AddNewActor(new Ground(position));
			break;

		case 'b':
			//std::cout << "B";
			// Box: Movable
			// 박스가 옮겨졌을 때, 그 밑에 땅이 있어야 함.
			AddNewActor(new Box(position));
			AddNewActor(new Ground(position));
			break;

		case 't':
			//std::cout << "T";
			AddNewActor(new Target(position));
			break;
		}

		// x 좌표 증가 처리.
		++position.x;
	}

	// Free buffer already have been used
	delete[] data;

	// Close itf successfuly opened.
	fclose(file);
}

bool SokobanLevel::CanMove(
	const Wanted::Vector2& playerPosition, 
	const Wanted::Vector2& newPosition)
{
	// Level에 있는 Box Actor 모으기.
	// Box는 Player가 밀기 등 추가적으로 처리해야하기 때문.
	std::vector<Actor*> boxes;

	// Level에 배치된 전체 Actor를 순회하면서 Box 찾기.
	for (Actor* const actor : actors)
	{
		// Actor가 Box type인지 확인.
		if(actor->IsTypeOf<Box>())
		{
			boxes.emplace_back(actor);
			continue;
		}
	}

	return false;
}