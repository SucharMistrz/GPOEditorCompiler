#include "SpawnPoint.h"
#include "Common.h"

SpawnPoint::SpawnPoint(std::string n, std::string l, std::string mbu,
	std::string spo, int spd, int g, int cpid,
	bool eos, bool aieos, bool sapt, bool ssp, bool ofh,
	bool ofai, bool asctv)
{
	name = n;
	layer = l;
	modifiedByUser = mbu;
	spawnPositionOffset = spo;
	spawnPreventionDelay = spd;
	group = g;
	controlPointId = cpid;
	enterOnSpawn = eos;
	aiEnterOnSpawn = aieos;
	spawnAsParaTroper = sapt;
	scatterSpawnPositions = ssp;
	onlyForHuman = ofh;
	onlyForAI = ofai;
	allowSpawnCloseToVehicle = asctv;
}
SpawnPoint::~SpawnPoint()
{
	//std::cout << std::endl << "Destructor called on SpawnPoint: " << name << std::endl;
}
void SpawnPoint::Print()
{
	std::cout << "ObjectTemplate.create SpawnPoint " << name << std::endl
		<< "ObjectTemplate.setControlPointId " << controlPointId << std::endl
		<< "ObjectTemplate.setGroup " << group << std::endl
		<< "ObjectTemplate.setEnterOnSpawn " << enterOnSpawn << std::endl
		<< "ObjectTemplate.setAIEnterOnSpawn " << aiEnterOnSpawn << std::endl
		<< "ObjectTemplate.setOnlyForHuman " << onlyForHuman << std::endl
		<< "ObjectTemplate.setOnlyForAI " << onlyForAI << std::endl
		<< "ObjectTemplate.setAllowSpawnCloseToVehicle " << allowSpawnCloseToVehicle << std::endl << std::endl;
}

int SpawnPoint::SetName(std::string a)
{
	if (a.empty())
	{
		report("SpawnPoint SetName failed");
		return 1;
	}

	name = a;

	return 0;
}

std::string SpawnPoint::GetName()
{
	return name;
}

int SpawnPoint::SetLayer(std::string a)
{
	layer = a;

	return 0;
}

std::string SpawnPoint::GetLayer()
{
	return layer;
}

int SpawnPoint::SetModifiedByUser(std::string a)
{
	modifiedByUser = a;

	return 0;
}

std::string SpawnPoint::GetModifiedByUser()
{
	return modifiedByUser;
}

int SpawnPoint::SetSpawnPositionOffset(std::string a)
{
	if (a.find_first_of("/") == std::string::npos)
	{
		report("SpawnPoint SetSpawnPositionOffset failed");
		return 1;
	}

	spawnPositionOffset = a;

	return 0;
}

std::string SpawnPoint::GetSpawnPositionOffset()
{
	return spawnPositionOffset;
}

int SpawnPoint::SetSpawnPreventionDelay(int a)
{
	spawnPreventionDelay = a;

	return 0;
}

int SpawnPoint::GetSpawnPreventionDelay()
{
	return spawnPreventionDelay;
}

int SpawnPoint::SetControlPointId(int a)
{
	if ((a < -1000) || (a > 1000))
	{
		report("SpawnPoint SetControlPointId failed");
		return 1;
	}

	controlPointId = a;

	return 0;
}

int SpawnPoint::GetControlPointId()
{
	return controlPointId;
}

int SpawnPoint::SetGroup(int a)
{
	if ((a < -1000) || (a > 1000))
	{
		report("SpawnPoint SetGroup failed");
		return 1;
	}

	group = a;

	return 0;
}

int SpawnPoint::GetGroup()
{
	return group;
}

int SpawnPoint::SetEnterOnSpawn(bool a)
{
	enterOnSpawn = a;

	return 0;
}

bool SpawnPoint::GetEnterOnSpawn()
{
	return enterOnSpawn;
}

int SpawnPoint::SetAIEnterOnSpawn(bool a)
{
	aiEnterOnSpawn = a;

	return 0;
}

bool SpawnPoint::GetAIEnterOnSpawn()
{
	return aiEnterOnSpawn;
}

int SpawnPoint::SetSpawnAsParaTroper(bool a)
{
	spawnAsParaTroper = a;

	return 0;
}

bool SpawnPoint::GetSpawnAsParaTroper()
{
	return spawnAsParaTroper;
}

int SpawnPoint::SetScatterSpawnPosition(bool a)
{
	scatterSpawnPositions = a;

	return 0;
}

bool SpawnPoint::GetScatterSpawnPosition()
{
	return scatterSpawnPositions;
}

int SpawnPoint::SetOnlyForHuman(bool a)
{
	onlyForHuman = a;

	return 0;
}

bool SpawnPoint::GetOnlyForHuman()
{
	return onlyForHuman;
}

int SpawnPoint::SetOnlyForAI(bool a)
{
	onlyForAI = a;

	return 0;
}

bool SpawnPoint::GetOnlyForAI()
{
	return onlyForAI;
}

int SpawnPoint::SetAllowSpawnCloseToVehicle(bool a)
{
	allowSpawnCloseToVehicle = a;

	return 0;
}

bool SpawnPoint::GetAllowSpawnCloseToVehicle()
{
	return allowSpawnCloseToVehicle;
}

int SpawnPoint::SetTeam(int a)
{
	return 0;
}

int SpawnPoint::GetTeam()
{
	return 0;
}