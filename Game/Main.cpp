#include <iostream>
#include "Engine/Engine.h"
#include "Level/Level.h"
#include "Level/SokobanLevel.h"
#include "Actor/Actor.h"
#include "Actor/Player.h"

#include "Common/Common.h"

using namespace Wanted;

int main()
{
	Wanted::Engine engine;
	engine.SetNewLevel(new SokobanLevel());
	engine.Run();

	return 0;
}