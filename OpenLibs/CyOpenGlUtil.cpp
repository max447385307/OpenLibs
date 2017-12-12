#include "CyOpenGlUtil.h"


unsigned int CyOpenglUtil::LoadCubemap(std::vector<std::string> faces)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, nrChannel;

	for (unsigned int i = 0; i < faces.size(); i++) {
		unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannel, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height,0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else {
			std::cout << "Cubemap texture failed to load at path: " << faces[i].c_str() << std::endl;
			stbi_image_free(data);
		}
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}

void CyOpenglUtil::PrintMat4(glm::mat4 mat)
{
	std::cout << mat[0][0] << "|" << mat[0][1] << "|" << mat[0][2] << "|" << mat[0][3] << std::endl;
	std::cout << mat[1][0] << "|" << mat[1][1] << "|" << mat[1][2] << "|" << mat[1][3] << std::endl;
	std::cout << mat[2][0] << "|" << mat[2][1] << "|" << mat[2][2] << "|" << mat[2][3] << std::endl;
	std::cout << mat[3][0] << "|" << mat[3][1] << "|" << mat[3][2] << "|" << mat[3][3] << std::endl;
}

