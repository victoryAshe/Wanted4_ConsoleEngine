#include <iostream>
#include "Engine/Engine.h"
#include "Level/Level.h"
#include "Level/TestLevel.h"
#include "Actor/Actor.h"
#include "Actor/TestActor.h"

#include "Common/Common.h"

using namespace Wanted;

int main()
{
	//Wanted::Engine engine;
	//engine.SetNewLevel(new TestLevel());
	//engine.Run();

	TestLevel* level = new TestLevel();
	Actor* actor = new TestActor();
	TestActor* testActor = new TestActor();

	if (actor->Is(testActor))
	{
		std::cout << "actor is TestActor Type.\n";
	}
	else
	{
		std::cout << "acter is not TestActor Type.\n";
	}

	/*
	TestActor* testActor = actor->As<TestActor>();
	if (testActor)
	{
		std::cout << "actor is TestACtor type.\n";
	}
	*/
	return 0;
}