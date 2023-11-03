#pragma once
#include <box2d/box2d.h>
namespace HorrorEngine
{
	class Physics
	{
	protected:
		//b2Vec2 _gravity;
		//b2World _world;
		//b2ContactListener _contactListener;
	public:
		const static float worldScale;
		Physics();
		void Update(float deltaTime);
	};
}

