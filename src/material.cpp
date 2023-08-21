#include "material.hpp"

using namespace std;
using glm::vec3;

Material::Material()
{
}

// apply given color to both diffuse and ambient
Material::Material(vec3 color) : diffuseFactors(color), ambientFactors(color)
{
}

Material::~Material()
{   
}
