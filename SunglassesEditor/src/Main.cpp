#include <raylib.h>
#include <raymath.h>

#include "Components/TransformComponent.h"
#include <iostream>

#include "Behaviour.h"


int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    TransformComponent t1;

    Camera3D camera;
    camera.position = Vector3{ 10.0f, 10.0f, 10.0f };
    camera.target = Vector3{ 0.0f, .0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };

    camera.projection = CAMERA_PERSPECTIVE;
    camera.fovy = 60;

    Vector3 cubePosition = Vector3{ 0.0f, 0.0f, 0.0f };

    Mesh mesh = GenMeshCube(5, 5, 8);
    Shader basicShader = LoadShader("./src/shaders/basic.vs", "./src/shaders/basic.fg");

    Material red = LoadMaterialDefault();
    red.shader = basicShader;
    red.maps[MATERIAL_MAP_DIFFUSE].color = RED;

    Material blue = LoadMaterialDefault();
    blue.shader = basicShader;
    blue.maps[MATERIAL_MAP_DIFFUSE].color = BLUE;

<<<<<<< HEAD
    Matrix transform1 = MatrixIdentity();
    Matrix transform2 = MatrixTranslate(-5, 0, 4);

    // Behaviour test
    Behaviour behaviour = Behaviour(0);
=======
>>>>>>> 717b7c6ea9d86b794ee774b986e1709b8ddeeb08

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(VIOLET);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        BeginMode3D(camera);

        //DrawCube(cubePosition, 5, 5, 8, RED);
        DrawMesh(mesh, red, t1.GetModelMatrix());

        EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}