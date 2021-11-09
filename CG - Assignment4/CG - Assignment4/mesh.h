#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <assimp/cimport.h> // scene importer
#include <assimp/scene.h> // collects data
#include <vector>

#include "maths_funcs.h"


#pragma region SimpleTypes

typedef struct ModelData {
	size_t mPointCount = 0;
	std::vector<vec3> mVertices;
	std::vector<vec3> mNormals;
	std::vector<vec2> mTextureCoords;
};
#pragma endregion SimpleTypes

class mesh
{
public:
	mesh(std::string newPath);

	


	std::string path;
	ModelData mesh_data;
	GLuint loc1, loc2, loc3;
	unsigned int vp;
	unsigned int vn;
	unsigned int vaoSelf;
	mesh* parent;


	int matrix_location;

	mat4 model;

	//VBO
	void getLoc(GLuint shaderProgramID);
	void genBuferPosition(unsigned int vp_vbo, unsigned int vn_vbo);
	void genBufferVertexArray(unsigned int vao);

	//Display
	void uniformVariables(GLuint shaderProgramID);
	void updateUniformAndDraw();



};

