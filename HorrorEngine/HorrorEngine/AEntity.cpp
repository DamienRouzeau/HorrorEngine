#include <SFML/Graphics.hpp>
#include "AEntity.h"
#include "Application.h"


HorrorEngine::AEntity::AEntity(std::string name)
{
	_ID = 0;
	_name = name;
}


HorrorEngine::AEntity::~AEntity()
{
}

void HorrorEngine::AEntity::Awake()
{
	
}

void HorrorEngine::AEntity::Start()
{
}

void HorrorEngine::AEntity::Update(float deltatime)
{
}

void HorrorEngine::AEntity::LateUpdate()
{
}

std::string HorrorEngine::AEntity::GetName()
{
	return std::string(_name);
}

void HorrorEngine::AEntity::AddComponent(AComponent* componentToAdd)
{
	//componentsList.insert(componentToAdd->GetID(), componentToAdd);
}

int HorrorEngine::AEntity::GetID()
{
	return _ID;
}

void HorrorEngine::AEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}

void HorrorEngine::AEntity::FixedUpdate()
{
}

void HorrorEngine::AEntity::OnCollisionEnter()
{
}

void HorrorEngine::AEntity::OnCollisionExit()
{
}

void HorrorEngine::AEntity::OnTriggerEnter()
{
}

void HorrorEngine::AEntity::OnTriggerExit()
{
}

