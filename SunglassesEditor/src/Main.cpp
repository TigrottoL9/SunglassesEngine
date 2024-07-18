#include <raylib.h>

#include "App.h"
#include <Core/SceneManager.h>

#include "Entities/CameraOrbit.h"
#include "Entities/MyEntity.h"
#include "Entities/Player.h"

int main(void)
{

    App* sunglassesEditor = new App("Sunglasses", 1600, 1000);

    sunglassesEditor->Initialize();

    ScenePtr mainScene = CreateScene();
    mainScene->Add(std::make_shared<MyEntity>());    //TODO: questa cosa se la deve implementare la scena propria, tipo MyScene
    mainScene->Add(std::make_shared<Player>());    //TODO: questa cosa se la deve implementare la scena propria, tipo MyScene
    SceneManager::GoToScene(mainScene);

    sunglassesEditor->Run();
    sunglassesEditor->Shutdown();

    delete sunglassesEditor;
    return 0;
}
