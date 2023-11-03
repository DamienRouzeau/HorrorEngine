#include "SpriteRenderer.h"

HorrorEngine::SpriteRenderer::SpriteRenderer(AEntity* parent)
{
	_parent = parent;
}

void HorrorEngine::SpriteRenderer::Init(std::string picName)
{
	if (!_texture.loadFromFile(picName))
	{
		// erreur...
	}
	SetSmooth(true);
	SetSprite();
	SetColor(255, 255, 255);
}

void HorrorEngine::SpriteRenderer::SetSprite()
{
	_sprite.setTexture(_texture);
}

void HorrorEngine::SpriteRenderer::SetColor(int R, int G, int B)
{
	_sprite.setColor(sf::Color(R, G, B));
}

void HorrorEngine::SpriteRenderer::SetSmooth(bool smooth)
{
	_texture.setSmooth(smooth);
}

void HorrorEngine::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
