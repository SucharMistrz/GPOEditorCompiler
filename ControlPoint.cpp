#include "ControlPoint.h"
#include "Common.h"

ControlPoint::ControlPoint(std::string n, std::string l, std::string mbu,
	std::string roff, std::string mmnoff, int t, int cpid,
	int avt1, int avt2, int tickloss, int ttgc, int ttlc,
	int minttc, int sgid, int otbt, bool dieir, bool dwlc,
	bool lcwec, bool utct, bool som, bool iscp, bool ih,
	bool fso, bool hgcs, bool hf)
{
	name = n; modifiedByUser = mbu; layer = l; radiusOffset = roff; MinimapNameOffset = mmnoff;

	team = t; controlPointId = cpid; areaValueTeam1 = avt1; areaValueTeam2 = avt2;
	enemyTicketLossWhenCaptured = tickloss; timeToGetControl = ttgc; timeToLoseControl = ttlc;
	minNrToTakeControl = minttc; supplyGroupId = sgid; onlyTakeableByTeam = otbt;
	
	disableIfEnemyInsideRadius = dieir; disableWhenLosingControl = dwlc;
	loseControlWhenEnemyClose = lcwec; unableToChangeTeam = utct; showOnMinimap = som;
	isUnstrategicControlPoint = iscp; isHemisphere = ih; ForSoldierOnly = fso;
	hasGreyCapturingState = hgcs; hoistFlag = hf;

}

ControlPoint::~ControlPoint()
{
	//std::cout << std::endl << "Destructor called on ControlPoint: " << name << std::endl;
}

void ControlPoint::Print()
{
	std::cout << "ObjectTemplate.create ControlPoint " << name << std::endl
		<< "ObjectTemplate.team " << team << std::endl
		<< "ObjectTemplate.controlPointID " << controlPointId << std::endl
		<< "ObjectTemplate.areaValueTeam1 " << areaValueTeam1 << std::endl
		<< "ObjectTemplate.areaValueTeam2 " << areaValueTeam2 << std::endl
		<< "ObjectTemplate.unableToChangeTeam " << unableToChangeTeam << std::endl
		<< "ObjectTemplate.supplyGroupId " << supplyGroupId << std::endl << std::endl;

	/*
	setNetworkableInfo
	onlyTakeableByTeam 
	hoistMinMax
	*/
}

int ControlPoint::SetLayer(std::string a)
{
	layer = a;

	return 0;
}

std::string ControlPoint::GetLayer()
{
	return layer;
}

int ControlPoint::SetName(std::string a)
{
	if (a.empty())
	{
		report("ControlPoint SetName failed");
		return 1;
	}

	name = a;

	return 0;
}

std::string ControlPoint::GetName()
{
	return name;
}

int ControlPoint::SetModifiedByUser(std::string a)
{
	modifiedByUser = a;

	return 0;
}

std::string ControlPoint::GetModifiedByUser()
{
	return modifiedByUser;
}

int ControlPoint::SetRadiusOffset(std::string a)
{
	radiusOffset = a;

	return 0;
}

std::string ControlPoint::GetRadiusOffset()
{
	return radiusOffset;
}

int ControlPoint::SetMinimapNameOffset(std::string a)
{
	if (a.find_first_of("/") == std::string::npos)
	{
		report("ControlPoint SetMinimapNameOffset failed");
		return 1;
	}

	MinimapNameOffset = a;
	
	return 0;
}

std::string ControlPoint::GetMinimapNameOffset()
{
	return MinimapNameOffset;
}

int ControlPoint::SetTeam(int a)
{
	if (a != 0 && a != 1 && a != 2)
	{
		report("ControlPoint SetTeam failed");
		return 1;
	}

	team = a;

	return 0;
}

int ControlPoint::GetTeam()
{
	return team;
}

int ControlPoint::SetControlPointID(int a)
{
	if (a < 0)
	{
		report("ControlPoint SetControlPointID failed");
		return 1;
	}

	controlPointId = a;

	return 0;
}

int ControlPoint::GetControlPointID()
{
	return controlPointId;
}

int ControlPoint::SetAreaValueTeam1(int a)
{
	if (a < 0)
	{
		report("ControlPoint SetAreaValueTeam1 failed");
		return 1;
	}

	areaValueTeam1 = a;

	return 0;
}

int ControlPoint::GetAreaValueTeam1()
{
	return areaValueTeam1;
}

int ControlPoint::SetAreaValueTeam2(int a)
{
	if (a < 0)
	{
		report("ControlPoint SetAreaValueTeam2 failed");
		return 1;
	}
	areaValueTeam2 = a;

	return 0;
}

