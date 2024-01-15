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

class CombatArea
{
	std::string name, layer;
	int team, vehicles;
	bool inverted;

	std::string* areaPoints;
	int numberOfAreaPoints;

public:
	CombatArea(std::string n = "CombatArea", std::string l = "1",
		std::string* aap = {}, int t = 0, int v = 4,
		bool i = 0, int noap = 0);
	~CombatArea();
	int SetName(std::string a); std::string GetName();
	int AddAreaPoint(std::string a); int GetNumberOfAreaPoints();
	int SetTeam(int a); int GetTeam();
	int SetVehicles(int a); int GetVehicles();
	int SetLayer(std::string a); std::string GetLayer();
	int SetInverted(bool a); bool GetInverted();
	void Print();
};