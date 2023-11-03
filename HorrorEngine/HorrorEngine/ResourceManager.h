#pragma once
#include <string>
namespace HorrorEngine
{
	class ResourceManager
	{
	protected:
		std::string _name;

	public: 
		std::string path;
		ResourceManager(std::string name);
		void Init();

	};
}