int ControlPoint::GetAreaValueTeam2()
{
	return areaValueTeam2;
}

int ControlPoint::SetEnemyTicketLossWhenCaptured(int a)
{
	enemyTicketLossWhenCaptured = a;

	return 0;
}

int ControlPoint::GetEnemyTicketLossWhenCaptured()
{
	return enemyTicketLossWhenCaptured;
}

int ControlPoint::SetTimeToGetControl(int a)
{
	timeToGetControl = a;

	return 0;
}

int ControlPoint::GetTimeToGetControl()
{
	return timeToGetControl;
}

int ControlPoint::SetTimeToLoseControl(int a)
{
	timeToLoseControl = a;

	return 0;
}

int ControlPoint::GetTimeToLoseControl()
{
	return timeToLoseControl;
}

int ControlPoint::SetMinNrToTakeControl(int a)
{
	if (a < 0)
	{
		report("ControlPoint SetMinNrToTakeControl failed");
		return 1;
	}

	minNrToTakeControl = a;

	return 0;
}

int ControlPoint::GetMinNrToTakeControl()
{
	return minNrToTakeControl;
}

int ControlPoint::SetSupplyGroupId(int mysgid)
{
	if (mysgid < -1)
	{
		report("ControlPoint SetSupplyGroupId failed");
		return 1;
	}

	supplyGroupId = mysgid;

	return 0;
}

int ControlPoint::GetSupplyGroupId()
{
	return supplyGroupId;
}

int ControlPoint::SetOnlyTakeableByTeam(int a)
{
	if ((a != 0) && (a != 1) && (a != 2))
	{
		report("ControlPoint SetOnlyTakeableByTeam failed");
		return 1;
	}
	onlyTakeableByTeam = a;

	return 0;
}

int ControlPoint::GetOnlyTakeableByTeam()
{
	return onlyTakeableByTeam;
}

int ControlPoint::SetDisableIfEnemyInsideRadius(bool a)
{
	disableIfEnemyInsideRadius = a;

	return 0;
}

bool ControlPoint::GetDisableIfEnemyInsideRadius()
{
	return disableIfEnemyInsideRadius;
}

int ControlPoint::SetDisableWhenLosingControl(bool a)
{
	disableWhenLosingControl = a;

	return 0;
}

bool ControlPoint::GetDisableWhenLosingControl()
{
	return disableWhenLosingControl;
}

int ControlPoint::SetLoseControlWhenEnemyClose(bool a)
{
	loseControlWhenEnemyClose = a;

	return 0;
}

bool ControlPoint::GetLoseControlWhenEnemyClose()
{
	return loseControlWhenEnemyClose;
}

int ControlPoint::SetLoseControlWhenNotClose(bool a)
{
	loseControlWhenNotClose = a;

	return 0;
}

bool ControlPoint::GetLoseControlWhenNotClose()
{
	return loseControlWhenNotClose;
}

int ControlPoint::SetUnableToChangeTeam(bool a)
{
	unableToChangeTeam = a;

	return 0;
}

bool ControlPoint::GetUnableToChangeTeam()
{
	return unableToChangeTeam;
}

int ControlPoint::SetShowOnMinimap(bool a)
{
	showOnMinimap = a;

	return 0;
}

bool ControlPoint::GetShowOnMinimap()
{
	return showOnMinimap;
}

int ControlPoint::SetIsUnstrategicControlPoint(bool a)
{
	isUnstrategicControlPoint = a;

	return 0;
}

bool ControlPoint::GetIsUnstrategicControlPoint()
{
	return isUnstrategicControlPoint;
}

int ControlPoint::SetIsHemisphere(bool a)
{
	isHemisphere = a;

	return 0;
}

bool ControlPoint::GetIsHemisphere()
{
	return isHemisphere;
}

int ControlPoint::SetForSoldierOnly(bool a)
{
	ForSoldierOnly = a;

	return 0;
}

bool ControlPoint::GetForSoldierOnly()
{
	return ForSoldierOnly;
}

int ControlPoint::SetHasGreyCapturingState(bool a)
{
	hasGreyCapturingState = a;

	return 0;
}

bool ControlPoint::GetHasGreyCapturingState()
{
	return hasGreyCapturingState;
}

int ControlPoint::SetHoistFlag(bool a)
{
	hoistFlag = a;

	return 0;
}

bool ControlPoint::GetHoistFlag()
{
	return hoistFlag;
}
