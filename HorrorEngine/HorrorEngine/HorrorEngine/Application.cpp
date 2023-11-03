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


		while (_window.isOpen())
		{

			float deltaTime = clock.getElapsedTime().asSeconds();
			sf::Event event;

			while (_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					_window.close();
			}



			std::map<int, AEntity*>::iterator it;

			
			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				it->second->Update(deltaTime);
			}

			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				it->second->LateUpdate();
			}

			_window.clear();
			for (it = entitiesList.begin(); it != entitiesList.end(); it++)
			{
				_window.draw(*it->second);
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

int HorrorEngine::Application::GenerateID()
{
	_entityID++;
	return _entityID;
}

