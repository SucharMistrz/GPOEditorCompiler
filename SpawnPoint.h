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

class SpawnPoint :public ObjectTemplate
{
	std::string name, modifiedByUser, spawnPositionOffset, layer;
	int spawnPreventionDelay, group, controlPointId;
	bool enterOnSpawn, aiEnterOnSpawn, spawnAsParaTroper,
		scatterSpawnPositions, onlyForHuman, onlyForAI,
		allowSpawnCloseToVehicle;

public:
	SpawnPoint(std::string n = "SpawnPoint", std::string l = "1", std::string mbu = "User",
		std::string spo = "0/1.25/0", int spd = 0, int g = 0, int cpid = 0,
		bool eos = 0, bool aieos = 0, bool sapt = 0, bool ssp = 0, bool ofh = 0,
		bool ofai = 0, bool asctv = 1);
	~SpawnPoint();
	int SetName(std::string a); std::string GetName();
	int SetModifiedByUser(std::string a); std::string GetModifiedByUser();
	int SetSpawnPositionOffset(std::string a); std::string GetSpawnPositionOffset();
	int SetSpawnPreventionDelay(int a); int GetSpawnPreventionDelay();
	int SetGroup(int a); int GetGroup();
	int SetControlPointId(int a); int GetControlPointId();
	int SetLayer(std::string a); std::string GetLayer();
	int SetEnterOnSpawn(bool a); bool GetEnterOnSpawn();
	int SetAIEnterOnSpawn(bool a); bool GetAIEnterOnSpawn();
	int SetSpawnAsParaTroper(bool a); bool GetSpawnAsParaTroper();
	int SetScatterSpawnPosition(bool a); bool GetScatterSpawnPosition();
	int SetOnlyForHuman(bool a); bool GetOnlyForHuman();
	int SetOnlyForAI(bool a); bool GetOnlyForAI();
	int SetAllowSpawnCloseToVehicle(bool a); bool GetAllowSpawnCloseToVehicle();
	void Print();

	int SetTeam(int a); int GetTeam();
};



