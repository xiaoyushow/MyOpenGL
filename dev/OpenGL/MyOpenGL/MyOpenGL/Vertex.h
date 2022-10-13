#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
class Vertex
{
public:
	unsigned int VBO, VAO, EBO;
	Vertex(float vertices[], int verSize, unsigned int indices[], int indSize, int prop[], int propSize, int Sum);
	~Vertex();
	void setProperty(int pId, int pSize, int vSize, int pOffset);
	void use();
	void setFor(int prop[], int propSize, int Sum);
private:

};

