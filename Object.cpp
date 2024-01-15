#include "Object.h"

Object::Object(std::string n, std::string l, std::string pos, std::string rot, int cpid)
{
	name = n;
	layer = l;
	absolutePosition = pos;
	rotation = rot;
	controlPointId = cpid;
}
Object::~Object()
{
	//std::cout << std::endl << "Destructor called on Object: " << name << std::endl;
}
int Object::SetName(std::string a)
{
	if (a.empty())
		return 1;

	name = a;

	return 0;
}
std::string Object::GetName()
{
	return name;
}
int Object::SetControlPointId(int a)
{
	if (a < 0)
		return 1;

	controlPointId = a;

	return 0;
}
int Object::GetControlPointId()
{
	return controlPointId;
}
int Object::SetRotation(std::string a)
{
	if (a.empty())
		return 1;

	rotation = a;

	return 0;
}
std::string Object::GetRotation()
{
	return rotation;
}
int Object::SetAbsolutePosition(std::string a)
{
	if (a.empty())
		return 1;

	absolutePosition = a;

	return 0;
}
std::string Object::GetAbsolutePosition()
{
	return absolutePosition;
}
int Object::SetLayer(std::string a)
{
	layer = a;

	return 0;
}
std::string Object::GetLayer()
{
	return layer;
}
void Object::Print()
{
	std::cout << "Object.create " << name << std::endl
		<< "Object.absolutePosition " << absolutePosition << std::endl
		<< "Object.rotation " << rotation << std::endl
		<< "Object.setControlPointId " << controlPointId << std::endl
		<< "Object.layer " << layer << std::endl << std::endl;
}