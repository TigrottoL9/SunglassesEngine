#include <raylib.h>
#include <raymath.h>

#include "Core/App.h"

#include "Mybehaviour.h"
#include "MyEntity.h"
#include "Core/Scene.h"

int main(void)
{

    App* sunglassesEditor = new App("Sunglasses", 1600, 1000);

    sunglassesEditor->Initialize();

    Scene* mainScene = new Scene();
    mainScene->Add(std::make_shared<MyEntity>());

    sunglassesEditor->SetScene(mainScene);

    sunglassesEditor->Run();
    sunglassesEditor->Shutdown();

    delete sunglassesEditor;
    return 0;
}