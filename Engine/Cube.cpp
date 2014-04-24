#include "Cube.h"
#include <glew.h>
#include "Mesh.h"
#include "Vector.h"

#define VERTEXCOUNT 24
#define INDEXCOUNT 36

static const glm::vec3 __vertexPositions[VERTEXCOUNT] =
{	
	glm::vec3(-0.5, -0.5, -0.5), glm::vec3(-0.5, 0.5, -0.5), glm::vec3(0.5, 0.5, -0.5), glm::vec3(0.5, -0.5, -0.5), // front
	glm::vec3(0.5, -0.5,0.5), glm::vec3(0.5, 0.5,0.5), glm::vec3(-0.5, 0.5,0.5), glm::vec3(-0.5, -0.5,0.5), // back
	glm::vec3(-0.5, 0.5, -0.5), glm::vec3(-0.5, 0.5,0.5), glm::vec3(0.5, 0.5,0.5), glm::vec3(0.5, 0.5, -0.5), // top
	glm::vec3(-0.5, -0.5,0.5), glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0.5, -0.5, -0.5), glm::vec3(0.5, -0.5,0.5), // bottom
	glm::vec3(-0.5, -0.5,0.5), glm::vec3(-0.5, 0.5,0.5), glm::vec3(-0.5, 0.5, -0.5), glm::vec3(-0.5, -0.5, -0.5), // left
	glm::vec3(0.5, -0.5, -0.5), glm::vec3(0.5, 0.5, -0.5), glm::vec3(0.5, 0.5,0.5), glm::vec3(0.5, -0.5,0.5) // right
};

static const GLuint __vertexIndex[INDEXCOUNT] =
{
	0, 3, 2, 2, 1, 0, // front
	4, 7, 6, 6, 5, 4, // back
	8,11, 10, 10,9, 8, // top
	12,15,14, 14,13,12, // bottom
	16,19,18, 18,17,16, // left
	20,23,22, 22,21,20 // right
};

Mesh Cube::getMesh()
{
	if(sm_mesh != nullptr){
		return *sm_mesh;
	}

	Mesh* m = new Mesh();
	m->Indeces.resize(INDEXCOUNT);
	m->Verteces.resize(VERTEXCOUNT);
	for(unsigned int i = 0; i < 6; i++)
	{
		m->Verteces[i*4].Position = __vertexPositions[i * 4 + 0];
		m->Verteces[i*4].Uv = glm::vec2(1,1);

		m->Verteces[i*4 + 1].Position = __vertexPositions[i * 4 + 1];
		m->Verteces[i*4 + 1].Uv = glm::vec2(1,0);

		m->Verteces[i*4 + 2].Position = __vertexPositions[i * 4 + 2];
		m->Verteces[i*4 + 2].Uv = glm::vec2(0,0);

		m->Verteces[i*4 + 3].Position = __vertexPositions[i * 4 + 3];
		m->Verteces[i*4 + 3].Uv = glm::vec2(0,1);
	}

	for (int i =0; i< INDEXCOUNT; i++)
	{
		m->Indeces.push_back(__vertexIndex[i]);
	}

	sm_mesh = std::shared_ptr<Mesh>(m);
	return *sm_mesh;
}

std::shared_ptr<Mesh> Cube::sm_mesh;