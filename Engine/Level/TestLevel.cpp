#include "TestLevel.h"
#include "Actor/TestActor.h"

TestLevel::TestLevel()
{
	// TestActor ACtor를 Level에 추가.
	AddNewActor(new TestActor());
}
