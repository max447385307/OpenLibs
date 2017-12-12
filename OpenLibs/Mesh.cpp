#include "Mesh.h"


Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
{
	this->vertices = vertices;
	this->indices = indices;
	this->textures = textures;

	this->setupMesh();
}

void Mesh::Draw(ShaderHelper shader)
{
	GLuint diffuseNr = 1;
	GLuint specularNr = 1;
	for (GLuint i = 0; i < this->textures.size(); i++)
	{
		//����һ��ָ����Texture���嵥Ԫ
		glActiveTexture(GL_TEXTURE0 + i); // Activate proper texture unit before binding
										  // Retrieve texture number (the N in diffuse_textureN)
		stringstream ss;
		string number;
		string name = this->textures[i].type;
		if (name == "texture_diffuse")
			ss << diffuseNr++; // Transfer GLuint to stream
		else if (name == "texture_specular")
			ss << specularNr++; // Transfer GLuint to stream
		number = ss.str();

		glUniform1f(glGetUniformLocation(shader.Program, ("material." + name + number).c_str()), i);

		//��id��ָ����texture��֮ǰ�����Texture unit��൱�ڰ�Texture���ȥ
		glBindTexture(GL_TEXTURE_2D, this->textures[i].id);
	}
	glActiveTexture(GL_TEXTURE0);//���Ｄ��0��ԭ���ǣ�

	glBindVertexArray(this->VAO);
	glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Mesh::setupMesh()
{
	glGenVertexArrays(1, &this->VAO);//������buffer��ʲô�����أ�
	glGenBuffers(1, &this->VBO);
	glGenBuffers(1, &this->EBO);

	glBindVertexArray(this->VAO);//bind array �� bind Buffer����ͻ�����ǿ�������һ�����
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);

	//���ǰ��󶨵�Array Buffer������䣬��vertices�����
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex),
		&this->vertices[0], GL_STATIC_DRAW);

	//��EBO,Ȼ�����EBO�����԰󶨶��EBO��VAO��VBOͬ��
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	//��֪opengl�Ե�ǰ�󶨵�EBO������䣬��ǰ�󶨵ļ��Ϸ���this->EBOָ����EBO
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(GLuint),
		&this->indices[0], GL_STATIC_DRAW);

	// Vertex Positions
	glEnableVertexAttribArray(0);//��ʾ����vertex shader��locationָ���ĵ�0���ڴ�λ��
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)0);//��֪��0���location����һ��float��sizeΪVertex����ַƫ��Ϊ��0��ʼ

    // Vertex Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, Normal));//������һ��������ƫ�ƣ���֪��Vertex�ṹ���е�Normal��Ա�ĵ�ַ��ʼƫ��

	// Vertex Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
		(GLvoid*)offsetof(Vertex, TexCoords));

	glBindVertexArray(0);
}
