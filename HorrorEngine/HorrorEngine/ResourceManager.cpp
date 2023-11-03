#include "ResourceManager.h"
#include <vector>
#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <filesystem>

HorrorEngine::ResourceManager::ResourceManager(std::string name)
{
	_name = name;
	Init();
}

void HorrorEngine::ResourceManager::Init()
{
	TCHAR buffer[MAX_PATH];
	path = GetModuleFileName(NULL, buffer, sizeof(buffer));
	std::cout << std::filesystem::path(buffer).parent_path().string() << std::endl;

}

