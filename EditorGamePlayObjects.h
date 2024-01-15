#pragma once
#include "Common.h"
#include "GPOManager.h"
class GPOManager;

class EditorGamePlayObjects
{
	std::string* editorLayers;
	int numberOfEditorLayers;
	int editorOS, editorSP, editorCP, editorOBJ, editorCA;
	int CP, SP, OS, OBJ, CA;

	//These two are for CombatAreaManager
	bool use;
	std::string timeAllowedOutside;

	//ObjectSpawner* OSobj;
	//SpawnPoint* SPobj;
	//ControlPoint* CPobj;
	//Object* OBJobj;
	//CombatArea* CAobj;
	ObjectTemplate* OTobj;

	std::vector<ObjectSpawner*> objectSpawners;
	std::vector<SpawnPoint*> spawnPoints;
	std::vector<ControlPoint*> controlPoints;
	std::vector<Object*> objects;
	std::vector<CombatArea*> combatAreas;

	std::vector<GPOManager*> layerGamePlayObjects;

public:
	EditorGamePlayObjects(std::string* el = {}, int noel = 0, int eos = 0, int esp = 0, int ecp = 0,
		int eobj = 0, int eca = 0, bool u = 1, std::string tao = "20.000000");
	~EditorGamePlayObjects();

	void UpdateEditorGamePlayObjectsData(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0);
	int AddEditorLayers(std::string a); bool EditorLayerExists(std::string a);
	int GetEditorOS();
	int GetEditorSP();
	int GetEditorCP();
	int GetEditorOBJ();
	int GetEditorCA();
	int SetUse(bool a); bool GetUse();
	int SetTimeAllowedOutside(std::string a); std::string GetTimeAllowedOutside();

	void CompileDataForEditorGamePlayObjects();
	void addLocalLayer(GPOManager* gpo);
	void RunAnalysis(std::string line, std::string layer);


};

