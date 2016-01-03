#ifndef SHADER_H
#define SHADER_H

#include <GL\glew.h>
#include <string>
#include <fstream>
//#include "shaderCode.cpp"

//extern const char* vertexShaderCode;
//extern const char* fragmentShaderCode;


class Shader
{
public:
    Shader();
    virtual ~Shader();

    void Bind();
private:
    Shader(const Shader& other) {}
    void operator=(const Shader& other) {}
};

#endif // SHADER_H