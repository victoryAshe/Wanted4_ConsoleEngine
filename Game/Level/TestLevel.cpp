#include "TestLevel.h"
#include "Actor/Player.h"
#include "Core/Input.h"

TestLevel::TestLevel()
{
	//if (Wanted::Input::Get().GetKeyDown('Q')) {}

	// TestActor ACtor를 Level에 추가.
	AddNewActor(new Player());
}
