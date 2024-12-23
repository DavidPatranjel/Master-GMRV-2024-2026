#pragma once

#include <vector>

#include "components/simple_scene.h"

#include "lab/lab03/transform2D.h"

namespace lab
{
    class Lab05 : public gfxc::SimpleScene
    {
     public:
        Lab05();
        ~Lab05();

        void Init() override;

     private:
        void CreateMesh(const char *name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned int> &indices);
        void DrawObjects(gfxc::Camera *camera, const transform2D::ViewportSpace &viewport_space);

        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

        void RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix,
            const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix);

     protected:
        transform2D::ViewportSpace viewport_space;
        glm::vec3 color;
        GLenum cullFace;

    private:
        float  cube_1_posY = 0.0f;
        bool is_cube_1_up = true;
        float cube_2_angle = 0.0f;
        float  cube_3_scale= 0.5f;
        bool is_cube_3_scaling_up = true;
        glm::vec3 my_cube_movement = glm::vec3(0);
        const float ANIMATION_SPEED = 0.02f;

    };
}   // namespace lab
