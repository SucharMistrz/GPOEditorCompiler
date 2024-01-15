#include "EditorGamePlayObjects.h"
#include "Common.h"
#include "GPOManager.h"

EditorGamePlayObjects::EditorGamePlayObjects(std::string* el, int noel, int eos, int esp, int ecp,
	int eobj, int eca, bool u, std::string tao)
{
	editorLayers = el;
	editorOS = eos;
	editorSP = esp;
	editorCP = ecp;
	editorOBJ = eobj;
	editorCA = eca;
	use = u;
	timeAllowedOutside = tao;

	//OSobj = nullptr;
	//SPobj = nullptr;
	//CPobj = nullptr;
	//OBJobj = nullptr;
	//CAobj = nullptr;
	//OTobj = nullptr;
}

EditorGamePlayObjects::~EditorGamePlayObjects()
{
	//delete[] OSobj;
	//delete[] SPobj;
	//delete[] CPobj;
	//delete[] OBJobj;
	//delete[] CAobj;
	//delete[] OTobj;
}

void EditorGamePlayObjects::UpdateEditorGamePlayObjectsData(int a, int b, int c, int d, int e)
{
	editorOS += a;
	editorSP += b;
	editorCP += c;
	editorOBJ += d;
	editorCA += e;
}

int EditorGamePlayObjects::AddEditorLayers(std::string a)
{
	if (EditorLayerExists(a))
	{
		std::cout << "Editor layer " << a << " already exists" << std::endl;
		return 0;
	}

	numberOfEditorLayers++;

	std::cout << "Adding new editor layer: " << a << std::endl;

	std::string* editorLayersNew = new std::string[numberOfEditorLayers];

	for (int i = 0; i < (numberOfEditorLayers - 1); i++)
	{
		editorLayersNew[i] = editorLayers[i];
	}

	editorLayersNew[numberOfEditorLayers - 1] = a;

	delete[] editorLayers;
	editorLayers = editorLayersNew;

	return 0;
}

bool EditorGamePlayObjects::EditorLayerExists(std::string a)
{
	for (int i = 0; i < (numberOfEditorLayers - 1); i++)
	{
		if (editorLayers[i] == a)
			return true;
	}

	return false;
}

int EditorGamePlayObjects::SetTimeAllowedOutside(std::string a)
{
	timeAllowedOutside = a;

	return 0;
}

std::string EditorGamePlayObjects::GetTimeAllowedOutside()
{
	return timeAllowedOutside;
}

int EditorGamePlayObjects::SetUse(bool a)
{
	use = a;

	return 0;
}

bool EditorGamePlayObjects::GetUse()
{
	return use;
}

int EditorGamePlayObjects::GetEditorOS()
{
	return editorOS;
}

int EditorGamePlayObjects::GetEditorSP()
{
	return editorSP;
}

int EditorGamePlayObjects::GetEditorOBJ()
{
	return editorOBJ;
}

int EditorGamePlayObjects::GetEditorCP()
{
	return editorCP;
}

int EditorGamePlayObjects::GetEditorCA()
{
	return editorCA;
}

