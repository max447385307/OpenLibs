#pragma once
#include <vector>
#include <string.h>
#include <GL/glew.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
//#include <stdio.h>
#include <iostream>
#include <CyOpenGlUtil/stb_image.h>

class CyOpenglUtil {

public:
	static unsigned int LoadCubemap(std::vector<std::string> faces);

	static void PrintMat4(glm::mat4 mat);
};

