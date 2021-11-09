#include "mesh.h"



mesh::mesh(std::string newPath)
{
	path = newPath;
}

void mesh::getLoc(GLuint shaderProgramID)
{
	loc1 = glGetAttribLocation(shaderProgramID, "vertex_position");
	loc2 = glGetAttribLocation(shaderProgramID, "vertex_normal");
	loc3 = glGetAttribLocation(shaderProgramID, "vertex_texture");

	std::cout << "loc1 = " << loc1 << ", loc2 = " << loc2 << std::endl;
}

void mesh::genBuferPosition(unsigned int vp_vbo, unsigned int vn_vbo)
{
	glGenBuffers(1, &vp_vbo);
	vp = vp_vbo;
	glBindBuffer(GL_ARRAY_BUFFER, vp);
	glBufferData(GL_ARRAY_BUFFER, mesh_data.mPointCount * sizeof(vec3), &mesh_data.mVertices[0], GL_STATIC_DRAW);
	
	glGenBuffers(1, &vn_vbo);
	vn = vn_vbo;
	glBindBuffer(GL_ARRAY_BUFFER, vn);
	glBufferData(GL_ARRAY_BUFFER, mesh_data.mPointCount * sizeof(vec3), &mesh_data.mNormals[0], GL_STATIC_DRAW);
}

void mesh::genBufferVertexArray(unsigned int vao)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	vaoSelf = vao;
	glEnableVertexAttribArray(loc1);
	glBindBuffer(GL_ARRAY_BUFFER, vp);
	glVertexAttribPointer(loc1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(loc2);
	glBindBuffer(GL_ARRAY_BUFFER, vn);
	glVertexAttribPointer(loc2, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

void mesh::uniformVariables(GLuint shaderProgramID)
{
	matrix_location = glGetUniformLocation(shaderProgramID, "model");
}

void mesh::updateUniformAndDraw() {

	glUniformMatrix4fv(matrix_location, 1, GL_FALSE, model.m);
}