#pragma once
#include <raylib.h>
#include <raymath.h>
#include <memory>

#include "IComponent.h"
#include "TransformComponent.h"

/*
typedef struct Camera3D {
    Vector3 position;       // Camera position
    Vector3 target;         // Camera target it looks-at
    Vector3 up;             // Camera up vector (rotation over its axis)
    float fovy;             // Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic
    int projection;         // Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
} Camera3D;
*/

class CameraComponent: public TransformComponent
{
public:
	CameraComponent();

    void SetFov(float fov) const;
    void SetType(CameraProjection projectionType) const;

	[[nodiscard]] Vector3 Target() const;

    void UpdateCamera() const;

    std::shared_ptr<Camera3D> GetCamera();

private:
	std::shared_ptr<Camera3D> m_camera;
};

