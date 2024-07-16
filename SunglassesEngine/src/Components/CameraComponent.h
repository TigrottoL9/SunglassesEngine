#pragma once
#include <raylib.h>
#include <raymath.h>
#include <memory>

/*
typedef struct Camera3D {
    Vector3 position;       // Camera position
    Vector3 target;         // Camera target it looks-at
    Vector3 up;             // Camera up vector (rotation over its axis)
    float fovy;             // Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic
    int projection;         // Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC
} Camera3D;
*/

class CameraComponent
{
public:
	CameraComponent();

    void SetPosition(Vector3 position);
    void SetTarget(Vector3 target);
    void SetFov(float fov);
    void SetType(CameraProjection projectionType);

    Vector3& Position() const;
    Vector3& Target() const;
    Vector3 Forward() const;
    Vector3& Up() const;
    Vector3 Rigth() const;

    std::shared_ptr<Camera3D> GetCamera();

private:
	std::shared_ptr<Camera3D> m_camera;
    
    Vector3 m_right; //Sfortunatamente Camera3d non ha right
};

