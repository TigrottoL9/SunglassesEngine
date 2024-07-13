#include <raylib.h>
#include <raymath.h>

#include <iostream>

#include "Components/TransformComponent.h"

#include "Mybehaviour.h"
#include "MyEntity.h"


int main(void)
{
    InitWindow(1200, 800, "raylib [core] example - basic window");
    Camera3D camera;
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f };
    camera.target = Vector3{ 0.0f, .0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };

    camera.projection = CAMERA_PERSPECTIVE;
    camera.fovy = 60;

    Vector3 cubePosition = Vector3{ 0.0f, 0.0f, 0.0f };

    MyEntity cubeMoveEntity;
    cubeMoveEntity.Initialize();

    while (!WindowShouldClose())
    {
        cubeMoveEntity.Update();
        //std::cout << GetFPS() << std::endl;

        BeginDrawing();

        ClearBackground(VIOLET);
        std::string fpsCounter = "FPS: " + GetFPS();
        
        DrawFPS(10, 10);

        BeginMode3D(camera);

        cubeMoveEntity.Draw();

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}