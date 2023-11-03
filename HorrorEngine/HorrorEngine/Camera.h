#pragma once
#include "AComponent.h"
#include <SFML/Graphics.hpp>

namespace HorrorEngine
{
	class Camera : public AComponent
	{
	protected:
		sf::View _view;
		sf::RenderWindow* _window;
	public:
		Camera(AEntity* parent);
		void Init(sf::RenderWindow* window);
		void Update(float delatime);
		void LateUpdate();
		void SetRotation();
		void SetPosition();
		void SetViewport(sf::FloatRect viewport);
		void SetZoom(float zoom);
	};
}