void EditorGamePlayObjects::RunAnalysis(std::string line, std::string layer)
{
	std::cout << line << std::endl;

	//Commmon
	if (toLowerString(line).find("objecttemplate.create ", 0) == 0)
	{
		if (extractClass(toLowerString(toLowerString(line))) == "objectspawner")
		{
			ObjectSpawner* OSobj = new ObjectSpawner(extract(line), layer);
			objectSpawners.push_back(OSobj);
			OS++;
		}
		else if (extractClass(toLowerString(line)) == "spawnpoint")
		{
			SpawnPoint* SPobj = new SpawnPoint(extract(line), layer);
			spawnPoints.push_back(SPobj);
			SP++;

		}
		else if (extractClass(toLowerString(line)) == "controlpoint")
		{
			ControlPoint* CPobj = new ControlPoint(extract(line), layer);
			controlPoints.push_back(CPobj);
			CP++;
		}
		else
		{
			report("Attempted Create and SetName on an unknown class!");
			return;
		}
	}
	else if (toLowerString(line).find("objecttemplate.modifiedbyuser ", 0) == 0)
	{
		if (OS > 0 && SP == 0 && CP == 0)
		{
			OTobj = objectSpawners.back();
		}
		else if (OS > 0 && SP > 0 && CP == 0)
		{
			OTobj = spawnPoints.back();
		}
		else if (OS > 0 && SP > 0 && CP > 0)
		{
			OTobj = controlPoints.back();
		}
		else
		{
			report("Attempted SetModifiedByUser in an unknown GPO location: " + line);
			return;
		}
		OTobj->SetModifiedByUser(extract(line));
	}
	else if (toLowerString(line).find("objecttemplate.team ", 0) == 0)
	{
		if (CP == 0)
		{
			OTobj = objectSpawners.back();
		}
		else
		{
			OTobj = controlPoints.back();
		}
	
		OTobj->SetTeam(std::stoi(extract(line)));
	}
	
	
	//Type-specific
	else if (toLowerString(line).find("objecttemplate.teamonvehicle ", 0) == 0)
	{
		objectSpawners.back()->SetTeamOnVehicle(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.minspawndelay ", 0) == 0)
	{
		objectSpawners.back()->SetMinSpawnDelay(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.maxspawndelay ", 0) == 0)
	{
		objectSpawners.back()->SetMaxSpawnDelay(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.timetolive ", 0) == 0)
	{
		objectSpawners.back()->SetTimeToLive(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setobjecttemplate 1 ", 0) == 0)
	{
		objectSpawners.back()->SetObjectTemplate1(extract(line));
	}
	else if (toLowerString(line).find("objecttemplate.setobjecttemplate 2 ", 0) == 0)
	{
		objectSpawners.back()->SetObjectTemplate2(extract(line));
	}
	else if (toLowerString(line).find("objecttemplate.spawndelayatstart ", 0) == 0)
	{
		objectSpawners.back()->SetSpawnDelayAtStart(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.maxnrofobjectspawned ", 0) == 0)
	{
		objectSpawners.back()->SetMaxNrOfObjectSpawned(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.distance ", 0) == 0)
	{
		objectSpawners.back()->SetDistance(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.radius ", 0) == 0)
	{
		objectSpawners.back()->SetRadius(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.holdobject ", 0) == 0)
	{
		objectSpawners.back()->SetHoldObject(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.usebuttonradius ", 0) == 0)
	{
		objectSpawners.back()->SetUseButtonRadius(std::stoi(extract(line)));
	}
	
	
	
	else if (toLowerString(line).find("objecttemplate.setgroup ", 0) == 0)
	{
		spawnPoints.back()->SetGroup(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setcontrolpointid ", 0) == 0)
	{
		spawnPoints.back()->SetControlPointId(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setaienteronspawn ", 0) == 0)
	{
		spawnPoints.back()->SetAIEnterOnSpawn(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setonlyforhuman ", 0) == 0)
	{
		spawnPoints.back()->SetOnlyForHuman(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setonlyforai ", 0) == 0)
	{
		spawnPoints.back()->SetOnlyForAI(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setallowspawnclosetovehicle ", 0) == 0)
	{
		spawnPoints.back()->SetAllowSpawnCloseToVehicle(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setenteronspawn ", 0) == 0)
	{
		spawnPoints.back()->SetEnterOnSpawn(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.spawnpositionoffset ", 0) == 0)
	{
		spawnPoints.back()->SetSpawnPositionOffset(extract(line));
	}
	else if (toLowerString(line).find("objecttemplate.setspawnpreventiondelay ", 0) == 0)
	{
		spawnPoints.back()->SetSpawnPreventionDelay(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setspawnasparatroper ", 0) == 0)
	{
		spawnPoints.back()->SetSpawnAsParaTroper(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setscatterspawnposition ", 0) == 0)
	{
		spawnPoints.back()->SetScatterSpawnPosition(stoi(extract(line)));
	}
	
	
	
	else if (toLowerString(line).find("objecttemplate.controlpointid ", 0) == 0)
	{
		controlPoints.back()->SetControlPointID(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.unabletochangeteam ", 0) == 0)
	{
		controlPoints.back()->SetUnableToChangeTeam(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.supplygroupid ", 0) == 0)
	{
		controlPoints.back()->SetSupplyGroupId(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.areavalueteam1 ", 0) == 0)
	{
		controlPoints.back()->SetAreaValueTeam1(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.areavalueteam2 ", 0) == 0)
	{
		controlPoints.back()->SetAreaValueTeam2(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setradiusoffset ", 0) == 0)
	{
		controlPoints.back()->SetRadiusOffset(extract(line));
	}
	else if (toLowerString(line).find("objecttemplate.setminimapnameoffset ", 0) == 0)
	{
		controlPoints.back()->SetMinimapNameOffset(extract(line));
	}
	else if (toLowerString(line).find("objecttemplate.setenemyticketlosswhencaptured ", 0) == 0)
	{
		controlPoints.back()->SetEnemyTicketLossWhenCaptured(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.settimetogetcontrol ", 0) == 0)
	{
		controlPoints.back()->SetTimeToGetControl(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.settimetolosecontrol ", 0) == 0)
	{
		controlPoints.back()->SetTimeToLoseControl(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setminnrtotakecontrol ", 0) == 0)
	{
		controlPoints.back()->SetMinNrToTakeControl(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setonlytakeablebyteam ", 0) == 0)
	{
		controlPoints.back()->SetOnlyTakeableByTeam(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setdisableifenemyinsideradius ", 0) == 0)
	{
		controlPoints.back()->SetDisableIfEnemyInsideRadius(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setdisablewhenlosingcontrol ", 0) == 0)
	{
		controlPoints.back()->SetDisableWhenLosingControl(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setlosecontrolwhenenemyclose ", 0) == 0)
	{
		controlPoints.back()->SetLoseControlWhenEnemyClose(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setlosecontrolwhennotclose ", 0) == 0)
	{
		controlPoints.back()->SetLoseControlWhenNotClose(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setshowonminimap ", 0) == 0)
	{
		controlPoints.back()->SetShowOnMinimap(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setisunstrategiccontrolpoint ", 0) == 0)
	{
		controlPoints.back()->SetIsUnstrategicControlPoint(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.setishemisphere ", 0) == 0)
	{
		controlPoints.back()->SetIsHemisphere(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.forsoldieronly ", 0) == 0)
	{
		controlPoints.back()->SetForSoldierOnly(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.hasgreycapturingstate ", 0) == 0)
	{
		controlPoints.back()->SetHasGreyCapturingState(stoi(extract(line)));
	}
	else if (toLowerString(line).find("objecttemplate.hoistflag ", 0) == 0)
	{
		controlPoints.back()->SetHoistFlag(stoi(extract(line)));
	}
	
	
	
	else if (toLowerString(line).find("object.create ", 0) == 0)
	{
		Object* OBJobj = new Object(extract(line), layer);
		objects.push_back(OBJobj);
		OBJ++;
	}
	else if (toLowerString(line).find("object.absoluteposition ", 0) == 0)
	{
		objects.back()->SetAbsolutePosition(extract(line));
	}
	else if (toLowerString(line).find("object.rotation ", 0) == 0)
	{
		objects.back()->SetRotation(extract(line));
	}
	else if (toLowerString(line).find("object.setcontrolpointid ", 0) == 0)
	{
		objects.back()->SetControlPointId(std::stoi(extract(line)));
	}
	//Turns out in the files compiled for in-game usage, layer is always set to 1
	/*else if (toLowerString(line).find("object.layer ", 0) == 0)
	{
		objects.back()->SetLayer(std::stoi(extract(line)));
	}*/
	
	
	
	else if (toLowerString(line).find("combatarea.create ", 0) == 0)
	{
		CombatArea* CAobj = new CombatArea(extract(line), layer);
		combatAreas.push_back(CAobj);
		CA++;
	}
	else if (toLowerString(line).find("combatarea.team ", 0) == 0)
	{
		combatAreas.back()->SetTeam(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("combatarea.vehicles ", 0) == 0)
	{
		combatAreas.back()->SetVehicles(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("combatareamanager.use ", 0) == 0)
	{
		SetUse(std::stoi(extract(line)));
	}
	else if (toLowerString(line).find("combatareamanager.settimeallowedoutside ", 0) == 0)
	{
		SetTimeAllowedOutside(extract(line));
	}
	else if (toLowerString(line).find("combatarea.addareapoint ", 0) == 0)
	{
		combatAreas.back()->AddAreaPoint(extract(line));
	}
	else if (toLowerString(line).find("combatarea.layer ", 0) == 0)
	{
		//combatAreas.back()->SetLayer(extract(line));
	}
	else if (toLowerString(line).find("combatarea.inverted ", 0) == 0)
	{
		combatAreas.back()->SetInverted(std::stoi(extract(line)));
	}
}

void EditorGamePlayObjects::addLocalLayer(GPOManager* GPO)
{
	//add some checks later

	layerGamePlayObjects.push_back(GPO);
}

void EditorGamePlayObjects::CompileDataForEditorGamePlayObjects()
{

	//editorLayers = layerGamePlayObjects.size(); //that's the "basic" number of layers which has to be further expanded based on objects association data

	/*
	The game engine uses mostly object names to associate objects and their relation to each other (although not always, as with Object CPID and a few other parameters)
	1. ObjectTemplate and Object are associated by name and require each other to be created properly.
	2. If more than 1 ObjectTemplate exists with a given name in one GPO, it's an issue that must have been created due to editing GPO by hand (the editor would never do it, when loading such a GPO it overwrites all the parameters of the first object with parameters defined for the second objects; if some parameters are not defined for the second object, they stay the same as defined for the first object).
	3. If more than 1 ObjectTemplate exists with a given name in multiple GPO, then it is a part of some sort of "shared layer" among multuple GPOs.
	*/
	
	//Assign objects to correct shared (editor) layers

	for (size_t i = 0; i < objectSpawners.size(); ++i) {
		for (size_t j = 0; j < objectSpawners.size(); ++j)
		{
			if (i == j)
				continue;

			if (objectSpawners[i]->GetName() == objectSpawners[j]->GetName()
				&& objectSpawners[i]->GetLayer() != objectSpawners[j]->GetLayer())
			{
				std::string combinedLayer = objectSpawners[i]->GetLayer() + " " + objectSpawners[j]->GetLayer();

				log("Same object, different layers:\nObject 1: " + objectSpawners[i]->GetName() + " Layer: "
					+ objectSpawners[i]->GetLayer() + "\nObject 2: " + objectSpawners[j]->GetName() + " Layer: "
					+ objectSpawners[j]->GetLayer());

				AddEditorLayers(combinedLayer);

				objectSpawners[i]->SetLayer(combinedLayer);

				//get rid of the duplicate
				delete objectSpawners[j];
				objectSpawners.erase(objectSpawners.begin() + j);
				--j;
			}
		}
	}

	for (size_t i = 0; i < spawnPoints.size(); ++i) {
		for (size_t j = 0; j < spawnPoints.size(); ++j)
		{
			if (i == j)
				continue;

			if (spawnPoints[i]->GetName() == spawnPoints[j]->GetName()
				&& spawnPoints[i]->GetLayer() != spawnPoints[j]->GetLayer())
			{
				std::string combinedLayer = spawnPoints[i]->GetLayer() + " " + spawnPoints[j]->GetLayer();

				log("Same object, different layers:\nObject 1: " + spawnPoints[i]->GetName() + " Layer: "
					+ spawnPoints[i]->GetLayer() + "\nObject 2: " + spawnPoints[j]->GetName() + " Layer: "
					+ spawnPoints[j]->GetLayer());

				AddEditorLayers(combinedLayer);

				spawnPoints[i]->SetLayer(combinedLayer);

				//get rid of the duplicate
				delete spawnPoints[j];
				spawnPoints.erase(spawnPoints.begin() + j);
				--j;
			}
		}
	}

	for (size_t i = 0; i < controlPoints.size(); ++i) {
		for (size_t j = 0; j < controlPoints.size(); ++j)
		{
			if (i == j)
				continue;

			if (controlPoints[i]->GetName() == controlPoints[j]->GetName()
				&& controlPoints[i]->GetLayer() != controlPoints[j]->GetLayer())
			{
				std::string combinedLayer = controlPoints[i]->GetLayer() + " " + controlPoints[j]->GetLayer();

				log("Same object, different layers:\nObject 1: " + controlPoints[i]->GetName() + " Layer: "
					+ controlPoints[i]->GetLayer() + "\nObject 2: " + controlPoints[j]->GetName() + " Layer: "
					+ controlPoints[j]->GetLayer());

				AddEditorLayers(combinedLayer);

				controlPoints[i]->SetLayer(combinedLayer);

				//get rid of the duplicate
				delete controlPoints[j];
				controlPoints.erase(controlPoints.begin() + j);
				--j;
			}
		}
	}

	for (size_t i = 0; i < objects.size(); ++i) {
		for (size_t j = 0; j < objects.size(); ++j)
		{
			if (i == j)
				continue;

			if (objects[i]->GetName() == objects[j]->GetName()
				&& objects[i]->GetLayer() != objects[j]->GetLayer())
			{
				std::string combinedLayer = objects[i]->GetLayer() + " " + objects[j]->GetLayer();

				log("Same object, different layers:\nObject 1: " + objects[i]->GetName() + " Layer: "
					+ objects[i]->GetLayer() + "\nObject 2: " + objects[j]->GetName() + " Layer: "
					+ objects[j]->GetLayer());

				AddEditorLayers(combinedLayer);

				objects[i]->SetLayer(combinedLayer);

				//get rid of the duplicate
				delete objects[j];
				objects.erase(objects.begin() + j);
				--j;
			}
		}
	}

	for (size_t i = 0; i < combatAreas.size(); ++i) {
		for (size_t j = 0; j < combatAreas.size(); ++j)
		{
			if (i == j)
				continue;

			if (combatAreas[i]->GetName() == combatAreas[j]->GetName()
				&& combatAreas[i]->GetLayer() != combatAreas[j]->GetLayer())
			{
				std::string combinedLayer = combatAreas[i]->GetLayer() + " " + combatAreas[j]->GetLayer();

				log("Same object, different layers:\nObject 1: " + combatAreas[i]->GetName() + " Layer: "
					+ combatAreas[i]->GetLayer() + "\nObject 2: " + combatAreas[j]->GetName() + " Layer: "
					+ combatAreas[j]->GetLayer());

				AddEditorLayers(combinedLayer);

				combatAreas[i]->SetLayer(combinedLayer);

				//get rid of the duplicate
				delete combatAreas[j];
				combatAreas.erase(combatAreas.begin() + j);
				--j;
			}
		}
	}

	//The second task is to find duplicated objects
	//it should never happen but this is needed in case something goes wrong or GPO is fubar

	for (size_t i = 0; i < objectSpawners.size(); ++i) {
		for (size_t j = 0; j < objectSpawners.size(); ++j)
		{
			if (i == j)
				continue;

			if (objectSpawners[i]->GetName() == objectSpawners[j]->GetName()
				&& objectSpawners[i]->GetLayer() == objectSpawners[j]->GetLayer())
			{
				report("Duplicated ObjectSpawner: " + objectSpawners[i]->GetName() + " Layer: "
					+ objectSpawners[i]->GetLayer() + "\nObject 2: " + objectSpawners[j]->GetName() + " Layer: "
					+ objectSpawners[j]->GetLayer());
			}
		}
	}

	for (size_t i = 0; i < spawnPoints.size(); ++i) {
		for (size_t j = 0; j < spawnPoints.size(); ++j)
		{
			if (i == j)
				continue;

			if (spawnPoints[i]->GetName() == spawnPoints[j]->GetName()
				&& spawnPoints[i]->GetLayer() == spawnPoints[j]->GetLayer())
			{
				report("Duplicated ObjectSpawner: " + spawnPoints[i]->GetName() + " Layer: "
					+ spawnPoints[i]->GetLayer() + "\nObject 2: " + spawnPoints[j]->GetName() + " Layer: "
					+ spawnPoints[j]->GetLayer());
			}
		}
	}

	for (size_t i = 0; i < controlPoints.size(); ++i) {
		for (size_t j = 0; j < controlPoints.size(); ++j)
		{
			if (i == j)
				continue;

			if (controlPoints[i]->GetName() == controlPoints[j]->GetName()
				&& controlPoints[i]->GetLayer() == controlPoints[j]->GetLayer())
			{
				report("Duplicated ObjectSpawner: " + controlPoints[i]->GetName() + " Layer: "
					+ controlPoints[i]->GetLayer() + "\nObject 2: " + controlPoints[j]->GetName() + " Layer: "
					+ controlPoints[j]->GetLayer());
			}
		}
	}

	for (size_t i = 0; i < objects.size(); ++i) {
		for (size_t j = 0; j < objects.size(); ++j)
		{
			if (i == j)
				continue;

			if (objects[i]->GetName() == objects[j]->GetName()
				&& objects[i]->GetLayer() == objects[j]->GetLayer())
			{
				report("Duplicated ObjectSpawner: " + objects[i]->GetName() + " Layer: "
					+ objects[i]->GetLayer() + "\nObject 2: " + objects[j]->GetName() + " Layer: "
					+ objects[j]->GetLayer());
			}
		}
	}

	for (size_t i = 0; i < combatAreas.size(); ++i) {
		for (size_t j = 0; j < combatAreas.size(); ++j)
		{
			if (i == j)
				continue;

			if (combatAreas[i]->GetName() == combatAreas[j]->GetName()
				&& combatAreas[i]->GetLayer() == combatAreas[j]->GetLayer())
			{
				report("Duplicated ObjectSpawner: " + combatAreas[i]->GetName() + " Layer: "
					+ combatAreas[i]->GetLayer() + "\nObject 2: " + combatAreas[j]->GetName() + " Layer: "
					+ combatAreas[j]->GetLayer());
			}
		}
	}

	//Delete layers which are empty now
	
	for (int i = 0; i < numberOfEditorLayers; i++)
	{

	}

	//TODO
}