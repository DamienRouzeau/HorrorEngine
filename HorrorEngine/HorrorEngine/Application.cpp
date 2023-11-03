#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Application.h"
#include "AEntity.h"
#include "AComponent.h"


int HorrorEngine::Application::_entityID = 0;
HorrorEngine::Application* HorrorEngine::Application::_instance = nullptr;

HorrorEngine::Application::Application()
{
	std::cout << "App Created" << std::endl;
}

HorrorEngine::Application::~Application()
{
	std::cout << "App Destroyed" << std::endl;
}

void HorrorEngine::Application::Init(int windowSizeX, int windowSizeY, std::string windowName)
{

	_window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
	std::cout << "Window Created" << std::endl;
}

void HorrorEngine::Application::Loop()
{
	{
		sf::Clock clock;

		float deltaTime = clock.getElapsedTime().asSeconds();

		while (_window.isOpen())
		{
			sf::Event event;

			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window.close();
			}



			std::map<int, AEntity*>::iterator it;

			_window.clear();
			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				it->second->Update(deltaTime);
				AEntity* entity = it->second;
				std::map<int, AComponent*>::iterator itcomp;

				for (itcomp = entity->componentsList.begin(); itcomp != entity->componentsList.end(); itcomp++)
				{
					itcomp->second->Update(deltaTime);
					AComponent* component = itcomp->second;



					itcomp->second->LateUpdate();
					_window.draw(*component);

				}
				it->second->LateUpdate();
				_window.draw(*entity);
			}
			_window.display();
		}
	}
}

HorrorEngine::AEntity* HorrorEngine::Application::CreateEntity(std::string name)
{
	HorrorEngine::AEntity* entity = new AEntity(name);
	entity->_ID = GenerateID();
	entitiesList.insert({ entity->GetID(), entity });
	std::cout << "the entity : " << name << " was created with ID=" << entity->_ID << std::endl;
	return entity;
}

void HorrorEngine::Application::GetAllComponents(AEntity* parent, std::map<int, AComponent*> result)
{

}

HorrorEngine::Application* HorrorEngine::Application::GetInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Application();
	}
	return _instance;
}
/*
  HorrorEngine::AComponent* HorrorEngine::Application::CreateComponentAndAttachToEntity(AEntity* parent, int radius, int R,int G,int B)
{
	HorrorEngine::AComponent* component = new AComponent(radius, R,G,B);
	component->_ID = GenerateID();
	componentsList.insert({ component->_ID,component });
	_linkBetweenComponentAndEntity[component->GetID()] = parent->GetID();
	parent->componentsList.insert({ component->GetID(), component });

	std::cout << "Component create with ID=" << component->_ID << " and linked to entity : " << parent->GetName() << std::endl;

	return component;
}*/

//template<typename T>
int HorrorEngine::Application::GenerateID()
{
	_entityID++;
	return _entityID;
}
/*
void HorrorEngine::Application::CreateWindow()
{
	_window.create(sf::VideoMode(1920, 1080), "Absolutly Very Scary Game");
}

void HorrorEngine::Application::CreateEntity()
{
	HorrorEngine::AEntity* jack = new HorrorEngine::AEntity();

	entitiesList[IDEntity] = jack;
	IDEntity += 1;
}


void HorrorEngine::Application::CreateComponent(AComponent component)
{
	HorrorEngine::AComponent Entity(IDComponent);
	IDComponent += 1;
	componentsList.insert({ IDComponent, component });
}

void HorrorEngine::Application::DeleteEntity(int entityID)
{
	HorrorEngine::AEntity entityToDelete = entitiesList.contains(entityID);
	std::map<int, AComponent>::iterator it;
	for (it = entityToDelete.componentsList.begin(); it != entityToDelete.componentsList.end(); it++)
	{
		DeleteComponent(it->first);
	}
	entityToDelete.~AEntity();
}

void HorrorEngine::Application::DeleteComponent(int componentID)
{
	HorrorEngine::AComponent componentToDelete = componentsList.contains(componentID);
	componentToDelete.~AComponent();
}

void HorrorEngine::Application::UpdateBehaviour()
{
	std::map<int, AEntity>::iterator it;
	for (it == entitiesList.begin(); it != entitiesList.end(); it++)
	{
		std::map<int, AComponent>::iterator componentIt;
		for (componentIt = it->second.componentsList.begin(); componentIt != it->second.componentsList.end(); componentIt++)
		{
			componentIt->second.Update();
		}
		it->second.Update();
	}
}

void HorrorEngine::Application::StartBehaviour()
{
	
}

void HorrorEngine::Application::StopBehaviour()
{
}

*/


