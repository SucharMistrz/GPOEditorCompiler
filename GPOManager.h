#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <filesystem>
#include <string_view>
#include <vector>
#include <source_location>
#include <windows.h>
#include "Common.h"

class GPOManager
{
	std::string path, layer;
public:

	GPOManager(std::string p = "", std::string l = "");
	~GPOManager();

	int SetPath(std::string a); std::string GetPath();
	int SetLayer(std::string a); std::string GetLayer();
};

