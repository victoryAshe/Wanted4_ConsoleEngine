#pragma once
#include "Level/Level.h"
#include "Actor/Player.h"
#include "Interface/ICanPlayerMove.h"

class SokobanLevel 
	: public Wanted::Level,
	public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level)

public:
	SokobanLevel();

private:
	// Load Game Map.
	void LoadMap(const char* filename);

	// ICanPlayerMove을(를) 통해 상속됨
	virtual bool CanMove(
		const Wanted::Vector2& playerPosition, 
		const Wanted::Vector2& newPosition) override;
};

