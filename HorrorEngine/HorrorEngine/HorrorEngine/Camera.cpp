#include "Camera.h"
#include "Application.h"
#include "AEntity.h"


HorrorEngine::Camera::Camera(AEntity* parent)
{
	_parent = parent;
}

void HorrorEngine::Camera::Init(sf::RenderWindow* window)
{
	_window = window;
	_window->setView(_view);
}

void HorrorEngine::Camera::Update(float delatime)
{
	_view.setCenter(_parent->transform.getPosition());
}

void HorrorEngine::Camera::LateUpdate()
{

}


void HorrorEngine::Camera::SetRotation()
{
	
}

void HorrorEngine::Camera::SetPosition()
{
}

void HorrorEngine::Camera::SetViewport(sf::FloatRect viewport)
{
	_view.setViewport(viewport);
}

void HorrorEngine::Camera::SetZoom(float zoom)
{
	_view.zoom(zoom);
}



