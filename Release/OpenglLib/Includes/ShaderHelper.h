//#pragma once
#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
// Include glew to get all the required OpenGL headers
class ShaderHelper
{
public:
	GLuint Program;
	// Constructor reads and builds the shader
	ShaderHelper(const GLchar* vertexPath, const GLchar* fragmentPath);
	// Use the program
	void Use();
};

#endif