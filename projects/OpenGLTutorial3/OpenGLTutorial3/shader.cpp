#include "shader.h"

const char* vertexShaderCode =
	"#version 430\r\n"
	""
	"in layout(location=0) vec3 position;"
	""
	"void main()"
	"{"
	"	gl_Position = vec4 position(position, 1.0);"
	"}";

const char* fragmentShaderCode =
	"#version 430\r\n"
	""
	"out vec4 daColor;"
	""
	"void main()"
	"{"
	"	daColor = vec4(0.0, 1.0, 0.0, 1.0);"
	"}";

Shader::Shader()
{
}


Shader::~Shader()
{
}


void Shader::Bind()
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    // define shader code
    const char* adapter[1];
    adapter[0] = vertexShaderCode;
    glShaderSource(vertexShaderID, 1, adapter, 0);
    adapter[0] = fragmentShaderCode;
    glShaderSource(fragmentShaderID, 1, adapter, 0);

    // compile shader id codes
    glCompileShader(vertexShaderID);
    glCompileShader(fragmentShaderID);

    // create and attach shaders to gl program
    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);

    // link the shaders to the program
    glLinkProgram(programID);
    glUseProgram(programID);
}