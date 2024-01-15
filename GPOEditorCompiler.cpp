#include "Common.h"
#include "GPOManager.h"
#include "EditorGamePlayObjects.h"

int main()
{
    std::filesystem::current_path("C:/Program Files (x86)/Project Reality/Project Reality BF2/mods/pr_repo/levels/adak");

    std::string cwd = std::filesystem::current_path().string(); std::replace(cwd.begin(), cwd.end(), '\\', '/');

    if (!(std::filesystem::exists(toLowerString("init.con"))))
    {
        std::cout << cwd << std::endl;
        report("Run the script in the main map folder (where init.con is located)");
        return 0;
    }

    //TODO do proper logging
    remove("C:/Users/Administrator/source/repos/GPOEC.con");
    remove("C:/Users/Administrator/source/repos/GPOEC_Err.con");

    EditorGamePlayObjects* EditorGPO = new EditorGamePlayObjects;
    int GPOid = 0;
    

    for (const auto& entry : std::filesystem::recursive_directory_iterator(cwd))
    {
        if (toLowerString(entry.path().stem().string()) != "gameplayobjects" || toLowerString(entry.path().parent_path().stem().string()) == "editor")
            continue;

        GPOid++;

        std::string currentLayer = extractLayer(entry.path().string());
        std::string currentMap = extractMap(entry.path().string());

        GPOManager* GPO = new GPOManager(entry.path().string().erase(entry.path().string().length() - 20), currentLayer);
        EditorGPO->addLocalLayer(GPO);
        
        std::ifstream gpo("gameplayobjects.con");
        std::string line;

        while (std::getline(gpo, line)) {
            EditorGPO->RunAnalysis(line, currentLayer);
        }

        gpo.close();
    }

    EditorGPO->CompileDataForEditorGamePlayObjects();

    std::cout << "Done" << std::endl;
    std::cin.get();
    return 0;
}