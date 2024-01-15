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
#include "ObjectTemplate.h"

class Object// :public ObjectTemplate
{
	std::string name, absolutePosition, rotation, layer;
	int controlPointId;

public:
	Object(std::string n = "ObjectName", std::string l = "1", std::string pos = "0/0/0", std::string rot = "0/0/0", int cpid = 0);
	~Object();
	int SetName(std::string a); std::string GetName();
	int SetControlPointId(int a); int GetControlPointId();
	int SetRotation(std::string a); std::string GetRotation();
	int SetAbsolutePosition(std::string a); std::string GetAbsolutePosition();
	int SetLayer(std::string a); std::string GetLayer();
	void Print();
};

