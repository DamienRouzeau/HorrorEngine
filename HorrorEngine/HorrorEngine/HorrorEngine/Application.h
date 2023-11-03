#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include "AEntity.h"
#include "AComponent.h"
#include <iostream>

namespace HorrorEngine 
{
	class Application
	{

	protected :
		std::map<int, AEntity*> entitiesList;
		std::map<int, AComponent*> componentsList;
		std::map<int, int> _linkBetweenComponentAndEntity;
		static Application* _instance;
		static int _entityID;

	public:
		sf::RenderWindow _window;

		Application();
		~Application();

		void Init(int windowSizeX, int windowSizeY, std::string windowName);
		void Loop();

		AEntity* CreateEntity(std::string name);

		template<typename T>
		inline T* CreateComponentAndAttachToEntity(AEntity* parent)
		{
			T* component = new T(parent);
			component->_ID = GenerateID();
			componentsList.insert({ component->_ID,component });
			_linkBetweenComponentAndEntity[component->GetID()] = parent->GetID();
			parent->componentsList.insert({ component->GetID(), component });

			std::cout << "Component create with ID=" << component->_ID << " and linked to entity : " << parent->GetName() << std::endl;

			return component;
		}
		//AComponent* CreateComponentAndAttachToEntity(AEntity* parent, int radius, int R, int G, int B);

		void GetAllComponents(AEntity* parent, std::map<int, AComponent*> result);

		static Application* GetInstance();

		//template<typename T>
		int GenerateID();






		/*
		void CreateWindow();
		void DeleteEntity(int);
		void DeleteComponent(int componentID);

		void UpdateBehaviour();
		void StartBehaviour();
		void StopBehaviour();

		void DrawEntity();
		void EntitiesController();
		void LinkComponentToEntity();
		*/

	};

}

