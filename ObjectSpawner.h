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

class ObjectSpawner :public ObjectTemplate
{
	std::string name, modifiedByUser, objectTemplate1, objectTemplate2, layer;
	int minSpawnDelay, maxSpawnDelay, timeToLive, distance,
		maxNrOfObjectSpawned, radius, team;
	bool spawnDelayAtStart, useButtonRadius, holdObject, teamOnVehicle;

public:
	ObjectSpawner(std::string n = "ObjectSpawner", std::string l = "1", std::string mbu = "User",
		std::string ot1 = "", std::string ot2 = "", int minsd = 30, int maxsd = 60,
		int ttl = 60, int d = 50, int mnoos = 1, int r = 0, int t = 0, bool sdat = 0,
		bool ubr = 0, bool ho = 0, bool tov = 1);
	~ObjectSpawner();

	int SetName(std::string a); std::string GetName();
	int SetModifiedByUser(std::string a); std::string GetModifiedByUser();
	int SetObjectTemplate1(std::string a); std::string GetObjectTemplate1();
	int SetObjectTemplate2(std::string a); std::string GetObjectTemplate2();
	int SetMinSpawnDelay(int a); int GetMinSpawnDelay();
	int SetMaxSpawnDelay(int a); int GetMaxSpawnDelay();
	int SetTimeToLive(int a); int GetTimeToLive();
	int SetDistance(int a); int GetDistance();
	int SetMaxNrOfObjectSpawned(int a); int GetMaxNrOfObjectSpawned();
	int SetRadius(int a); int GetRadius();
	int SetTeam(int a); int GetTeam();
	int SetLayer(std::string a); std::string GetLayer();
	int SetSpawnDelayAtStart(bool a); bool GetSpawnDelayAtStart();
	int SetUseButtonRadius(bool a); bool GetUseButtonRadius();
	int SetHoldObject(bool a); bool GetHoldObject();
	int SetTeamOnVehicle(bool a); bool GetTeamOnVehicle();
	void Print();
};

