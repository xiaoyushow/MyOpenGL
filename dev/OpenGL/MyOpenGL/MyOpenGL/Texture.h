#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include<string>
#include"stb_image.h"
using namespace std;
class Texture2D
{
public:
	int width, height, nrChannels;
	unsigned int ID = 0;
	unsigned char* data = nullptr;
	int TextureNum = 0;

	Texture2D(const string& path, unsigned int saveType = GL_RGB, unsigned int imgType = GL_RGB, int level = 0, const int TextureNum = 0);
	~Texture2D();
	void use();



};

