#include "GPOManager.h"

GPOManager::GPOManager(std::string p, std::string l)
{
	path = p;
	layer = l;
	std::filesystem::current_path(p);
}

GPOManager::~GPOManager()
{
	//std::cout << std::endl << "Destructor called on GPOManager" << std::endl;
}

int GPOManager::SetPath(std::string a)
{
	std::filesystem::current_path(a);

	return 0;
}

std::string GPOManager::GetPath()
{
	return path;
}

int GPOManager::SetLayer(std::string l)
{
	layer = l;

	return 0;
}

std::string GPOManager::GetLayer()
{
	return layer;
}