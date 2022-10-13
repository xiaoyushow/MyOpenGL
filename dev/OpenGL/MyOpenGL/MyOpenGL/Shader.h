#pragma once

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;
using namespace glm;
class Shader
{
public:
	unsigned int ID;
	Shader(const GLchar* vs, const GLchar* fs);
	~Shader();

	void use();

	// uniform工具函数
	void setBool(const string& name, bool value) const;

	void setInt(const string& name, int value) const;

	void setFloat(const string& name, float value) const;

	void setMat4(const string& name, mat4 value) const;
private:
	void checkComplileError(unsigned int shader, string type);
	

};





