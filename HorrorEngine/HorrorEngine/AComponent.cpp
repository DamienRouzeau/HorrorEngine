#include <iostream>
#include "AComponent.h"




HorrorEngine::AComponent::AComponent()
{
	
}

HorrorEngine::AComponent::AComponent(float length, int colorR, int colorG, int colorB)
{
	_ID = 0;
	_shape.setRadius(length);
	_shape.setFillColor(sf::Color(colorR, colorG, colorB));
}

HorrorEngine::AComponent::~AComponent()
{

}

void HorrorEngine::AComponent::Awake()
{
}

void HorrorEngine::AComponent::Start()
{
}

void HorrorEngine::AComponent::Update(float deltatime)
{
}

void HorrorEngine::AComponent::LateUpdate()
{
}


int HorrorEngine::AComponent::GetID()
{
	return _ID;
}

void HorrorEngine::AComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}



void HorrorEngine::AComponent::GetParent(AEntity* parent)
{
	_parent = parent;
}

void HorrorEngine::AComponent::FixedUpdate()
{
}

void HorrorEngine::AComponent::OnCollisionEnter()
{
}

void HorrorEngine::AComponent::OnCollisionExit()
{
}

void HorrorEngine::AComponent::OnTriggerEnter()
{
}

void HorrorEngine::AComponent::OnTriggerExit()
{
}

