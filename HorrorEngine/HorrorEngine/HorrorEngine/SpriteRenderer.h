#pragma once
#include <string>
#include "AComponent.h"
namespace HorrorEngine
{
	class SpriteRenderer : public AComponent , public sf::Drawable
	{
	protected:
		sf::Sprite _sprite;
		sf::Texture _texture;
		sf::RectangleShape _shape;

	public:
		SpriteRenderer(AEntity* parent);
		void Init(std::string picName);
		void SetSprite();
		void SetColor(int R, int G, int B);
		void SetSize(float sizeX, float sizeY);
		void SetSmooth(bool smooth);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}
