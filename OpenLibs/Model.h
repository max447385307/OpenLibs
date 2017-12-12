#pragma once
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <iostream>
#include <map>
//#include <vector>
using namespace std;
//#include <GL/glew.h> // Contains all the necessery OpenGL includes
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <SOIL/SOIL.h>
//#include <assimp/Importer.hpp>
//#include <assimp/scene.h>
//#include <assimp/postprocess.h>

#include "Mesh.h"


class Model
{
public:
	/*  Functions   */
	Model(GLchar* path)
	{
		this->loadModel(path);
	}
	void Draw(ShaderHelper shader);
	vector<Mesh> meshes;
private:
	/*  Model Data  */
	//vector<Mesh> meshes;
	string directory;
	vector<Texture> textures_loaded;

	/*  Functions   */
	void loadModel(string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
		string typeName);

	
};

