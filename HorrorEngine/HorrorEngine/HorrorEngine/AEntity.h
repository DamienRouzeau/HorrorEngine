#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include "AComponent.h"

namespace HorrorEngine
{
	class AEntity : public sf::Drawable
	{
	protected:

		std::string _name;

	public:
		AEntity(std::string name);
		~AEntity();
		int _ID;
		std::map<int, AComponent*> componentsList;
		sf::CircleShape _shape;

		void Awake();
		void Start();
		void Update(float deltatime);
		void LateUpdate();
		void AddComponent(AComponent* componentToAdd);
		std::string GetName();
		int GetID();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		void SetTransform(sf::Transformable newPosition);
		void FixedUpdate();
		void OnCollisionEnter();
		void OnCollisionExit();
		void OnTriggerEnter();
		void OnTriggerExit();

		sf::Transformable transform;

	};
}

