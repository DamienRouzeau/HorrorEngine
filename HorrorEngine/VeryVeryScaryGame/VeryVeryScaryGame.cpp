
#include <iostream>
#include <SFML/Graphics.hpp>
#include <HorrorEngine/Application.h>
#include <HorrorEngine/Camera.h>
#include <HorrorEngine/ResourceManager.h>
#include <HorrorEngine/SpriteRenderer.h>

int main()
{
    HorrorEngine::Application MyApp;
    MyApp.Init(1920, 1080, "Absolutly Scary Game");
    HorrorEngine::ResourceManager ressourceManager = HorrorEngine::ResourceManager("rm");



    HorrorEngine::AEntity* gwen = MyApp.CreateEntity("Gwen");
    HorrorEngine::Camera* yeux = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Camera>(gwen);
    HorrorEngine::SpriteRenderer* cheveuxBleus = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxBleus->Init("gwen.png");
    cheveuxBleus->SetColor(12, 132, 238);
    HorrorEngine::SpriteRenderer* cheveuxRoses = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxBleus->Init("gwen.png");
    cheveuxBleus->SetColor(176, 23, 191);



    HorrorEngine::AEntity* maxime = MyApp.CreateEntity("Maxime");
    MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);

    HorrorEngine::AEntity* clement = MyApp.CreateEntity("Clement parce que c'est bientot son anniversaire");
    MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(maxime);
    MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(clement);
    
    

    MyApp.Loop();

    return 0;
}