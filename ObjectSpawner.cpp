#include "ObjectSpawner.h"
#include "Common.h"

ObjectSpawner::ObjectSpawner(std::string n, std::string l, std::string mbu,
	std::string ot1, std::string ot2, int minsd, int maxsd,
	int ttl, int d, int mnoos, int r, int t, bool sdat,
	bool ubr, bool ho, bool tov)
{
	name = n;
	layer = l;
	modifiedByUser = mbu;
	objectTemplate1 = ot1;
	objectTemplate2 = ot2;
	minSpawnDelay = minsd;
	maxSpawnDelay = maxsd;
	timeToLive = ttl;
	distance = d;
	maxNrOfObjectSpawned = mnoos;
	radius = r;
	team = t;
	spawnDelayAtStart = sdat;
	useButtonRadius = ubr;
	holdObject = ho;
	teamOnVehicle = tov;
}
ObjectSpawner::~ObjectSpawner()
{
	std::cout << std::endl << "Destructor called on ObjectSpawner: " << name << std::endl;
}

void ObjectSpawner::Print()
{
	std::cout << "ObjectTemplate.create ObjectSpawner " << name << std::endl
		<< "ObjectTemplate.setObjectTemplate 1 " << objectTemplate1 << std::endl
		<< "ObjectTemplate.setObjectTemplate 2 " << objectTemplate2 << std::endl
		//<< "ObjectTemplate.setControlPointId " << controlPointID << std::endl
		<< "ObjectTemplate.minSpawnDelay " << minSpawnDelay << std::endl
		<< "ObjectTemplate.maxSpawnDelay " << maxSpawnDelay << std::endl
		<< "ObjectTemplate.spawnDelayAtStart " << spawnDelayAtStart << std::endl
		<< "ObjectTemplate.TimeToLive " << timeToLive << std::endl
		<< "ObjectTemplate.maxNrOfObjectSpawned " << maxNrOfObjectSpawned << std::endl
		<< "ObjectTemplate.team " << team << std::endl
		<< "ObjectTemplate.teamOnVehicle " << teamOnVehicle << std::endl << std::endl;
}

int ObjectSpawner::SetName(std::string a)
{
	if (a.empty())
	{
		report("ObjectSpawner SetName failed");
		return 1;
	}

	name = a;

	return 0;
}

std::string ObjectSpawner::GetName()
{
	return name;
}

int ObjectSpawner::SetLayer(std::string a)
{
	layer = a;

	return 0;
}

std::string ObjectSpawner::GetLayer()
{
	return layer;
}

int ObjectSpawner::SetModifiedByUser(std::string a)
{
	if (a.empty())
	{
		report("ObjectSpawner SetModifiedByUser failed");
		return 1;
	}

	modifiedByUser = a;

	return 0;
}

std::string ObjectSpawner::GetModifiedByUser()
{
	return modifiedByUser;
}

int ObjectSpawner::SetObjectTemplate1(std::string a)
{
	if (a.empty())
	{
		report("ObjectSpawner SetObjectTemplate1 failed");
		return 1;
	}

	objectTemplate1 = a;

	return 0;
}

std::string ObjectSpawner::GetObjectTemplate1()
{
	return objectTemplate1;
}

int ObjectSpawner::SetObjectTemplate2(std::string a)
{
	if (a.empty())
	{
		report("ObjectSpawner SetObjectTemplate2 failed");
		return 1;
	}
	
	objectTemplate2 = a;

	return 0;
}

std::string ObjectSpawner::GetObjectTemplate2()
{
	return objectTemplate2;
}

int ObjectSpawner::SetMinSpawnDelay(int a)
{
	if (a < 0)
	{
		report("ObjectSpawner SetMinSpawnDelay failed");
		return 1;
	}

	minSpawnDelay = a;

	return 0;
}

int ObjectSpawner::GetMinSpawnDelay()
{
	return minSpawnDelay;
}

int ObjectSpawner::SetMaxSpawnDelay(int a)
{
	if (a < 0)
	{
		report("ObjectSpawner SetMaxSpawnDelay failed");
		return 1;
	}

	maxSpawnDelay = a;

	return 0;
}

int ObjectSpawner::GetMaxSpawnDelay()
{
	return maxSpawnDelay;
}

int ObjectSpawner::SetTimeToLive(int a)
{
	if (a < 0)
	{
		report("ObjectSpawner SetTimeToLive failed");
		return 1;
	}

	timeToLive = a;

	return 0;
}

int ObjectSpawner::GetTimeToLive()
{
	return timeToLive;
}

int ObjectSpawner::SetDistance(int a)
{
	if (a <= 0) //ObjectTemplate.Distance 0 crashes the game but DICE forgot to correct it in the editor
	{
		report("ObjectSpawner SetDistance failed");
		return 1;
	}

	distance = a;

	return 0;
}

int ObjectSpawner::GetDistance()
{
	return distance;
}

int ObjectSpawner::SetMaxNrOfObjectSpawned(int a)
{
	if (a < 0)
	{
		report("ObjectSpawner SetMaxNrOfObjectSpawned failed");
		return 1;
	}

	maxNrOfObjectSpawned = a;

	return 0;
}

int ObjectSpawner::GetMaxNrOfObjectSpawned()
{
	return maxNrOfObjectSpawned;
}

int ObjectSpawner::SetRadius(int a)
{
	if (a < 0)
	{
		report("ObjectSpawner SetRadius failed");
		return 1;
	}

	radius = a;

	return 0;
}

int ObjectSpawner::GetRadius()
{
	return radius;
}

int ObjectSpawner::SetTeam(int a)
{
	if (a != 0 && a != 1 && a != 2)
	{
		report("ObjectSpawner SetTeam failed");
		return 1;
	}

	team = a;

	return 0;
}

int ObjectSpawner::GetTeam()
{
	return team;
}

int ObjectSpawner::SetSpawnDelayAtStart(bool a)
{
	spawnDelayAtStart = a;

	return 0;
}

bool ObjectSpawner::GetSpawnDelayAtStart()
{
	return spawnDelayAtStart;
}

int ObjectSpawner::SetUseButtonRadius(bool a)
{
	useButtonRadius = a;

	return 0;
}

bool ObjectSpawner::GetUseButtonRadius()
{
	return useButtonRadius;
}

int ObjectSpawner::SetHoldObject(bool a)
{
	holdObject = a;

	return 0;
}

bool ObjectSpawner::GetHoldObject()
{
	return holdObject;
}

int ObjectSpawner::SetTeamOnVehicle(bool a)
{
	teamOnVehicle = a;

	return 0;
}

bool ObjectSpawner::GetTeamOnVehicle()
{
	return teamOnVehicle;
}
