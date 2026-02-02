#pragma once
#include "Level/Level.h"
#include "Actor/Player.h"

class TestLevel : public Wanted::Level
{
	RTTI_DECLARATIONS(TestLevel, Level)

public:
	TestLevel();

private:
	// Load Game Map.
	void LoadMap(const char* filename);
};

