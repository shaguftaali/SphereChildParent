#pragma once


#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include "../Includes/Maths/Matrix4.h"

class Shader
{
public:

	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	void use();

	void setBool(const std::string &name, bool value) const;

	void setInt(const std::string &name, int value) const;

	void setFloat(const std::string &name, float value) const;

	//void setMat4(const std::string &name, const Matrix4 &mat) const;

	void setVec3(const std::string &name, float x, float y, float z) const;
	void setMat4(const std::string &name, const Matrix4 &mat) const;

private:
	void checkCompilerErrors(unsigned int shader, std::string type);
};

