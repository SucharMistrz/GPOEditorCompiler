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
#include "ControlPoint.h"
#include "CombatArea.h"
#include "Object.h"
#include "ObjectSpawner.h"
#include "SpawnPoint.h"
#include "ObjectTemplate.h"
#include "EditorGamePlayObjects.h"
//#include "GPOManager.h"

void log(std::string message, const std::source_location& location = std::source_location::current());
void report(std::string message, const std::source_location& location = std::source_location::current());
void note(std::string message, const std::source_location& location = std::source_location::current());
void meme(std::string message, const std::source_location& location = std::source_location::current());
std::string toLowerString(std::string);
std::string extract(std::string);
std::string extractClass(std::string);
std::string extractLayer(std::string);
std::string extractMap(std::string);