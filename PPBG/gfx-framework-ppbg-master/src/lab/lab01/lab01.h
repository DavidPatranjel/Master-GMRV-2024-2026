#pragma once

#include "components/primitives_rendering_scene.h"

namespace lab
{
    class Lab01 : public gfxc::PrimitivesRenderingScene
    {
     public:
        Lab01();
        ~Lab01();

        void Initialize() override;

     protected:
         void Exercise1();
         void Exercise2();
         void Exercise3();
         void Exercise4();
         void Exercise5();
         void Exercise6();
         void Bonus();
     private:
        void PrintTextArea(const glm::vec2& p1, const glm::vec2& p2, const  glm::vec2& p3);
        float ComputeArea(const glm::vec2& p1, const glm::vec2& p2, const  glm::vec2& p3);
        bool IsInTriangle(const glm::vec2& p1, const glm::vec2& p2, const  glm::vec2& p3, const  glm::vec2& check_point);
    };
}   // namespace lab
