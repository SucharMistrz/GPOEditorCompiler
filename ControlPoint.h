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

class ControlPoint :public ObjectTemplate
{
	std::string name, modifiedByUser, radiusOffset, MinimapNameOffset;
	int team, controlPointId, areaValueTeam1, areaValueTeam2,
		enemyTicketLossWhenCaptured, timeToGetControl, timeToLoseControl,
		minNrToTakeControl, supplyGroupId, onlyTakeableByTeam;
	bool disableIfEnemyInsideRadius, disableWhenLosingControl,
		loseControlWhenEnemyClose, loseControlWhenNotClose,
		unableToChangeTeam, showOnMinimap, isUnstrategicControlPoint,
		isHemisphere, ForSoldierOnly, hasGreyCapturingState, hoistFlag;

	std::string layer;

public:
	ControlPoint(std::string n = "cpname_", std::string l = "1", std::string mbu = "User",
		std::string roff = "0/0/0",	std::string mmnoff = "0/0", int t = 0,
		int cpid = -1, int avt1 = 0, int avt2 = 0, int tickloss = 0,
		int ttgc = 10, int ttlc = 10, int minttc = 1, int sgid = -1,
		int otbt = 0, bool dieir = 0, bool dwlc = 0, bool lcwec = 1,
		bool utct = 0, bool som = 1, bool iscp = 0, bool ih = 0, bool fso = 0,
		bool hgcs = 0, bool hf = 1);
	~ControlPoint();
	int SetName(std::string a); std::string GetName();
	int SetModifiedByUser(std::string a); std::string GetModifiedByUser();
	int SetRadiusOffset(std::string a); std::string GetRadiusOffset();
	int SetMinimapNameOffset(std::string a); std::string GetMinimapNameOffset();

	int SetTeam(int a); int GetTeam();
	int SetControlPointID(int a); int GetControlPointID();
	int SetAreaValueTeam1(int a); int GetAreaValueTeam1();
	int SetAreaValueTeam2(int a); int GetAreaValueTeam2();
	int SetEnemyTicketLossWhenCaptured(int a); int GetEnemyTicketLossWhenCaptured();
	int SetTimeToGetControl(int a); int GetTimeToGetControl();
	int SetTimeToLoseControl(int a); int GetTimeToLoseControl();
	int SetMinNrToTakeControl(int a); int GetMinNrToTakeControl();
	int SetSupplyGroupId(int mysgid); int GetSupplyGroupId();
	int SetOnlyTakeableByTeam(int a); int GetOnlyTakeableByTeam();
	int SetLayer(std::string a); std::string GetLayer();

	int SetDisableIfEnemyInsideRadius(bool a); bool GetDisableIfEnemyInsideRadius();
	int SetDisableWhenLosingControl(bool a); bool GetDisableWhenLosingControl();
	int SetLoseControlWhenEnemyClose(bool a); bool GetLoseControlWhenEnemyClose();
	int SetLoseControlWhenNotClose(bool a); bool GetLoseControlWhenNotClose();
	int SetUnableToChangeTeam(bool a); bool GetUnableToChangeTeam();
	int SetShowOnMinimap(bool a); bool GetShowOnMinimap();
	int SetIsUnstrategicControlPoint(bool a); bool GetIsUnstrategicControlPoint();
	int SetIsHemisphere(bool a); bool GetIsHemisphere();
	int SetForSoldierOnly(bool a); bool GetForSoldierOnly();
	int SetHasGreyCapturingState(bool a); bool GetHasGreyCapturingState();
	int SetHoistFlag(bool a); bool GetHoistFlag();
	
	void Print();
};
