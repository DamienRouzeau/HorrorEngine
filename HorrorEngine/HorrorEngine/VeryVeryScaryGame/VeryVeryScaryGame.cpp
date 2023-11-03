
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
    gwen->transform.setPosition(500, 20);
    gwen->transform.setRotation(50);
    HorrorEngine::Camera* yeux = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::Camera>(gwen);
    yeux->Init(&MyApp._window);
    HorrorEngine::SpriteRenderer* cheveuxBleus = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxBleus->Init("gwen.png");
    cheveuxBleus->SetColor(12, 132, 238);
    cheveuxBleus->SetSize(2, 1);
    HorrorEngine::SpriteRenderer* cheveuxRoses = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(gwen);
    cheveuxRoses->Init("gwen.png");
    cheveuxRoses->SetColor(176, 23, 191);
    cheveuxRoses->SetSize(1, 2);

    HorrorEngine::AEntity* maxime = MyApp.CreateEntity("Maxime");
    maxime->transform.setPosition(200, 300);
    HorrorEngine::SpriteRenderer* cheveuxRouges = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(maxime);
    cheveuxRouges->Init("gwen.png");
    cheveuxRouges->SetColor(169, 29, 56);


    /*HorrorEngine::AEntity* clement = MyApp.CreateEntity("Clement parce que c'est bientot son anniversaire");
    HorrorEngine::SpriteRenderer* cheveuxNwar = MyApp.CreateComponentAndAttachToEntity<HorrorEngine::SpriteRenderer>(clement);
    cheveuxNwar->Init("gwen.png");
    cheveuxNwar->SetColor(1, 2, 3);*/
    

    MyApp.Loop();

    return 0;
}