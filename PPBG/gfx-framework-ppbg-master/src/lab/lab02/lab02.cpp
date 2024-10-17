#include "lab/lab02/lab02.h"

#include <vector>

using namespace std;
using namespace lab;

Lab02::Lab02()
{
    window->SetSize(1280, 720);
}


Lab02::~Lab02()
{
}

void Lab02::Initialize()
{
    image->Init(1280, 720, 3 /* channels */);
    depthImage->Init(1280, 720);
    /*
    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(290, 90,  0.5), glm::vec3(1, 0, 0)),
            VertexFormat(glm::vec3(1099, 450,  0.5), glm::vec3(0, 1, 0)),
            VertexFormat(glm::vec3(650, 719,  0.5), glm::vec3(0, 0, 1)),

            VertexFormat(glm::vec3(200, 450,  0), glm::vec3(0, 1, 1)),
            VertexFormat(glm::vec3(830, 719,  1), glm::vec3(1, 1, 0)),
            VertexFormat(glm::vec3(1099, 0,  1), glm::vec3(1, 0, 1)) };

        vector<unsigned int> indices
        {
            0, 1, 2,    // indices for first triangle
            3, 4, 5,    // indices for second triangle
        };

        Rasterize(vertices, indices);
    }*/
    
    {
        int no_triangles = 1000;
        float R = (float) 360 / no_triangles;
        float r = 200;
        float alpha = 0.0f;
        glm::vec3 center = glm::vec3(1280/2, 720/2, 0.5f);

        vector<VertexFormat> vertices
        {
            VertexFormat(center, glm::vec3(0, 0, 1)), //center
        };
        for (int i = 0; i < no_triangles; i++, alpha += R)
        {
            vertices.push_back(VertexFormat(ComputePolarCoords3D(glm::radians(alpha), r, center), glm::vec3(1, 0, 0)));
        }

        
        vector<unsigned int> indices = {};
        for (int i = 0; i < no_triangles; i++)
        {
            indices.push_back(0);
            indices.push_back(i + 1);
            indices.push_back(i + 2);
        }
        indices.pop_back();
        indices.push_back(1);
        Rasterize(vertices, indices);
    }
       
}

void Lab02::Rasterize(
    const vector<VertexFormat> &vertices,
    const vector<unsigned int> &indices)
{
    for (int i = 0; i < indices.size(); i += 3) {
        auto v1 = vertices[indices[i]];
        auto v2 = vertices[indices[i+1]];
        auto v3 = vertices[indices[i+2]];

        TriangleRasterizer::Rasterize(
            v1, v2, v3, image, depthImage
        );
    }
}

glm::vec3 Lab02::ComputePolarCoords3D(float alpha, float r, glm::vec2 p0)
{
    float x = p0.x + r * glm::cos(alpha);
    float y = p0.y + r * glm::sin(alpha);
    return glm::vec3(x, y, 0.5f);
}