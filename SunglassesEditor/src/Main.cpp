#include <raylib.h>
#include <raymath.h>

#include "Core/App.h"
#include "Core/SceneManager.h"

#include "Entities/CameraOrbit.h"
#include "Mybehaviour.h"
#include "MyEntity.h"

int main(void)
{

    App* sunglassesEditor = new App("Sunglasses", 1600, 1000);

    sunglassesEditor->Initialize();

    ScenePtr mainScene = CreateScene();
    mainScene->Add(std::make_shared<MyEntity>());    //TODO: questa cosa se la deve implementare la scena propria, tipo MyScene
    mainScene->Add(std::make_shared<CameraOrbit>());    //TODO: questa cosa se la deve implementare la scena propria, tipo MyScene
    SceneManager::GoToScene(mainScene);

    sunglassesEditor->Run();
    sunglassesEditor->Shutdown();

    delete sunglassesEditor;
    return 0;
}