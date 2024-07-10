#include "raylib.h"
#include "raymath.h"

int main(void)
{
	InitWindow(800, 450, "raylib [core] example - basic window");

	Camera3D camera{};
	camera.position = Vector3{ 10.0f, 10.0f, 10.0f };
	camera.target = Vector3{ .0f, .0f, .0f };
	camera.up = Vector3{ .0f, 1.0f, .0f };

	camera.projection = CAMERA_PERSPECTIVE;
	camera.fovy = 60;

	Vector3 cubePosition = Vector3{ .0f, .0f, .0f };

	Mesh mesh = GenMeshCube(5, 5, 8);
	Material material = LoadMaterialDefault();
	material.maps->color = RED;
	Matrix transform = MatrixIdentity();


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(VIOLET);
		//DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		BeginMode3D(camera);

		//DrawCube(cubePosition, 5, 5, 8, RED);
		DrawMesh(mesh, material, transform);

		EndMode3D();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}