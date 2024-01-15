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

class ObjectTemplate
{
	//bool objectAttached;
public:
	virtual int SetName(std::string a) = 0; virtual std::string GetName() = 0;
	virtual int SetModifiedByUser(std::string a) = 0; virtual std::string GetModifiedByUser() = 0;
	virtual int SetTeam(int a) = 0; virtual int GetTeam() = 0;
	//virtual int SetControlPointId(int a) = 0; virtual int GetControlPointId() = 0;
};

