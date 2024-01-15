#include "CombatArea.h"
#include "Common.h"

CombatArea::CombatArea(std::string n, std::string l,
	std::string* aap, int t, int v,
	bool i, int noap)
{
	name = n;
	areaPoints = aap;
	team = t;
	vehicles = v;
	layer = l;
	inverted = i;
	numberOfAreaPoints = noap;
}

CombatArea::~CombatArea()
{
	std::cout << std::endl << "Destructor called on Object: " << name << std::endl;
}

void CombatArea::Print()
{
	std::cout << "CombatArea.create " << name << std::endl
		<< "CombatArea.team " << team << std::endl
		<< "CombatArea.vehicles " << vehicles << std::endl << std::endl;
}

int CombatArea::SetName(std::string a)
{
	if (a.empty())
	{
		report("CombatArea SetName failed");
		return 1;
	}
	name = a;

	return 0;
}

std::string CombatArea::GetName()
{
	return name;
}

int CombatArea::AddAreaPoint(std::string a)
{
	numberOfAreaPoints++;

	std::string* areaPointsNew = new std::string[numberOfAreaPoints];

	for (int i = 0; i < (numberOfAreaPoints - 1); i++)
	{
		areaPointsNew[i] = areaPoints[i];
	}

	areaPointsNew[numberOfAreaPoints - 1] = a;

	delete[] areaPoints;
	areaPoints = areaPointsNew;

	return 0;
}

int CombatArea::GetNumberOfAreaPoints()
{
	return numberOfAreaPoints;
}

int CombatArea::SetTeam(int a)
{
	if (a != 0 && a != 1 && a != 2)
	{
		report("CombatArea SetTeam failed");
		return 1;
	}

	team = a;

	return 0;
}

int CombatArea::GetTeam()
{
	return team;
}

int CombatArea::SetVehicles(int a)
{
	if (a != 0 && a != 1 && a != 2 && a != 3 && a != 4 && a != 5)
	{	
		report("CombatArea SetVehicles failed");
		return 1;
	}

	vehicles = a;

	return 0;
}

int CombatArea::GetVehicles()
{
	return vehicles;
}

int CombatArea::SetLayer(std::string a)
{
	layer = a;

	return 0;
}

std::string CombatArea::GetLayer()
{
	return layer;
}

int CombatArea::SetInverted(bool a)
{
	inverted = a;

	return 0;
}

bool CombatArea::GetInverted()
{
	return inverted;
}
