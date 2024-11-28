#include "lab/lab02/triangle_rasterizer.h"

#include <vector>
#include <iostream>

using namespace std;
using namespace lab;

void TriangleRasterizer::Rasterize(
    const VertexFormat &v1,
    const VertexFormat &v2,
    const VertexFormat &v3,
    Image *image,
    DepthImage *depthImage)
{
    float xMin = min(v1.position.x, min(v2.position.x, v3.position.x));
    float yMin = min(v1.position.y, min(v2.position.y, v3.position.y));
    float xMax = max(v1.position.x, max(v2.position.x, v3.position.x));
    float yMax = max(v1.position.y, max(v2.position.y, v3.position.y));

    for (int row = yMin; row < yMax; row++) {
        for (int column = xMin; column < xMax; column++) {

            if (row < 0 || row >= image->GetHeight() ||
                column < 0 || column >= image->GetWidth()) {
                continue;
            }

            glm::vec2 p(column + 0.5f, row + 0.5f);

            if (CheckPointInsideTriangle(p, v1, v2, v3)) {

                float depth = ComputePixelDepth(p, v1, v2, v3);
                float pixelDepth = depthImage->Get(row, column).x;

                if (pixelDepth > depth) {
                    image->Set(row, column, ComputePixelColor (p, v1, v2, v3));
                    depthImage->Set(row, column, glm::vec3(depth, 0, 0));
                }
            }
        }
    }
}

float TriangleRasterizer::ComputeTriangleArea(
    const glm::vec2 &v1,
    const glm::vec2 &v2,
    const glm::vec2 &v3)
{
    // TODO(student): Ex. 1
    float a = glm::length(v1 - v2);
    float b = glm::length(v2 - v3);
    float c = glm::length(v3 - v1);
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;

}

//method 1 area
bool TriangleRasterizer::CheckPointInsideTriangle(
    const glm::vec2 &p,
    const VertexFormat &v1,
    const VertexFormat &v2,
    const VertexFormat &v3)
{
    const float EPSILON = 5;

    // TODO(student): Ex. 1
    float area1 = ComputeTriangleArea(v1.position, v2.position, p);
    float area2 = ComputeTriangleArea(v2.position, v3.position, p);
    float area3 = ComputeTriangleArea(v3.position, v1.position, p);
    float triangle_area = ComputeTriangleArea(v1.position, v2.position, v3.position);

    bool inside_triangle = abs(triangle_area - (area1 + area2 + area3)) < EPSILON;
    return inside_triangle;
}


float TriangleRasterizer::ComputeDet(
    const glm::vec2& v1,
    const glm::vec2& v2,
    const glm::vec2& v3)
{
    
    return v2.x * v3.y + v1.x * v2.y + v3.x * v1.y -
            v1.y * v2.x - v3.x * v2.y - v1.x* v3.y;

}
/*
// method 2: determinant
bool TriangleRasterizer::CheckPointInsideTriangle(
    const glm::vec2 &p,
    const VertexFormat &v1,
    const VertexFormat &v2,
    const VertexFormat &v3)
{
    // TODO(student): Ex. 1
    bool orientation1 = ComputeDet(v1.position, v2.position, p) < 0 ? true : false; // < 0 == left
    bool orientation2 = ComputeDet(v2.position, v3.position, p) < 0 ? true : false;
    bool orientation3 = ComputeDet(v3.position, v1.position, p) < 0 ? true : false;
    return (orientation1 && orientation2 && orientation3) || (!orientation1 && !orientation2 || !orientation3);
}

*/

glm::vec2 TriangleRasterizer::GetXY(glm::vec3 p)
{
    return glm::vec2(p.x, p.y);
}

// method 3 cross product
//bool TriangleRasterizer::CheckPointInsideTriangle(
//    const glm::vec2& p,
//    const VertexFormat& v1,
//    const VertexFormat& v2,
//    const VertexFormat& v3)
//{
//    const float EPSILON = 5.0f;
//
//    // TODO(student): Ex. 1
//    glm::vec2 v21 = GetXY(v2.position - v1.position);
//    glm::vec2 v32 = GetXY(v3.position - v2.position);
//    glm::vec2 v13 = GetXY(v1.position - v3.position);
//
//    bool orientation1 = (v21.x * p.y - v21.y * p.x) < 0 ? true : false; // < 0 == left
//    bool orientation2 = (v32.x * p.y - v21.y * p.x) < 0 ? true : false;
//    bool orientation3 = (v13.x * p.y - v21.y * p.x) < 0 ? true : false;
//    bool test = (orientation1 && orientation2 && orientation3) || (!orientation1 && !orientation2 || !orientation3);
//    /*if(test) {
//        std::cout << p << " " << v21 << " " << orientation1 << " " << orientation2 << " " << orientation3 << std::endl;
//    }*/
//    return test;
//}

glm::vec3 TriangleRasterizer::ComputePixelColor(
    const glm::vec2 &p,
    const VertexFormat &v1,
    const VertexFormat &v2,
    const VertexFormat &v3)
{
    // TODO(student): Ex. 2
    glm::vec3 b_coords = ComputeBarycentricCoords(p, v1, v2, v3);
    glm::vec3 color = b_coords.x * v3.color +
        b_coords.y * v1.color +
        b_coords.z * v2.color;

    return color;
}

float TriangleRasterizer::ComputePixelDepth(
    const glm::vec2 &p,
    const VertexFormat &v1,
    const VertexFormat &v2,
    const VertexFormat &v3)
{
    // TODO(student): Ex. 3
    glm::vec3 b_coords = ComputeBarycentricCoords(p, v1, v2, v3);
    float z_val = b_coords.x * v3.position.z +
        b_coords.y * v1.position.z +
        b_coords.z * v2.position.z;

    return z_val;
}

glm::vec3 TriangleRasterizer::ComputeBarycentricCoords(
    const glm::vec2& p,
    const VertexFormat& v1,
    const VertexFormat& v2,
    const VertexFormat& v3
)
{
    float area1 = ComputeTriangleArea(v1.position, v2.position, p);
    float area2 = ComputeTriangleArea(v2.position, v3.position, p);
    float area3 = ComputeTriangleArea(v3.position, v1.position, p);
    float triangle_area = ComputeTriangleArea(v1.position, v2.position, v3.position);

    float u = area1 / triangle_area;
    float v = area2 / triangle_area;
    float w = area3 / triangle_area;
    return glm::vec3(u, v, w);
}