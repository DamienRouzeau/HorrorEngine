#pragma once
#include <SFML/Graphics.hpp>

namespace HorrorEngine
{
	class AEntity;

	class AComponent : public sf::Drawable
	{
	protected:
		
	public:
		AEntity* _parent;

		int _ID;
		sf::CircleShape _shape;
		AComponent();
		AComponent(float length, int colorR, int colorG, int colorB);
		~AComponent();

		virtual void Awake();
		virtual void Start();
		virtual void Update(float delatime);
		virtual void LateUpdate();
		int GetID();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		virtual void GetParent(AEntity* parent);
		virtual void FixedUpdate();
		virtual void OnCollisionEnter();
		virtual void OnCollisionExit();
		virtual void OnTriggerEnter();
		virtual void OnTriggerExit();

	};
}

