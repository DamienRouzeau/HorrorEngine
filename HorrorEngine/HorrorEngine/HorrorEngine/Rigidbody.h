#pragma once
#include <box2d/box2d.h>
namespace HorrorEngine
{
	class Rigidbody
	{
	protected:
		b2BodyDef _bodyDef;
		b2Body _body;
	public:
		// Setters
		void SetBodyType();
		void SetPosition();
		void SetLinearVelocity();
		void SetAngularVelocity();
		 
		// Getters
		void GetPosition();

	};
}

