#include "Common.h"

std::string version = "1.0.0.0";
extern int User;
std::string GlobalLogPath = "C:/Users/Administrator/source/repos/GPOEC.con";
std::string GlobalLogErrPath = "C:/Users/Administrator/source/repos/GPOEC_Err.con";

void report(std::string message, const std::source_location& location)
{
	log(message, location);

	std::stringstream output;

	output << "Debug Assertion Failed!" << std::endl << std::endl << std::endl
		<< "Version: " << version << "   Build date: " << __TIME__ << "   " << __DATE__ << std::endl << std::endl
		<< "File: " << location.file_name() << std::endl
		<< "Line: " << location.line() << std::endl << std::endl
		//<< "Call: " << location.function_name() << std::endl << std::endl
		<< location.function_name() << ": " << message << std::endl << std::endl;

	MessageBoxA(0, output.str().c_str(), "GamePlayObjects Editor Compiler", MB_ICONERROR | MB_OK);
}

void log(std::string message, const std::source_location& location)
{
	std::ofstream log;

	log.open(GlobalLogErrPath, std::ios::in | std::ios::app);

	log << "Debug Assertion Failed!" << std::endl
		<< "Version: " << version << "   Build date: " << __TIME__ << "   " << __DATE__ << std::endl
		<< "File: " << location.file_name() << std::endl
		<< "Line: " << location.line() << std::endl
		//<< "Call: " << location.function_name() << std::endl << std::endl
		<< location.function_name() << ": " << message << std::endl << std::endl;

	log.close();

	std::cout << "Logged error" << std::endl;
}

void note(std::string message, const std::source_location& location)
{
	std::ofstream note;

	note.open(GlobalLogPath, std::ios::in | std::ios::app);

	note << "Debug Assertion Failed!" << std::endl
		<< "Version: " << version << "   Build date: " << __TIME__ << "   " << __DATE__ << std::endl
		<< "File: " << location.file_name() << std::endl
		<< "Line: " << location.line() << std::endl
		//<< "Call: " << location.function_name() << std::endl << std::endl
		<< location.function_name() << ": " << message << std::endl << std::endl;

	note.close();
}

std::string toLowerString(std::string s)
{
	s.erase(0, s.find_first_not_of(" "));

	std::string lowercasestring;
	int i = 0;
	char c;
	while (s[i])
	{
		c = s[i];
		lowercasestring += tolower(c);
		i++;
	}
	return lowercasestring;
}

std::string extract(std::string s)
{
	s.erase(0, s.find_last_of(" ") + 1);

	return s;
}

std::string extractClass(std::string s)
{
	s.erase(s.find_last_of(" "), s.length());
	s.erase(0, (s.find_first_of(" ") + 1));

	return s;
}

std::string extractLayer(std::string s)
{
	s.erase(0, s.find("levels") + 7);// 7 = "levels/"
	std::string layer = s; layer.erase(layer.length() - 20).erase(0, layer.find_last_of("\\") + 1);
	std::string gamemode = s; gamemode.erase(0, gamemode.find("gpm_") + 4).erase(gamemode.find_first_of("\\"), gamemode.length() - gamemode.find_first_of("\\"));
	
	std::cout << " Gamemode: " << gamemode << " Layer: " << layer << std::endl;

	return gamemode + layer;
}

std::string extractMap(std::string s)
{
	s.erase(0, s.find("levels") + 7);// 7 = "levels/"
	std::string map = s; map.erase(map.find_first_of("\\"), map.length() - map.find_first_of("\\"));

	return map;
}