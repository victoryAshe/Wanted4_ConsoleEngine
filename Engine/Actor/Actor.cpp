#include "Actor.h"

namespace Wanted
{
	Actor::Actor()
	{
		
	}
	Actor::~Actor()
	{
	}


	void Actor::BeginPlay() 
	{
		// Event 받은 후에는 flag 설정.
		hasBeganPlay = true;
	}

	void Actor:: Tick(float deltaTime)
	{
	}

	void Actor:: Draw()
	{
	}

}