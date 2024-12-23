#pragma once

#include "components/software_rendering_scene.h"
#include "core/gpu/frame_buffer.h"

#include "triangle_rasterizer.h"

namespace lab
{
    class Lab02 : public gfxc::SoftwareRenderScene
    {
     public:
        Lab02();
        ~Lab02();

        void Initialize() override;

     private:
        void Rasterize(
            const std::vector<VertexFormat> &vertices,
            const std::vector<unsigned int> &indices);
        glm::vec3 ComputePolarCoords3D(float aplha, float r, glm::vec2 p0);
    };
}   // namespace lab
